#include "../lib/main.h"

int main(){
	Vertex *vertice1 = new Vertex( (double) 1,(double) 1,(double) 1);
	Vertex *vertice2 = new Vertex( (double) 2,(double) 2,(double) 2);
	Vertex *vertice3 = new Vertex( (double) 3,(double) 3,(double) 3);

	Face *face1 = new Face(vertice1, vertice2, vertice3);

	Vertex *vet = face1->getVertice1();

	cout<< "Vertice 1:" << vet->getCoordinateXd() << endl;
}