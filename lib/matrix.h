/**
*\file matrix.h
*\class Matrix
*\authors Matheus Mayron, Cristiano e Caio Viktor
*\brief Armazenar matrizes e facilitar as operações feitas com matrizes.
*/
class Matrix
{
    //!Guarda o conteudo da matriz.
	double **content;

public:

    //Construtores e Destrutores.


	/** Constrói um objeto Matrix.*/
    Matrix();


	/**
	*	Constrói uma matriz 4x4 a partir de um array2d.
	*	\param array2d É um array bidimensional. Espera-se que ele só seja constituído por números.
    */
	Matrix(double array2d[4][4]);


	/** Destroi o objeto, desalocando também o que foi alocado em seu interior*/
    ~Matrix();

    //getters e setters.

	/** \return Um ponteiro para os valores da matriz estão armazenados. */
    double **getContent();


	/**
	*	Retorna um valor presente na matriz armazenada no objeto Matrix.
	*	\param lin Valor correspondente a linha da posição desejada.
	*	\param col Valor correspondente a coluna da posição desejada.
	*	\return O valor da posição [lin,col]
	*/
    double getPosition(int lin, int col);


	/**
	*	Atualiza o conteudo da matriz por completo. Espera como entrada um ponteiro para uma matriz.
	*	\param c Espera como entrada um ponteiro para uma matriz.
	*/
    void setContent(double **c);


	/**
	*	Atualiza uma única posição da matriz.
	*	\param lin Valor correspondente a linha da posição desejada.
	*	\param col Valor correspondente a coluna da posição desejada.
	*	\param value Novo valor da posição [lin,col]
	*/
    void setPosition(int lin, int col, double value);


    //Utilitarias.

	/**
	*	Gera a matriz identidade.
	*	\return Ponteiro para uma objeto Matrix que contém uma matriz identidade.
	*/
    static Matrix* getIdentity();


	/**
	*	Gera a matriz transposta.
	*	\return Ponteiro para um objeto contendo a matriz transposta ao do objeto que a invocou.
	*
	*/
    Matrix* getTransposed();


	/**
	*	Gera uma copia da matriz atual.
	*	\return Ponteiro para um objeto contendo uma copia do objeto que a invocou.
	*
	*/
    Matrix* getCopy();


	/**
	*	Gera a matriz inversa.
	*	\return Ponteiro para um objeto contendo a matriz inversa ao do objeto que a invocou.
	*
	*/
    Matrix* getInverse();


	/**
	*	Multiplica duas matrizes.
	*	\param B Ponteiro para um objeto Matrix com o qual se deseja realizar a multiplicação.
	*	\return Multiplicação entre a matriz armazenada no próprio objeto e a matriz da Matrix B.
	*/
    Matrix* multiplyMatrix(Matrix* B);


	/** Exibe na tela a matriz armazenada no objeto Matrix que o invocou. */
    void printMatrix();


    //Transformações
	/**
	*	Gera uma matriz de translação.
	*	\param x Deslocamento sobre o eixo X.
	*	\param y Deslocamento sobre o eixo Y.
	*	\param z Deslocamento sobre o eixo Z.
	*	\return Ponteiro para um objeto Matrix contendo a matriz de transformação desejada.
	*/
    static Matrix* getTranslation(double x, double y, double z);

	/**
	*	Gera uma matriz de rotação em torno do eixo X
	*	\param angle Ângulo da rotação.
	*	\return Ponteiro para um objeto Matrix contendo a matriz de rotação desejada
	*/
    static Matrix* getRotationX(double angle);

	/**
	*	Gera uma matriz de rotação em torno do eixo Y
	*	\param angle Ângulo da rotação.
	*	\return Ponteiro para um objeto Matrix contendo a matriz de rotação desejada
	*/
    static Matrix* getRotationY(double angle);

	/**
	*	Gera uma matriz de rotação em torno do eixo Z
	*	\param angle Ângulo da rotação.
	*	\return Ponteiro para um objeto Matrix contendo a matriz de rotação desejada
	*/
    static Matrix* getRotationZ(double angle);

	/**
	*	Gera uma matriz de escala.
	*	\param dx Deformação desejada no eixo X.
	*	\param dy Deformação desejada no eixo Y.
	*	\param dz Deformação desejada no eixo Z.
	*	\param xf Coordenada X do ponto fixo.
	*	\param yf Coordenada Y do ponto fixo.
	*	\param zf Coordenada Z do ponto fixo.
	*	\result Ponteiro para um objeto Matrix contendo a matriz de escala desejada.
	*/
    static Matrix* getScale(double dx, double dy, double dz, double xf, double yf, double zf);

    //Sobrecarga operador multiplicação matrizes
    Matrix operator*(Matrix B);
    bool operator==(Matrix B);
};


