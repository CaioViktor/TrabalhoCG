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

Vertex* Face::getVertice1(){
	return this->vertice1;
}


void Face::setVertice2(Vertex *vertice){
	vertice2 = vertice;
}

Vertex* Face::getVertice2(){
	return vertice2;
}


void Face::setVertice3(Vertex *vertice){
	vertice3 = vertice;
}

Vertex* Face::getVertice3(){
	return vertice3;
}	

Vector* Face::getNormal(){
	return normal;
}

void Face::desenhar(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	glVertex3f(vertice1->getCoordinateXd(),vertice1->getCoordinateYd(),vertice1->getCoordinateZd());
	glVertex3f(vertice2->getCoordinateXd(),vertice2->getCoordinateYd(),vertice2->getCoordinateZd());
	glVertex3f(vertice3->getCoordinateXd(),vertice3->getCoordinateZd(),vertice3->getCoordinateZd());

	glEnd();

	glFlush();
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
