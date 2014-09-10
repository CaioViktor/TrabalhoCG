/*	topology.h - Caio Viktor
	implementa estrutura de topologia contendo os array de objetos,faces e vértices.
*/
typedef struct Topology_{
	ObjectClass **ObjectArray;
	int ObjectNumber;

	Face **FaceArray;
	int FaceNumber;

	Vertex **VertexArray;
	int VertexNumber;
} Topology;
