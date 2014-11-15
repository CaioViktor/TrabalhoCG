#include "../lib/main.h"

Face::Face(){
	this->vertice1 = NULL;
	this->vertice2 = NULL;
	this->vertice3 = NULL;
}
Face::Face(Vertex *vert1, Vertex *vert2, Vertex *vert3){
	this->vertice1 = vert1;
	this->vertice2 = vert2;
	this->vertice3 = vert3;
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

Vector* Face::getNormal(){
	return normal;
}

void Face::calculateNormal(){
	Vector* vector1 = vertice1->toVector3();
	Vector* vector2 = vertice2->toVector3();
	Vector* vector3 = vertice3->toVector3();
	this->normal =  ((*vector2)-(*vector1))->cross3((*vector3)-(*vector1));
	delete vector1;
	delete vector2;
	delete vector3;
}

void Face::draw(unsigned int mode,Matrix* viewProjection,bool opengl){
	glBegin(mode);
	if(opengl){
		glVertex3f(vertice1->getCoordinateXd(),vertice1->getCoordinateYd(),vertice1->getCoordinateZd());
		glVertex3f(vertice2->getCoordinateXd(),vertice2->getCoordinateYd(),vertice2->getCoordinateZd());
		glVertex3f(vertice3->getCoordinateXd(),vertice3->getCoordinateYd(),vertice3->getCoordinateZd());
	}

	else{

		Vector *vertex  = vertice1->toVector3()->multiplyMatrix(viewProjection);
		vertex->divisionW();
		glVertex3f(vertex->getValue(0),vertex->getValue(1),vertex->getValue(2));

		
		Vector *vertex2 = vertice2->toVector3()->multiplyMatrix(viewProjection);
		vertex2->divisionW();
		glVertex3f(vertex2->getValue(0),vertex2->getValue(1),vertex2->getValue(2));


		Vector *vertex3 = vertice3->toVector3()->multiplyMatrix(viewProjection);
		vertex3->divisionW();
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
