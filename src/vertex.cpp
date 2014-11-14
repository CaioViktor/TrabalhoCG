/* vertex.cpp - Caio Viktor
*  Implemanta a estrutra de vértice utilizada na construção de figuras geométricas pelo OpenGl
*/
#include "../lib/main.h"
//constroi um vertice na origem do sistema de coodenadas
Vertex::Vertex(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 1;
	//cout << "Vertice construido com sucesso." << endl;
}
//constroi um vertice nos pontos especificados pelos parâmetros, apenas as três dimensões serão levadas em consideração a quarta coordenada será setada como 0.
Vertex::Vertex(double coordinateX,double coordinateY,double coordinateZ){
	this->x = coordinateX;
	this->y = coordinateY;
	this->z = coordinateZ;
	this->w = 1;
	//cout << "Vertice construido com sucesso." << endl;
}
//constroi um vertice nos pontos especificados pelos parâmetros. É necessário que seja passada a quata coordena
Vertex::Vertex(double coordinateX,double coordinateY,double coordinateZ,double coordinateW){
	this->x = coordinateX;
	this->y = coordinateY;
	this->z = coordinateZ;
	this->w = coordinateW;
	//cout << "Vertice construido com sucesso." << endl;
}
//destrutor da classe Vertex
// Vertex::~Vertex(){
// 	delete this;
// 	cout << "Vertice destruido com sucesso.\n";
// }


//Método de atualização da Coordenada X
void Vertex::setCoordinateX(double X){
	this->x = X;
}
//Método de atualização da Coordenada Y
void Vertex::setCoordinateY(double Y){
	this->y = Y;
}
//Método de atualização da Coordenada W
void Vertex::setCoordinateZ(double Z){
	this->z = Z;
}
//Método de atualização da Coordenada Z
void Vertex::setCoordinateW(double W){
	this->w = W;
}
//mostra as coordenadas do vértice
void Vertex::showVertex(){
	cout << "X: " << this->x << "    Y: " << this->y << "   Z: " << this->z << "   W: " << this->w << endl;
}


//Método de retorno da coordenada X no formato double
double Vertex::getCoordinateXd(){
	return this->x;
}
//Método de retorno da coordenada Y no formato double
double Vertex::getCoordinateYd(){
	return this->y;
}
//Método de retorno da coordenada Z no formato double
double Vertex::getCoordinateZd(){
	return this->z;
}
//Método de retorno da coordenada W no formato double
double Vertex::getCoordinateWd(){
	return this->w;
}


//Método de retorno da coordenada X no formato float
float Vertex::getCoordinateXf(){
	return (float) (this->x);
}
//Método de retorno da coordenada Y no formato float
float Vertex::getCoordinateYf(){
	return (float) (this->y);
}
//Método de retorno da coordenada Z no formato float
float Vertex::getCoordinateZf(){
	return (float) (this->z);
}
//Método de retorno da coordenada W no formato float
float Vertex::getCoordinateWf(){
	return (float) (this->w);
}



//retorna um objeto da classe Vector representando o vétice
Vector* Vertex::toVector(){
	Vector *newVector = new Vector();
	newVector->setValue(0,&this->x);
	newVector->setValue(1,&this->y);
	newVector->setValue(2,&this->z);
	if(this->w != 0)
		newVector->setValue(3,&this->w);
	else
		newVector->setValue(3,1);
	return newVector;
}
Vector* Vertex::toVector3(){
	Vector *newVector = new Vector();
	newVector->setValue(0,this->x);
	newVector->setValue(1,this->y);
	newVector->setValue(2,this->z);
	if(this->w != 0)
		newVector->setValue(3,this->w);
	else
		newVector->setValue(3,1);
	return newVector;
}