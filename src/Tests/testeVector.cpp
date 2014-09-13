#include "../../lib/main.h"
int main(){
	Vector *v = new Vector();
	
	for(int i=0;i<4;i++){
		cout << "Valor inicial:\n" << v->getValue(i)<<endl;
		v->setValue(i,(double)i+2);
		cout << v->getValue(i)<<endl;	
	}

	double *d = (double *)malloc(sizeof(double));
	*d = 8;
	cout << "Ponteiro:\n" << *d <<endl;
	v->setValue(0,d);
	cout << v->getValue(0)<<endl;
	v->setValue(0,2);
	cout << "Vector: " << v->getValue(0) <<" Ponteiro:\n" << *d <<endl;

	cout << "GetVector:\n";
	double **v2 = v->getVector();
	for(int i=0;i<4;i++){
		cout << *v2[i]<<endl;	
	}
	

	cout << "showVector:\n";
	v->showVector();


	cout << "Vertex:\n";
	Vertex *ve = new Vertex((double) 7,(double) 8, (double) 9, (double) 10);
	Vector *v3 = ve->toVector();
	v3->showVector();
	for(int i = 0; i < 4;i++)
		v3->setValue(i,v3->getValue(i) + 1);
	cout << "Vector:\n";
	v3->showVector();
	cout << "Vertex: \n" << ve->getCoordinateXd() << endl << ve->getCoordinateYd() << endl << ve->getCoordinateZd() << endl << ve->getCoordinateWd() << endl;

	cout << "Multiplicação de vector por matriz matrix:\n";
	double m[4][4]=
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	Matrix *matrix = new Matrix(m);
	matrix->printMatrix();
	v3->multiplicationMatrix(matrix);
	cout << "Vector:\n";
	v3->showVector();
	cout << "Vertex: \n" << ve->getCoordinateXd() << endl << ve->getCoordinateYd() << endl << ve->getCoordinateZd() << endl << ve->getCoordinateWd() << endl;
	cout << v3->getValue(0)<< "  " << v3->getValue(1)<<"  " << v3->getValue(2) <<"  "<< v3->getValue(3)<<endl;
	return 0;
}