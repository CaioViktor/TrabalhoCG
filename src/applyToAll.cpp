#include "../lib/main.h"
void applyToAll(Vertex **arrayVertex,int qtd,Matrix *transformation){
	for(int i = 0 ; i < qtd ; i++){
		arrayVertex[i]->toVector()->multiplicationMatrix(transformation);
	}
}