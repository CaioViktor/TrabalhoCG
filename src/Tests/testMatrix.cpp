//Autor: Matheus Mayron
#include "../../lib/main.h"
int main()
{
    Matrix *padrao = new Matrix();
    Matrix *identidade = Matrix::getIdentity();
    Matrix *transposta = new Matrix();
    double a[4][4]={{4,0,8,1},{0,5,0,0},{0,0,6,7},{1,1,0,1}};
    double b[4][4]={{10,0,2.2,9},{1,1,0,3},{1,8,2,0},{12,0,0,8}};

    double m[4][4]=
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
    cout << "1:\n";
	Matrix *recebeVetor2d = new Matrix(m);
    cout << "2:\n";
    padrao->printMatrix();
    cout << "4:\n";
    identidade->printMatrix();
    cout << "5:\n";
    recebeVetor2d->printMatrix();
    cout << "6:\n";
    recebeVetor2d->getTransposed()->printMatrix();
    cout << "7:\n";
    recebeVetor2d->setPosition(1,0,9);
    cout << "8:\n";
    recebeVetor2d->printMatrix();

    cout << "nova matrix:\n";
    Matrix *matrix = new Matrix(m);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cout << matrix->getPosition(i,j) << endl;


    //Testa Multiplicação de Matrizes.


    cout << "\n\nVamos multiplicar as duas matrizes seguintes." << endl;
    Matrix *A = new Matrix(a);
    A->printMatrix();
    Matrix *B = new Matrix(b);
    B->printMatrix();
    cout << "\nResultado: " << endl;
    Matrix *C = A->multiplyMatrix(B);
    C->printMatrix();

    cout << "\n\nMatrizes de transformação teste." << endl;

    //Matrizes de Transformação - Falta testar as outras operações.
    Matrix *rotx = Matrix::getRotationX(0.7853);
    rotx->printMatrix();
    cout << "em torno de Y:\n";
    Matrix *roty = Matrix::getRotationY(0.7853);
    roty->printMatrix();
    cout << "em torno de Z:\n";
    Matrix *rotz = Matrix::getRotationZ(0.7853);

    rotz->printMatrix();
    rotz->getTransposed()->printMatrix();

    Matrix* inversa = rotz->getInverse();
    inversa->printMatrix();



    //A de escala depois eu reviso

    cout << "\n**Fim do testMatrix**" << endl;
}
