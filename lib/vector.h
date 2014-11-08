/**
*\file vector.h
*\class Vector
*\author Caio Viktor
*\brief Classe responsável pela implementação de estrutura de vetores de coordenadas 4X1 
*/

class Vector{
	double **vector; //!Guarda o conteudo do vetor.
public:
	/**Cria vetor double* de 4 posições e o seta em vecto  ou seja um vetor de ponteiros de double*/
	Vector();
	// Vector(Vertex*);

	/**
	*	\return Vetor de ponteiros do tipo double onde os valores estão armazenados. 
	*/
	double** getVector();

	/**
	*	Retorna o valor da posição passada por parâmetro
	*	\param position Posição desejada no vetor. (X Y Z W)
	*	\return O valor da posição desejada.
	*/
	double getValue(int);
	
	/**
	*	Atualiza a posição passada por parâmetro para o valor passado por parâmetro.
	*	\param position Posição no vetor.
	*	\param value Valor que será inserido na posição passada em position.
	*	\return
	*/
	void setValue(int,double);
	
	/**
	*	Atualiza o ponteiro da posição passada por parâmetro para o ponteiro passado por parâmetro ou seja guarda uma referência no vetor.
	*	\param position Posição no vetor.
	*	\param value Ponteiro que referência uma das posições no vetor.
	*	\return
	*/
	void setValue(int,double*);
	
	/**
	*	Exibe os valores contidos no vetor
	*/
	void showVector();
	
	/**
	*	Multiplica vector por matrix e armazena o resultado na própria matriz.
	*	\param matrix Matriz com a qual a multiplicaçao será realizada.
	*/
	void multiplicationMatrix(Matrix*);
	Vector operator*(Matrix M);
};