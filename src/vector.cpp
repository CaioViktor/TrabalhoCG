/* vector.cpp - Caio Viktor
*  classe responsável pela implementação de estrutura de vetores de coordenadas 4X1 
*/
#include "../lib/main.h"
//Cria vetor double* de 4 posições e o seta em vecto  ou seja um vetor de ponteiros de double 
Vector::Vector(){
	double **newVector = new double*[4];
	newVector[0] = (double*) malloc(sizeof(double));
	newVector[1] = (double*) malloc(sizeof(double));
	newVector[2] = (double*) malloc(sizeof(double));
	newVector[3] = (double*) malloc(sizeof(double));
	this->length = 4;
	this->vector = newVector;
}

Vector::Vector(double x, double y, double z){
	double **newVector = new double*[3];
	newVector[0] = (double*) malloc(sizeof(double));
	newVector[1] = (double*) malloc(sizeof(double));
	newVector[2] = (double*) malloc(sizeof(double));
	this->length = 3;
	this->vector = newVector;
	this->setValue(0,x);
	this->setValue(1,y);
	this->setValue(2,z);
	
}

//
// Vector::Vector(Vertex *vertex){
	
// }

//retorna o vetor de ponteiros double onde os valores estão armazenados
double** Vector::getVector(){
	return this->vector;
}

// retorna o valor da posição passada por parâmetro
double Vector::getValue(int position){
	if(position >= 0 && position < this->length){
		double **newVector = this->vector;
		return *newVector[position];
	}
	else
		return 0;
}

//atualiza a posição passada por parâmetro para o valor passado por parâmetro
void Vector::setValue(int position,double value){
	if(position >= 0 && position < this->length){
		double **newVector = this->vector;
		*newVector[position] = value;
		//cout << "Valor armazenado no vetor\n";
	}
	else
		cout << "Erro posição inexistente\n";
}
//atualiza o ponteiro da posição passada por parâmetro para o ponteiro passado por parâmetro ou seja guarda uma referência no vetor
void Vector::setValue(int position,double *value){
	if(position >= 0 && position < this->length){
		double **newVector = this->vector;
		newVector[position] = value;
		//cout << "Ponteiro armazenado no vetor\n";
	}
	else
		cout << "Erro posição inexistente\n";	
}
//exibe os valores contidos no vetor
void Vector::showVector(){
	for(int i=0;i < this->length;i++){
		cout << this->getValue(i)<<endl;	
	}
}
//multiplica vector por matrix e armazena o resultado no próprio vetor
void Vector::multiplicationMatrix(Matrix *matrix){
	double vector[4];
	for(int i = 0; i < 4; i++)
		vector[i] = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			vector[i] = vector[i] + matrix->getPosition(i,j) * this->getValue(j);
	for(int i = 0; i < 4; i++)
		this->setValue(i,vector[i]);
}

Vector* Vector::multiplyMatrix(Matrix *matrix){
	Vector *vector = new Vector();
	for(int i = 0 ; i < 4 ; i++)
		for(int j = 0; j < 4 ; j++)
			vector->setValue(i, vector->getValue(i) + matrix->getPosition(i,j) * this->getValue(j));
	return vector;
}

//Sobrecarga operador multiplicação para matrizes
Vector Vector::operator*(Matrix M){
    double vector[4];
    Vector result;
    for(int i = 0; i < 4; i++)
        vector[i] = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            vector[i] = vector[i] + M.getPosition(i,j) * this->getValue(j);
    for(int i = 0; i < 4; i++)
        result.setValue(i,vector[i]);    
    return result;
}

Vector Vector::operator-(Vector V){
	if(length == V.length){
		double r[length];
		for(int i = 0 ; i < length ; i++){
			r[i] = getValue(i) - V.getValue(i);
		}
		if(length == 4){
			Vector result;
			for(int i = 0; i < 4; i++)
				result.setValue(i,r[i]);
			return result;
		}
		else{
			Vector result(0,0,0);
			for(int i = 0; i < 3; i++)
				result.setValue(i,r[i]);
			return result;
		}
	}
	else{
		cout << "Erro: Os vetores não possuem mesma dimenensão!\n";
		Vector r;
		return r;
	}
}

