/* vertex.h - Caio Viktor
*  Implemanta a estrutra de vértice utilizada na construção de figuras geométricas pelo OpenGl
*/
class Vertex{
	double x,y,z,w;
public:
	Vertex();
	//~Vertex();
	Vertex(double coordinateX,double coordinateY,double coordinateZ);
	Vertex(double coordinateX,double coordinateY,double coordinateZ,double coordinateW);
	void setCoordinateX(double X);
	void setCoordinateY(double Y);
	void setCoordinateZ(double Z);
	void setCoordinateW(double W);
	double getCoordinateXd();
	double getCoordinateYd();
	double getCoordinateZd();
	double getCoordinateWd();
	float getCoordinateXf();
	float getCoordinateYf();
	float getCoordinateZf();
	float getCoordinateWf();
	Vector* toVector();
};