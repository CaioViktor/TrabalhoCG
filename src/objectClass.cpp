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
    this->centroid = new Vector();
    for(int c = 0;c<3;c++)
        this->centroid->setValue(c,(double)0);
    this->centroid->setValue(3,(double)1);
	
}

//MÃ©todo para desenhar objeto
void ObjectClass::drawObject( unsigned int modeExibitionValue, Matrix* viewProjection, Illumination *illumination, Vector* camPosition){
    bool opengl = (*viewProjection) == (*Matrix::getIdentity());
      
    if(modeExibitionValue == GL_POLYGON)
        this->list_face->drawSolid(viewProjection, illumination, camPosition, opengl);
    else{
        glColor3f(this->R,this->G,this->B);
        this->list_face->drawWired(viewProjection, opengl);
    }
}

//MÃ©todo para aplicar transformaÃ§Ã£o no objeto
void ObjectClass::applyTransformation( Matrix *transformationMatrix ){ 
     this->list_vertex->transformation( transformationMatrix );
     this->updateCentroide();
}
     

//SETs

//Configura o nome do objeto
void ObjectClass::setName( std::string Name ){
	this->name = Name;
  if(this->name == "Paredes"){
    this->R = 0.5;
    this->G = 0.5;
    this->B = 0.5;
  }
}

//Configura a lista de vÃ©rtice
void ObjectClass::setListVertex( ListVertex *list_vertex ){
	this->list_vertex = list_vertex;
	this->number_vertex = list_vertex->numberVertex();
}

//Configura a lista de faces
void ObjectClass::setListFace( ListFace *list_face ){
     this->list_face = list_face;
     this->number_face = list_face->numberFaces();
     this->updateCentroide();
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

//Acessa a lista de vÃ©rtices do objeto	
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
      
//Acessa o número de vértices do Objeto
int ObjectClass::getNumberVertex(){
    return this->number_vertex;
}

//Acessa o número de faces do Objeto
int ObjectClass::getNumberFace(){
    return this->number_face;
}

//Autor: Caio Viktor
//Método que atualiza a centroide do objeto. a coordenada homogênia está sendo setada com 1
void ObjectClass::updateCentroide(){
    for(int c = 0;c < 4;c++)
        this->centroid->setValue(c,(double)0);
    Vertex *vertex;
    for(int c = 0;c < this->number_vertex;c++){
        vertex = this->list_vertex->getVertex(c);
        this->centroid->setValue(0,this->centroid->getValue(0) + vertex->getCoordinateXd());
        this->centroid->setValue(1,this->centroid->getValue(1) + vertex->getCoordinateYd());
        this->centroid->setValue(2,this->centroid->getValue(2) + vertex->getCoordinateZd());
        //this->centroid->setValue(3,this->centroid->getValue(3) + vertex->getCoordinateWd());
    }
    this->centroid->setValue(0,this->centroid->getValue(0)/this->number_vertex);
    this->centroid->setValue(1,this->centroid->getValue(1)/this->number_vertex);
    this->centroid->setValue(2,this->centroid->getValue(2)/this->number_vertex);
    //this->centroid->setValue(3,this->centroid->getValue(3)/this->number_vertex);
    this->centroid->setValue(3,(double)1);
}
Vector* ObjectClass::getCentroid(){
    return this->centroid;
}