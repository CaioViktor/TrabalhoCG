#include "../lib/main.h"

//Construtor da classe Object. 
ObjectClass::ObjectClass(){
	
	this->name = "";
		
	//Lista de Vertices
	this->list = NULL;
	
	//Lista de Faces

	//Centroide	
	
}

ObjectClass::ObjectClass( std::string name, ListVertex *list ){
	this->name = name;
	this->list = list;	
}

void ObjectClass::setName( std::string Name ){
	this->name = Name;
}

std::string ObjectClass::getName(){
	return this->name;
}

void ObjectClass::setListVertex( ListVertex *list ){
	this->list = list;
}
	
ListVertex* ObjectClass::getListVertex(){
	return this->list;
}
