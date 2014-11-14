/**
*\author Matheus Mayron
*/

typedef struct NodeMaterial_{
	Material *material;		
	struct NodeMaterial_ *next;
} NodeMaterial;
