/*	listVertex.h - Caio Viktor
	implementa estrutura de lista encadeada de vertices utilizada na classe objeto 
*/
typedef struct Node_{
	Vertex *vertex;
	struct Node_ *next;
} Node;
class ListVertex{
public:
	Node *first, *last;
	ListVertex();
	ListVertex(Vertex *vertex);
	bool isempty();
	void addVertex(Vertex *vertex);
	void list();
	void transformation(Matrix*);
	int numberVertex();
};