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
	Vector* getLightPosition();

	void setLightAmbient(Vector* v);
	Vector* getLightAmbient();

	void setLightIntesity(Vector* v);
	Vector* getLightIntesity();
};