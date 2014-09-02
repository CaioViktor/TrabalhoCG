//Autor: Matheus Mayron... Até agora. Cristiano vem ai.

//Essa é uma implementação de uma Matriz de tamanho fixo 4x4
//A limitação dimensional pode ser alterada com poucas modificações
#include "../lib/main.h"


//Constrói um matriz 4x4 com todos os elementos iguais a 0;
Matrix::Matrix(){
    content = new double*[4];
    for(int i=0 ;i<4 ;i++){
        content[i] = new double[4];
        for(int j=0; j<4; j++){
            content[i][j] = 0;
        }
    }
}

//Constrói uma matriz 4x4 a partir de um array2d;
Matrix::Matrix(double c[4][4]){
    content = new double*[4];
    for(int i=0; i<4; i++){
        content[i] = new double[4];
        for(int j=0; j<4; j++){
            content[i][j] = c[i][j];
        }
    }
}

Matrix::~Matrix(){
    for(int i=0;i<4;i++){
        delete [] content[i];
    }
    delete [] content;
}


//Retorna o um ponteiro para on os valores da matriz estão armazenados.
double** Matrix::getContent(){return content;}

//Atualiza o conteudo da matriz por completo. Espera como entrada um ponteiro para uma matriz.
void  Matrix::setContent(double **c){content = c;};


double Matrix::getPosition(int lin, int col){
        return content[lin][col];
}

//Atualiza uma única posição da matriz.
void Matrix::setPosition(int lin,int col, double value){
    if((lin>=0) & (lin<4) & (col>=0) & (col<4)){
        content[lin][col] = value;
    }
}

//Exibe na tela o conteúdo da matriz
void Matrix::printMatrix(){
    cout << endl;
    for(int i=0; i<4; i++){
        for(int j=0 ;j<4; j++){
            cout << content[i][j] << " ";
        }
    cout << endl;
    }

}

//Retorna a matriz transposta da matriz armazenada em conteúdo.
Matrix Matrix::getTransposed()
{
    Matrix trans;
    for(int i=0; i<4 ; i++){
        for(int j=i; j<4; j++){
            trans.setPosition(j,i,content[i][j]);
            trans.setPosition(i,j,content[j][i]);
        }
    }
    return trans;
}


//Função que faz o produto de duas matrizes.
Matrix Matrix::multiplyMatrix( Matrix B ){
       Matrix C;
       int i, j , k;
       double temp;
       for( i = 0; i < 4; i++ ){
            for( j = 0; j < 4; j++ ){
                 temp = 0;
                 for( k = 0; k < 4; k++ ){
                      temp += this->getPosition(i,k) * B.getPosition(k,j);
                 }
                 C.setPosition( i, j, temp );
            }
       }
      return C;
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
