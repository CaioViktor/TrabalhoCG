#include "../../lib/main.h"
int main(){
	Vertex *v  = new Vertex( (double) 1,(double) 3,(double) 5);
	Vertex *v2 = new Vertex( (double) 2,(double) 3,(double) 5, 2);
	Vertex *v3 = new Vertex( (double) 3,(double) 7,(double) 9, 3);
	Vertex *v4 = new Vertex( (double) 4,(double) 7,(double) 9, 3);
	ListVertex *l1 = new ListVertex();
	cout << l1->isempty() << endl;
	l1->addVertex(v);
	cout << l1->isempty() << endl;
	l1->list();
	l1->addVertex(v2);
	l1->addVertex(v3);
	l1->list();
	cout << "Atualizações: \n";
	v->setCoordinateX((double)4);
	v2->setCoordinateX((double)5);
	l1->list();
	cout << "Lista 2:\n";
	ListVertex *l2 = new ListVertex(v);
	l2->list();
	Vertex *f1 = l2->first->vertex;
	f1->setCoordinateX((double) 9);
	l2->list();
	Vertex *f2 = l1->first->vertex;
	cout << "Lista 1: " << f2->getCoordinateXd() << endl;
	cout << "Vertice: " << v->getCoordinateXd() << endl;	
	cout << "lista 1:\n";
	l1->list();
	cout << "tenta adicionar vertice: " << v->getCoordinateXd() << endl;
	l1->addVertex(v);
	l1->list();
	cout << "tenta adicionar vertice: " << v4->getCoordinateXd() << endl;
	l1->addVertex(v4);
	l1->list();
	cout << "tenta adicionar vertice: " << v4->getCoordinateXd() << endl;
	l1->addVertex(v4);
	l1->list();


	cout << "Teste transformação:\n";
	cout << "Antes:\n";
	ListVertex *list = new ListVertex(v);
	list->addVertex(v2);
	list->addVertex(v3);
	list->addVertex(v4);
	cout << "Matriz:\n";
	Matrix::getRotationX(0.7853)->printMatrix();
	list->list();
	cout << "Depois:\n";
	list->transformation(Matrix::getRotationX(0.7853));
	list->list();
	cout << "Número de faces: " << l1->numberVertex() << endl;
	return 0;
}