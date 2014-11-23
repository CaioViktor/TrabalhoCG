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
	this->normal = new Vector(0,0,0);
	//cout << "Vertice construido com sucesso." << endl;
}
//constroi um vertice nos pontos especificados pelos parâmetros, apenas as três dimensões serão levadas em consideração a quarta coordenada será setada como 0.
Vertex::Vertex(double coordinateX,double coordinateY,double coordinateZ){
	this->x = coordinateX;
	this->y = coordinateY;
	this->z = coordinateZ;
	this->w = 1;
	this->normal = new Vector(0,0,0);
	//cout << "Vertice construido com sucesso." << endl;
}
//constroi um vertice nos pontos especificados pelos parâmetros. É necessário que seja passada a quata coordena
Vertex::Vertex(double coordinateX,double coordinateY,double coordinateZ,double coordinateW){
	this->x = coordinateX;
	this->y = coordinateY;
	this->z = coordinateZ;
	this->w = coordinateW;
	this->normal = new Vector(0,0,0);
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

void Vertex::resetNormal(){
	delete normal;
	normal = new Vector(0,0,0);
}
void Vertex::sumNormal(Vector *n){
	normal->setValue(0, normal->getValue(0)+ n->getValue(0));
	normal->setValue(1, normal->getValue(1)+ n->getValue(1));
	normal->setValue(2, normal->getValue(2)+ n->getValue(2));
}
Vector* Vertex::calculateColors(Illumination *illumination, Vector* camPosition, Material *material){
	float Ir, Ig, Ib;
	double dot1;
	double dot2;

	Vector *centroid;
	Vector *lightPosition;
	Vector *v;
	Vector *l;
	Vector *r;


	centroid = new Vector(this->x,this->y,this->z);

	normal->normalize3();
	

	// normal->divisionZ();

	lightPosition = illumination->getLightPosition();

	l = new Vector(
			lightPosition->getValue(0) - centroid->getValue(0),
			lightPosition->getValue(1) - centroid->getValue(1),
			lightPosition->getValue(2) - centroid->getValue(2));

	l->normalize3();


	v = new Vector(
		camPosition->getValue(0) - centroid->getValue(0),
		camPosition->getValue(1) - centroid->getValue(1),
		camPosition->getValue(2) - centroid->getValue(2));
	v->normalize3();

	dot1 = l->dot3(normal);

	r = normal->multiplyDouble(2*dot1);
	r = (*r)-(*l);
	// r->normalize3();

	dot2 = v->dot3(r);
	Ir  = material->getKa()->getValue(0) * illumination->getLightAmbient()->getValue(0);
	Ir += material->getKd()->getValue(0) * illumination->getLightIntesity()->getValue(0) * fmax(0,dot1);
	Ir += material->getKs()->getValue(0) * illumination->getLightIntesity()->getValue(0) * fmax(0,(pow(dot2,(material->getNs()))));

	Ig  = material->getKa()->getValue(1) * illumination->getLightAmbient()->getValue(1);
	Ig += material->getKd()->getValue(1) * illumination->getLightIntesity()->getValue(1) * fmax(0,dot1);
	Ig += material->getKs()->getValue(1) * illumination->getLightIntesity()->getValue(1) * fmax(0,(pow(dot2,(material->getNs()))));

	Ib  = material->getKa()->getValue(2) * illumination->getLightAmbient()->getValue(2);
	Ib += material->getKd()->getValue(2) * illumination->getLightIntesity()->getValue(2) * fmax(0,dot1);
	Ib += material->getKs()->getValue(2) * illumination->getLightIntesity()->getValue(2) * fmax(0,(pow(dot2,(material->getNs()))));
	
	//delete centroid;
	//delete normal;
	delete v;
	//delete l; Nao consigo deletar esse porque se trata de um ponteiro prodigio... tsc tsc
	delete r;

	return new Vector(fmin(Ir,1), fmin(Ig,1), fmin(Ib,1));
}