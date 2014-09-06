#include "../lib/main.h"

//Construtor da classe Object. 
ObjectClass::ObjectClass(){
	
	string name;
		
	//Lista de Vertices
	ListVertex *list = new ListVertex();
	
	//Lista de Faces

	//Centroide	
	
}

ObjectClass::ObjectClass( string name, ListVertex *list ){
	this->name = name;
	this->list = list;	
}

void ObjectClass::setName( string Name ){
	this->name = Name;
}

string ObjectClass::getName(){
	return this->name;
}

void ObjectClass::setListVertex( ListVertex *list ){
	this->list = list;
}
	
ListVertex* ObjectClass::getListVertex(){
	return this->list;
}
