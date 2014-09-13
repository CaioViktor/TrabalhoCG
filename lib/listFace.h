/*	listFace.h - Caio Viktor
	implementa estrutura de lista encadeada de faces utilizada na classe objeto 
*/
typedef struct NodeFace_{
	Face *face;
	struct NodeFace_ *next;
} NodeFace;
class ListFace{
	int number;
	NodeFace *first, *last;
public:
	ListFace();
	ListFace(Face *face);
	bool isempty();
	void addFace(Face *face);
	Face* getFace(int index);
	void list();
	void drawWired();
	void drawSolid();
	int numberFaces();
};