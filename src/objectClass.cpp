#include "../lib/main.h"

//Construtor da classe Object. 
ObjectClass::ObjectClass(){
	//Nome do objeto
    this->name = "";
	//Lista de Vertices
	this->list_vertex = NULL;
	//Numero de Vertices
	this->number_vertex = 0;
	//Lista de Faces
    this->list_face = NULL;
    //Numero de Faces
    this->number_face = 0;
    
    //Cores
    this->R = 0;
    this->G = 0.7;
    this->B = 0;
    
	//Centroide	
	
}

//Método para desenhar objeto
void ObjectClass::drawObject( unsigned int modeExibitionValue ){
    glColor3f(this->R,this->G,this->B);   
    if(modeExibitionValue == GL_POLYGON)
        this->list_face->drawSolid();
    else
        this->list_face->drawWired();
}

//Método para aplicar transformação no objeto
void ObjectClass::applyTransformation( Matrix *transformationMatrix ){ 
     this->list_vertex->transformation( transformationMatrix );
}
     

//SETs

//Configura o nome do objeto
void ObjectClass::setName( std::string Name ){
	this->name = Name;
}

//Configura a lista de vértice
void ObjectClass::setListVertex( ListVertex *list_vertex ){
	this->list_vertex = list_vertex;
	this->number_vertex = list_vertex->numberVertex();
}

//Configura a lista de faces
void ObjectClass::setListFace( ListFace *list_face ){
     this->list_face = list_face;
     this->number_face = list_face->numberFaces();
}

//Configura a cor R do objeto
void ObjectClass::setColorR( float R ){
     this->R = R;
}

//Configura a cor G do objeto
void ObjectClass::setColorG( float G ){
     this->G = G;
}

//Configura a cor B do objeto
void ObjectClass::setColorB( float B ){
     this->B = B;
}


//GETs

//Acessa o nome do objeto
std::string ObjectClass::getName(){
	return this->name;
}

//Acessa a lista de vértices do objeto	
ListVertex* ObjectClass::getListVertex(){
	return this->list_vertex;
}

//Acessa a lista de faces do objeto
ListFace* ObjectClass::getListFace(){
    return this->list_face;
}

//Acessa a cor R do objeto
float ObjectClass::getCollorR(){
      return this->R;
}

//Acessa a cor G do objeto
float ObjectClass::getCollorG(){
      return this->G;
}

//Acessa a cor B do objeto
float ObjectClass::getCollorB(){
      return this->B;
}
      
//Acessa o n�mero de v�rtices do Objeto
int ObjectClass::getNumberVertex(){
    return this->number_vertex;
}

//Acessa o n�mero de faces do Objeto
int ObjectClass::getNumberFace(){
    return this->number_face;
}
