/*	listVertex.h - Caio Viktor
	implementa estrutura de lista encadeada de vertices utilizada na classe objeto 
*/
typedef struct Node_{
	Vertex *vertex;
	struct Node_ *next;
} Node;
class ListVertex{
	int number;
	Node *first, *last;
public:
	ListVertex();
	ListVertex(Vertex *vertex);
	bool isempty();
	void addVertex(Vertex *vertex);
	Vertex* getVertex(int index);
	void list();
	void transformation(Matrix*);
	int numberVertex();
};