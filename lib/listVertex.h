/**
*\file listVertex.h
*\class ListVertex
*\author Caio Viktor
*\brief Implementa estrutura de lista encadeada de vertices utilizada na classe objeto.
*/

/** 
*\brief Um nó da lista de vertices.
*/
typedef struct Node_{
	Vertex *vertex;		///< Ponteiro para um objeto do tipo Vertex armazenado pelo nó.
	struct Node_ *next;	///< Ponteiro para o nó posterior a ele.
} Node;


class ListVertex{
	int number;
	Node *first, *last;
public:

	/**
	*	Construtor da classe ListVertex. Inicia uma lista vazia.
	*/
	ListVertex();

	/**
	*	Construtor da classe ListVertex, inicia a lista com um vértice passado como parâmetro.
	*	\param vertex Ponteiro para um objeto do tipo Vertex.
	*/
	ListVertex(Vertex *vertex);

	/**
	*	Verifica se a lista está vazia.
	*	\result Valor \c true caso ela esteja vazia e \c false caso contrário.
	*/
	bool isempty();
	
	/**
	*	Aiciona um vertice passado como parâmetro na ultima posição da lista caso ele ainda não exista na lista. <BR>
	*	Caso contrário, ele retorna uma mensagem informando.
	*	\param vertex Ponteiro para o vértice que se deseja adicionar.
	*/	
	void addVertex(Vertex *vertex);
	
	/**
	*	Retorna o vértice na posição passada por parâmetro.
	*	\param index Inteiro com a posicao desejada iniciando-se de 0
	*	\result Um ponteiro para o vértice ou \c null caso ele não exista.
	*/
	Vertex* getVertex(int index);
	
	/**
	*	Printa as coordenadas X de todos os vértices da lista (Utilizada para teste).
	*	Protótipo da função de transformação.
	*/
	void list();
	
	/**
	*	Aplica uma transformação em todos os vértices da lista. 
	*	Percorre a lista multiplicando cada vértice pela matriz passada.
	*	\param matrix Um ponteiro para um objeto do tipo Matrix.
	*/
	void transformation(Matrix*);
	
	/**
	*	\result O número de vértices existentes na lista
	*/
	int numberVertex();
};