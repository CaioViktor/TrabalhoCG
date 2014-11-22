/**
*\file topology.h
*\author Caio Viktor
*/

/**
*\brief Implementa estrutura de topologia contendo os array de objetos,faces e vértices.
*/
typedef struct Topology_{
	ObjectClass **ObjectArray;	///<Vetor contendo todos os objetos criados
	int ObjectNumber;			///<Número de objetos criados

	Face **FaceArray;			///<Vetor contendo todas as faces criadas
	int FaceNumber;				///<Número de faces criadas

	Vertex **VertexArray;		///<Vetor contendo todos os vértices criados
	int VertexNumber;			///<Número de vértices criadas

	ListMaterial *Materials; //by: Luke - Pequena alteração para armazenar os materiais
	int MaterialNumber;   
} Topology;
