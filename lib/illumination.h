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
	void setLightAmbient(double red, double green, double blue);
	Vector* getLightAmbient();
	double getLightAmbient_Red();
	double getLightAmbient_Green();
	double getLightAmbient_Blue();


	void setLightIntesity(Vector* v);
	void setLightIntesity(double red, double green, double blue);
	Vector* getLightIntesity();
	double getLightIntesity_Red();
	double getLightIntesity_Green();
	double getLightIntesity_Blue();
};