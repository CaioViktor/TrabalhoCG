#include "../lib/main.h"

Face::Face(){
	this->vertice1 = NULL;
	this->vertice2 = NULL;
	this->vertice3 = NULL;
	//this->material=NULL;
	this->material=new Material("Default", new Vector(1,0,0), new Vector(0,1,1),new Vector(1,1,1), 96, 1, 1);
}
Face::Face(Vertex *vert1, Vertex *vert2, Vertex *vert3){
	this->vertice1 = vert1;
	this->vertice2 = vert2;
	this->vertice3 = vert3;
	//this->material=NULL;
	this->material=new Material("Default", new Vector(1,0,0), new Vector(0,1,1),new Vector(1,1,1), 96, 1, 1);
}


void Face::setVertice1(Vertex *vertice){
	vertice1 = vertice;
}

void Face::setVertice2(Vertex *vertice){
	vertice2 = vertice;
}

void Face::setVertice3(Vertex *vertice){
	vertice3 = vertice;
}

Vertex* Face::getVertice1(){
	return this->vertice1;
}

Vertex* Face::getVertice2(){
	return vertice2;
}

Vertex* Face::getVertice3(){
	return vertice3;
}	


Vector* Face::calculateNormal(){
	Vector *u = new Vector(vertice2->getCoordinateXd() - vertice1->getCoordinateXd(), vertice2->getCoordinateYd() - vertice1->getCoordinateYd(), vertice2->getCoordinateZd() - vertice1->getCoordinateZd());
	Vector *v = new Vector(vertice3->getCoordinateXd() - vertice1->getCoordinateXd(), vertice3->getCoordinateYd() - vertice1->getCoordinateYd(), vertice3->getCoordinateZd() - vertice1->getCoordinateZd());
	return  u->cross3(v);
}

void Face::setMaterial(Material *m){
	this->material = m;
}
Material* Face::getMaterial(){
	return this->material;
}

Vector* Face::calculateCentroid(){
	double x,y,z;
	x = vertice1->getCoordinateXd() + vertice2->getCoordinateYd() + vertice3->getCoordinateZd();
	y = vertice1->getCoordinateXd() + vertice2->getCoordinateYd() + vertice3->getCoordinateZd();
	z = vertice1->getCoordinateXd() + vertice2->getCoordinateYd() + vertice3->getCoordinateZd();
	return new Vector(x,y,z);
} 


void Face::draw(unsigned int mode, Matrix* viewProjection, Illumination* illumination, Vector* camPosition, bool opengl){
	glBegin(mode);
	glEnable(GL_LIGHTING);
	
	if(opengl){
		glVertex3f(vertice1->getCoordinateXd(),vertice1->getCoordinateYd(),vertice1->getCoordinateZd());
		glVertex3f(vertice2->getCoordinateXd(),vertice2->getCoordinateYd(),vertice2->getCoordinateZd());
		glVertex3f(vertice3->getCoordinateXd(),vertice3->getCoordinateYd(),vertice3->getCoordinateZd());
	}


	else{
		//***********************************Calculo da Luz*****************************************//
		// cout<<"1"<<endl;
		if(illumination != NULL && camPosition !=NULL){
			glDisable (GL_LIGHTING);	//TODO: Verificar se da pra colocar isso em outro canto.
			glShadeModel(GL_FLAT);
			float Ir, Ig, Ib;

			Vector* centroid = this->calculateCentroid();

			Vector* normal = this->calculateNormal();
			normal->normalize3();


			Vector* lightPosition = illumination->getLightPosition();

			Vector* l = new Vector(lightPosition->getValue(0)-centroid->getValue(0),lightPosition->getValue(1)-centroid->getValue(1),lightPosition->getValue(2)-centroid->getValue(2));
			l->normalize3();



			Vector* v = new Vector(camPosition->getValue(0) - centroid->getValue(0),camPosition->getValue(1) - centroid->getValue(1),camPosition->getValue(2) - centroid->getValue(2));
			// cout<<"chogou aqui"<<endl;

			v->normalize3();
			double dot1 = l->dot3(normal);

			Vector* r = normal->multiplyDouble(2*dot1);
			r = (*r)-(*l);
			// r->normalize3();

			double dot2 = v->dot3(r);
			// cout<<"1"<<endl;
			Ir  = material->getKa()->getValue(0) * illumination->getLightAmbient()->getValue(0);
			Ir += material->getKd()->getValue(0) * illumination->getLightIntesity()->getValue(0)*fmax(0,dot1);
			Ir += material->getKs()->getValue(0) * illumination->getLightIntesity()->getValue(0)*fmax(0,(pow(dot2,(material->getNs()))));

			Ig  = material->getKa()->getValue(1) * illumination->getLightAmbient()->getValue(1);
			Ig += material->getKd()->getValue(1) * illumination->getLightIntesity()->getValue(1)*fmax(0,dot1);
			Ig += material->getKs()->getValue(1) * illumination->getLightIntesity()->getValue(1)*fmax(0,(pow(dot2,(material->getNs()))));

			Ib  = material->getKa()->getValue(2) * illumination->getLightAmbient()->getValue(2);
			Ib += material->getKd()->getValue(2) * illumination->getLightIntesity()->getValue(2)*fmax(0,dot1);
			Ib += material->getKs()->getValue(2) * illumination->getLightIntesity()->getValue(2)*fmax(0,(pow(dot2,(material->getNs()))));
			glColor3f ( Ir, Ig, Ib);
		}
		//delete normal;
		//delete lightPosition;
		//delete centroid;
		//delete l;
		//delete v;
		//delete r;
		//***********************Fim Calculo da Luz**************************************//



		Vector *vertex  = vertice1->toVector3()->multiplyMatrix(viewProjection);
		vertex->divisionW();
		//vertex->normalize3();
		glVertex3f(vertex->getValue(0),vertex->getValue(1),vertex->getValue(2));

		
		Vector *vertex2 = vertice2->toVector3()->multiplyMatrix(viewProjection);
		vertex2->divisionW();
		// vertex2->normalize3();
		glVertex3f(vertex2->getValue(0),vertex2->getValue(1),vertex2->getValue(2));


		Vector *vertex3 = vertice3->toVector3()->multiplyMatrix(viewProjection);
		vertex3->divisionW();
		// vertex3->normalize3();
		glVertex3f(vertex3->getValue(0),vertex3->getValue(1),vertex3->getValue(2));

		delete vertex;
		delete vertex2;
		delete vertex3;
	}
	
	glEnd();
}

// Autor: Caio Viktor. imprime as coordenadas dos vértices contidos na face
void Face::showVertexs(){
	if(this->vertice1 != NULL)
		this->vertice1->showVertex();
	if(this->vertice2 != NULL)
		this->vertice2->showVertex();
	if(this->vertice3 != NULL)
		this->vertice3->showVertex();
}
