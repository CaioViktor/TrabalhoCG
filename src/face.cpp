#include "../lib/main.h"

Face::Face(){
	this->vertice1 = NULL;
	this->vertice2 = NULL;
	this->vertice3 = NULL;
	this->material=NULL;
}
Face::Face(Vertex *vert1, Vertex *vert2, Vertex *vert3){
	this->vertice1 = vert1;
	this->vertice2 = vert2;
	this->vertice3 = vert3;
	this->material=NULL;
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
	Vector* vector1 = vertice1->toVector3();
	Vector* vector2 = vertice2->toVector3();
	Vector* vector3 = vertice3->toVector3();
	Vector* normal =  ((*vector2)-(*vector1))->cross3((*vector3)-(*vector1));
	delete vector1;
	delete vector2;
	delete vector3;
	return normal;
}

void Face::setMaterial(Material *m){
	this->material=m;
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


void Face::draw(unsigned int mode, Matrix* viewProjection, Illumination* illumination, bool opengl){
	glBegin(mode);
	if(opengl){
		glVertex3f(vertice1->getCoordinateXd(),vertice1->getCoordinateYd(),vertice1->getCoordinateZd());
		glVertex3f(vertice2->getCoordinateXd(),vertice2->getCoordinateYd(),vertice2->getCoordinateZd());
		glVertex3f(vertice3->getCoordinateXd(),vertice3->getCoordinateYd(),vertice3->getCoordinateZd());
	}


	else{
		//Calculo da Luz
		Vector* normal = this->calculateNormal()->multiplyMatrix(viewProjection);
		Vector* centroid = this->calculateCentroid()->multiplyMatrix(viewProjection);
		Vector* lightPosition = illumination->getLightPosition()->multiplyMatrix(viewProjection);
		Vector* l = (*centroid) - (*lightPosition);

		
		//Vector* v = ()

		Vector *vertex  = vertice1->toVector3()->multiplyMatrix(viewProjection);
		vertex->divisionW();
		// vertex->normalize3();
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
