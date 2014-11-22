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

void Illumination::setLightAmbient(double red, double green, double blue){
	light_ambiente->setValue(0, red);
	light_ambiente->setValue(1, green);
	light_ambiente->setValue(2, blue);
}

Vector* Illumination::getLightAmbient(){
	return this->light_ambiente;
}

double Illumination::getLightAmbient_Red(){
	return light_ambiente->getValue(0);
}

double Illumination::getLightAmbient_Green(){
	return light_ambiente->getValue(1);
}

double Illumination::getLightAmbient_Blue(){
	return light_ambiente->getValue(2);
}

void Illumination::setLightIntesity(Vector* v){
	this->light_intensity = v;
}

void Illumination::setLightIntesity(double red, double green, double blue){
	light_intensity->setValue(0, red);
	light_intensity->setValue(1, green);
	light_intensity->setValue(2, blue);
}


Vector* Illumination::getLightIntesity(){
	return this->light_intensity;
}

double Illumination::getLightIntesity_Red(){
	return light_intensity->getValue(0);
}

double Illumination::getLightIntesity_Green(){
	return light_intensity->getValue(1);
}

double Illumination::getLightIntesity_Blue(){
	return light_intensity->getValue(2);
}
