/* vector.cpp - Caio Viktor
*  classe responsável pela implementação de estrutura de vetores de coordenadas 4X1 
*/
#include "../lib/main.h"
//
Vector::Vector(){
	double **newVector = new double*[4];
	for(int i=0;i<4;i++)
		newVector[i] = 0;
	this->vector = newVector;
}
//
// Vector::Vector(Vertex *vertex){
	
// 	vertex->toVector()


// }
 //
// Vector::Vector(double[4] vector){

// }
// //
// double* Vector::getVector(){

// }
// //
// double* Vector::getValue(int position){

// }
// //
// void Vector::setValue(int position,double value){

// }
// //
// void Vector::showVector(){

// }
// //
// void multiplicationMatrix(Matrix *matrix){

// }