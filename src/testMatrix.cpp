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
	Matrix recebeVetor2d(m);

    identidade = Matrix::getIdentity();

    padrao.printMatrix();
    identidade.printMatrix();
    recebeVetor2d.printMatrix();
    recebeVetor2d.getTransposed().printMatrix();
    recebeVetor2d.setPosition(1,0,9);
    recebeVetor2d.printMatrix();

}
