//Autor: Matheus Mayron... At� agora. Cristiano vem ai.

//Essa � uma implementa��o de uma Matriz de tamanho fixo 4x4
//A limita��o dimensional pode ser alterada com poucas modifica��es
#include "../lib/main.h"


//Constr�i um matriz 4x4 com todos os elementos iguais a 0;
Matrix::Matrix(){
    double **matrix4x4;

	matrix4x4 = new double*[4];
	for(int i=0 ;i<4 ;i++){
		matrix4x4[i] = new double[4];
		for(int j=0; j<4; j++){
			matrix4x4[i][j] = 0;
		}
	}
	content = matrix4x4;
}

//Constr�i uma matriz 4x4 a partir de um array2d;
Matrix::Matrix(double c[4][4]){
    double **matrix4x4;
	matrix4x4 = new double*[4];
	for(int i=0; i<4; i++){
		matrix4x4[i] = new double[4];
		for(int j=0; j<4; j++){
			matrix4x4[i][j] = c[i][j];
		}
	}
	content = matrix4x4;
}


//Retorna o um ponteiro para on os valores da matriz est�o armazenados.
double** Matrix::getContent(){return content;}

//Atualiza o conteudo da matriz por completo. Espera como entrada um ponteiro para uma matriz.
void  Matrix::setContent(double **c){content = c;};


//Atualiza uma �nica posi��o da matriz.
void Matrix::setPosition(int lin,int col, double value){
    if((lin>=0) & (lin<4) & (col>=0) & (col<4)){
        content[lin][col] = value;
    }
}

//Exibe na tela o conte�do da matriz
void Matrix::printMatrix(){
	cout << endl;
	for(int i=0; i<4; i++){
		for(int j=0 ;j<4; j++){
			cout << content[i][j] << " ";
		}
	cout << endl;
	}

}

//Retorna a matriz transposta da matriz armazenada em conte�do.
Matrix Matrix::getTransposed()
{
    Matrix trans;
    double** contTrans = trans.getContent();
	for(int i=0; i<4 ; i++){
		for(int j=i; j<4; j++){
			contTrans[j][i] = content[i][j];
			contTrans[i][j] = content[j][i];
		}
	}
	return trans;
}


//Retorna a matriz identidade.
//TODO: Melhorar isso.
Matrix Matrix::getIdentity()
{
	Matrix matrixId;
	for(int i=0; i<4; i++){
		matrixId.setPosition(i,i,1);
	}
	return matrixId;
}
