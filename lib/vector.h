/* vector.h - Caio Viktor
*  classe responsável pela implementação de estrutura de vetores de coordenadas 4X1 
*/
class Vector{
	double **vector;
public:
	Vector();
	// Vector(Vertex*);
	double** getVector();
	double getValue(int);
	void setValue(int,double);
	void setValue(int,double*);
	void showVector();
	void multiplicationMatrix(Matrix*);
};