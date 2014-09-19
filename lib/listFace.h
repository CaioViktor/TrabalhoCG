/**
*\file ListFace.h
*\class ListFace
*\author Caio Viktor
*\brief Implementa estrutura de lista encadeada de faces utilizada na classe objeto.
*/


typedef struct NodeFace_{
	Face *face;
	struct NodeFace_ *next;
} NodeFace;

class ListFace{
	int number;
	NodeFace *first, *last;
public:
	/**
	*	Construtor da classe ListFace. Inicia uma lista vazia.
	*/
	ListFace();
	
	/**
	*	Construtor da classe ListFace, inicia a lista com uma face passado como parâmetro.
	*	\param face Ponteiro para um objeto do tipo Face.
	*/
	ListFace(Face *face);
	
	/**
	*	Verifica se a lista de faces está vazia.
	*	\return True se estiver e fase caso contrário.
	*/
	bool isempty();
	
	/**
	*	Adiciona uma face passada como parâmetro na ultima posição da lista caso ele ainda não exista na lista.<BR> 
	*	Caso ele já exista, retorna uma mensagem informando 
	*	\param face ponteiro para um objeto do tipo Face
	*/
	void addFace(Face *face);
	
	/**
	*	\param index Posiçao da objeto Face desejada na lista de faces.
	*	\return Um ponteiro para a face desejada. Retorna null caso ele nao exista.
	*/
	Face* getFace(int index);
	

	/**
	*	Printa as coordenadas de todos os vértices da lista (Utilizada para teste). Protótipo da função de transformação.
	*/
	void list();
	

	/**
	*	Desenha todas as faces da lista em aramado.
	*/
	void drawWired();
	

	/**
	*	Desenha todas as faces da lista em sólido.
	*/
	void drawSolid();
	

	/**
	*	\return O número de faces contidas na lista.
	*/
	int numberFaces();
};

