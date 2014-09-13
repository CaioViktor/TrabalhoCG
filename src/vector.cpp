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
	this->vector = newVector;
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
	if(position >= 0 && position < 4){
		double **newVector = this->vector;
		return *newVector[position];
	}
	else
		return 0;
}

//atualiza a posição passada por parâmetro para o valor passado por parâmetro
void Vector::setValue(int position,double value){
	if(position >= 0 && position < 4){
		double **newVector = this->vector;
		*newVector[position] = value;
		//cout << "Valor armazenado no vetor\n";
	}
	else
		cout << "Erro posição inexistente\n";
}
//atualiza o ponteiro da posição passada por parâmetro para o ponteiro passado por parâmetro ou seja guarda uma referência no vetor
void Vector::setValue(int position,double *value){
	if(position >= 0 && position < 4){
		double **newVector = this->vector;
		newVector[position] = value;
		//cout << "Ponteiro armazenado no vetor\n";
	}
	else
		cout << "Erro posição inexistente\n";	
}
//exibe os valores contidos no vetor
void Vector::showVector(){
	for(int i=0;i<4;i++){
		cout << this->getValue(i)<<endl;	
	}
}
//multiplica vector por matrix e armazena o resultado na própria matriz
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