#include "../../lib/main.h"
int main(){
	Vertex *v  = new Vertex( (double) 1,(double) 3,(double) 5);
	Vertex *v2 = new Vertex( (double) 2,(double) 3,(double) 5, 2);
	Vertex *v3 = new Vertex( (double) 3,(double) 7,(double) 9, 3);
	Face *f1 = new Face();
	f1->setVertice1(v);
	f1->setVertice2(v2);
	f1->setVertice3(v3);
	cout << "Face criada com sucesso\n";
	f1->showVertexs();

	ListFace *l1 = new ListFace();
	l1->list();
	l1->addFace(f1);
	l1->list();


	Vertex *v4  = new Vertex( (double) 4,(double) 3,(double) 5);
	Vertex *v5 = new Vertex( (double) 5,(double) 3,(double) 5, 2);
	Vertex *v6 = new Vertex( (double) 6,(double) 7,(double) 9, 3);
	Face *f2 = new Face();
	f2->setVertice1(v4);
	f2->setVertice2(v5);
	f2->setVertice3(v6);
	cout << "Face 2 criada com sucesso\n";


	Vertex *v7  = new Vertex( (double) 7,(double) 3,(double) 5);
	Vertex *v8 = new Vertex( (double) 8,(double) 3,(double) 5, 2);
	Vertex *v9 = new Vertex( (double) 9,(double) 7,(double) 9, 3);
	Face *f3 = new Face(v7,v8,v9);
	cout << "Face 3 criada com sucesso\n";	

	l1->addFace(f2);
	l1->addFace(f3);
	l1->addFace(f1);
	l1->list();
	
	l1->drawWired();
	l1->drawSolid();

	cout << "Número de faces: " << l1->numberFaces() << endl;
	return 0;
}