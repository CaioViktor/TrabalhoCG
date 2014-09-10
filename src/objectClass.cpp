#include "../lib/main.h"

//Construtor da classe Object. 
ObjectClass::ObjectClass(){
	
	char *name;
		
	//Lista de Vertices
	ListVertex *list = new ListVertex();
	
	//Lista de Faces

	//Centroide	
	
}

ObjectClass::ObjectClass( char *name, ListVertex *list ){
	this->name = name;
	this->list = list;	
}

void ObjectClass::setName( char *Name ){
	this->name = Name;
}

char* ObjectClass::getName(){
	return this->name;
}

void ObjectClass::setListVertex( ListVertex *list ){
	this->list = list;
}
	
ListVertex* ObjectClass::getListVertex(){
	return this->list;
}
