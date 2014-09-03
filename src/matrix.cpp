//Autor: Matheus Mayron e Cristiano.
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

//Destrutor MUAHUAHUA
Matrix::~Matrix(){
    for(int i=0;i<4;i++){
        delete [] content[i];
    }
    delete [] content;
}


//Retorna um ponteiro para os valores da matriz estão armazenados.
double** Matrix::getContent(){return content;}


//Atualiza o conteúdo da matriz por completo. Espera como entrada um ponteiro para uma matriz.
void  Matrix::setContent(double **c){content = c;};


//Retorna o valor de uma posição da matriz
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
Matrix Matrix::getTransposed(){
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
Matrix Matrix::getIdentity(){
    Matrix matrixId;
    for(int i=0; i<4; i++){
        matrixId.setPosition(i,i,1);
    }
    return matrixId;
}



//Retorna uma matriz para que seja realizada uma translação
Matrix Matrix::getTranslation(double x,double y,double z){
    Matrix translate = getIdentity();
    translate.setPosition(0,3,x);
    translate.setPosition(1,3,y);
    translate.setPosition(2,3,z);
    return translate;
}

// PONTO IMPORTANTE: o parâmetro angle das funções de rotação espera receber um ângulo em RADIANOS.

//Retorna uma matriz para que seja realizada uma rotação em torno do eixo x;
Matrix Matrix::getRotationX(double angle){
    Matrix rotatex = getIdentity();
    rotatex.setPosition(1,1,cos(angle));
    rotatex.setPosition(1,2,-sin(angle));
    rotatex.setPosition(2,1,sin(angle));
    rotatex.setPosition(2,2,cos(angle));
    return rotatex;
}

//Retorna uma matriz para que seja realizada uma rotação em torno do eixo y;
Matrix Matrix::getRotationY(double angle){
    Matrix rotatey = getIdentity();
    rotatey.setPosition(0,0,cos(angle));
    rotatey.setPosition(0,2,sin(angle));
    rotatey.setPosition(2,0,-sin(angle));
    rotatey.setPosition(2,2,cos(angle));
    return rotatey;
}

//Retorna uma matriz para que seja realizada uma rotação em torno do eixo z;
Matrix Matrix::getRotationZ(double angle){
    Matrix rotatez = getIdentity();
    rotatez.setPosition(0,0,cos(angle));
    rotatez.setPosition(0,1,-sin(angle));
    rotatez.setPosition(1,0,sin(angle));
    rotatez.setPosition(1,1,cos(angle));
    return rotatez;
}

//Retorna uma matriz para que seja realizada a transformação de escala em relação a um ponto fixo.
Matrix Matrix::getScale(double dx, double dy, double dz, double xf, double yf, double zf){
    Matrix scale = getIdentity();
    scale.setPosition(0,0,dx);
    scale.setPosition(1,1,dy);
    scale.setPosition(2,2,dz);
    scale.setPosition(0,3,xf);
    scale.setPosition(1,3,yf);
    scale.setPosition(2,3,zf);
    return scale;
}
