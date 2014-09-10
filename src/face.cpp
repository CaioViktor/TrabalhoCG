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


/*void Face::setNormal(Vector *vnormal){
	this->normal = vnormal;
}

Vector Face::getNormal(){
	return normal;
}*/
void Face::desenhar(){
	
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
