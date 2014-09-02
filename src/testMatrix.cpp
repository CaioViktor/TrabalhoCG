//Autor: Matheus Mayron
#include "../lib/main.h"
int main()
{
    Matrix padrao;
    Matrix identidade;
    Matrix transposta;
    double m[4][4]=
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
    cout << "1:\n";
	Matrix recebeVetor2d(m);
    cout << "2:\n";
    identidade = Matrix::getIdentity();
    cout << "3:\n";
    padrao.printMatrix();
    cout << "4:\n";
    identidade.printMatrix();//falha segmentação
    cout << "5:\n";
    recebeVetor2d.printMatrix();
    cout << "6:\n";
    recebeVetor2d.getTransposed().printMatrix();
    cout << "7:\n";
    recebeVetor2d.setPosition(1,0,9);
    cout << "8:\n";
    recebeVetor2d.printMatrix();

    cout << "nova matrix:\n";
    Matrix *matrix = new Matrix(m);
    cout << matrix->getPosition(0,0) << endl;

}
