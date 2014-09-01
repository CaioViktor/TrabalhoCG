#include <iostream>
class Matrix
{
    double **conteudo;
public:
    Matrix(void);
    Matrix(double c[4][4]);

    static Matrix getIdentity(void);
    Matrix getTransposed(void);

    double** getConteudo(void);
    double getPosition(int,int);

    void setConteudo(double**);
    void setPosition(int,int,double);
    void printMatrix();

};

Matrix::Matrix()
{
    double **matrix4x4;
	matrix4x4 = new double*[4];
	for(int i=0;i<4;i++)
	{
		matrix4x4[i] = new double[4];
		for(int j=0;j<4;j++)
		{
			matrix4x4[i][j]=0;
		}
	}
	conteudo=matrix4x4;
}

Matrix::Matrix(double c[4][4])
{
    double **matrix4x4;
	matrix4x4 = new double*[4];
	for(int i=0;i<4;i++)
	{
		matrix4x4[i] = new double[4];
		for(int j=0;j<4;j++)
		{
			matrix4x4[i][j]=c[i][j];
		}
	}
	conteudo=matrix4x4;
}

double** Matrix::getConteudo(){return conteudo;}

void  Matrix::setConteudo(double **c){conteudo=c;};

void Matrix::setPosition(int linha,int coluna, double value){
    if(linha>=0 & linha<4 & coluna>=0 & coluna<4){
        conteudo[linha][coluna]=value;
    }
}

void Matrix::printMatrix()
{
	std::cout<< std::endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			std::cout<< conteudo[i][j] << " ";
		}
	std::cout<< std::endl;
	}

}

Matrix Matrix::getTransposed()
{
    Matrix trans;
    double** contTrans = trans.getConteudo();
	for(int i=0; i<4 ; i++)
	{
		for(int j=i;j<4;j++)
		{
			contTrans[j][i]=conteudo[i][j];
			contTrans[i][j]=conteudo[j][i];
		}
	}
	return trans;
}

Matrix Matrix::getIdentity()
{
	Matrix matrixId;
	double** conteudo= matrixId.getConteudo();
	for(int i=0;i<4;i++)
	{
		conteudo[i][i]=1;
	}
	return matrixId;
}




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
