/**
*\author Matheus Mayron
*/
class Illumination{
	Vector* light_position;
	Vector* light_ambiente;
	Vector* light_intensity;
	
public:
	Illumination();
	Illumination(Vector* light_position,Vector* light_ambiente, Vector* light_intensity);

	void setLightPosition(Vector* V);
	void setLightPosition(double x, double y, double z);
	Vector* getLightPosition();
	double getLightPosition_X();
	double getLightPosition_Y();
	double getLightPosition_Z();

	void setLightAmbient(Vector* v);
	Vector* getLightAmbient();


	void setLightIntesity(Vector* v);
	Vector* getLightIntesity();
};