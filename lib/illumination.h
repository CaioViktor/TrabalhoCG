/**
*\author Matheus Mayron
*/
class Illumination{
	Vertex* light_position;
	Vector* ligt_ambiente;
	Vector* light_difuse;
	Vector* light_specular;
	
public:
	Illumination();
	Illumination(Vertex* light_position,Vector* ligt_ambiente, Vector* light_difuse, Vector* light_specular);

	void setLightPosition(Vertex* V);
	Vertex* getLightPosition();

	void setLightAmbient(Vector* v);
	Vector* getLightAmbient();

	void setLightDifuse(Vector* v);
	Vector* getLightDifuse();

	void setLightSpecular(Vector* v);
	Vector* getLightSpecular();
};