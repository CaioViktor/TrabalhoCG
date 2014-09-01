#include "../lib/main.h"
int main(){
	Vector *v = new Vector();
	double *d = (double *)malloc(sizeof(double));
	*d = 8;
	cout << *d<<endl;
	cout << v->vector[0]<<endl;
	v->vector[0] = d;
	cout << v->vector[1]<<endl;
	cout << v->vector[2]<<endl;
	cout << v->vector[3]<<endl;
	*v->vector[0] = *v->vector[0] + 2;
	cout << *v->vector[0]<<endl;
	cout << *d<<endl;
	return 0;
}