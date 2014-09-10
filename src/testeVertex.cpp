#include "../lib/main.h"
int main(){
	cout.precision(15);
	Vertex *v = new Vertex();
	Vertex *v2 = new Vertex( (double) 2,(double) 3,(double) 5);
	Vertex *v3 = new Vertex( (double) 2,(double) 3,(double) 5, 2);
	
	cout << v->getCoordinateXd() << endl;
	v->setCoordinateX(2.123456789454678754535);
	cout << v->getCoordinateXd() << endl;
	cout << v->getCoordinateXf() << endl;

	cout << v->getCoordinateYd() << endl;
	v->setCoordinateY(2*2.123456789454678754535);
	cout << v->getCoordinateYd() << endl;
	cout << v->getCoordinateYf() << endl;

	cout << v->getCoordinateZd() << endl;
	v->setCoordinateZ(3*2.123456789454678754535);
	cout << v->getCoordinateZd() << endl;
	cout << v->getCoordinateZf() << endl;

	cout << v->getCoordinateWd() << endl;
	v->setCoordinateW(4*2.123456789454678754535);
	cout << v->getCoordinateWd() << endl;
	cout << v->getCoordinateWf() << endl;

	cout << "V2: ";
	v2->showVertex();

	cout << "V3: ";
	v3->showVertex();	

	free(v);
	free(v2);
	free(v3);
}