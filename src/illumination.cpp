/**
*\author Matheus Mayron
*/
#include "../lib/main.h"


Illumination::Illumination(){
	this->light_position = NULL;
	this->light_ambiente = NULL;
	this->light_intensity = NULL;
}
Illumination::Illumination(Vector* light_position, Vector* light_ambiente, Vector* light_intensity){
	this->light_position = light_position;
	this->light_ambiente = light_ambiente;
	this->light_intensity = light_intensity;
}


void Illumination::setLightPosition(Vector* v){
	this->light_position = v;
}
Vector* Illumination::getLightPosition(){
	return this->light_position;
}


void Illumination::setLightAmbient(Vector* v){
	this->light_ambiente = v;
}
Vector* Illumination::getLightAmbient(){
	return this->light_ambiente;
}


void Illumination::setLightIntesity(Vector* v){
	this->light_intensity = v;
}
Vector* Illumination::getLightIntesity(){
	return this->light_intensity;
}
