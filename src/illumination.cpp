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

void Illumination::setLightPosition(double x, double y, double z){
	light_position->setValue(0,x);
	light_position->setValue(1,y);
	light_position->setValue(2,z);
}

Vector* Illumination::getLightPosition(){
	return this->light_position;
}

double Illumination::getLightPosition_X(){
	return light_position->getValue(0);
}

double Illumination::getLightPosition_Y(){
	return light_position->getValue(1);
}

double Illumination::getLightPosition_Z(){
	return light_position->getValue(2);
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
