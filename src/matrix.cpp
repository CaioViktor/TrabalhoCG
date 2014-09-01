//Essa é uma implementação de uma Matriz de tamanho fixo 4x4
//A limitação dimensional pode ser alterada com poucas modificações

//Constrói um matriz 4x4 com todos os elementos iguais a 0;
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

//Constrói uma matriz 4x4 a partir de um array2d;
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


//Retorna o um ponteiro para on os valores da matriz estão armazenados.
double** Matrix::getConteudo(){return conteudo;}

//Atualiza o conteudo da matriz por completo. Espera como entrada um ponteiro para uma matriz.
void  Matrix::setConteudo(double **c){conteudo=c;};


//Atualiza uma única posição da matriz.
void Matrix::setPosition(int linha,int coluna, double value){
    if(linha>=0 & linha<4 & coluna>=0 & coluna<4){
        conteudo[linha][coluna]=value;
    }
}

//Exibe na tela o conteúdo da matriz
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

//Retorna a matriz transposta da matriz armazenada em conteúdo.
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


//Retorna a matriz identidade.
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
