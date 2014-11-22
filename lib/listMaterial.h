/**
*\author Matheus Mayron
*/

typedef struct NodeMaterial_{
	Material *material;
	struct NodeMaterial_ *next;
} NodeMaterial;


class ListMaterial{
	int size;
	NodeMaterial* first;
	NodeMaterial* last;

public:

	ListMaterial();

	~ListMaterial();

	void addMaterial(Material* m);

	Material* getMaterial(std::string materialName);

	bool isEmpty();

	int getSize();

	Material** toVector();

};
