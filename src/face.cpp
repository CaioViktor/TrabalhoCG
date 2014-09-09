#include "../lib/main.h"

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
