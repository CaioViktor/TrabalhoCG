//Autor: Matheus Mayron Vlw Flws

#include "../lib/main.h"

/*
	Informações Uteis:
	/*Ns = Phong specular component. Ranges from 0 to 1000. 
	Kd = Diffuse color weighted by the diffuse coefficient.
	Ka = Ambient color weighted by the ambient coefficient.
	Ks = Specular color weighted by the specular coefficient.
	d = Dissolve factor (pseudo-transparency). Values are from 0-1. 0 is completely transparent, 1 is opaque.
	Ni = Refraction index. Values range from 1 upwards. A value of 1 will cause no refraction. A higher value implies refraction.
*/


Material::Material(){
	this->name = "";
	this->kd = NULL;
	this->ka = NULL;
	this->ks = NULL;
	this->ns = 0;
	this->ni = 0;
	this->transparency = 0; 
}


Material::Material(std::string name, Vector* kd, Vector* ka, Vector* ks, double ns, double ni, double transparency){
	this->name = name;
	this->kd = kd;
	this->ka = ka;
	this->ks = ks;
	this->ns = ns;
	this->ni = ni;
	this->transparency = transparency;
}

//TODO
Material::~Material(){}


void Material::setName(std::string name){
	this->name = name;
}
std::string Material::getName(){
	return this->name;
}


Vector* Material::getKd(){
	return this->kd.
}
void Material::setKd(Vector* kd){
	this->kd=kd;
}
void Material::setKd_eachPosition(double r, double g, double b){
	kd->setPosition(0,r);
	kd->setPosition(1,g);
	kd->setPosition(2,b);
}


Vector* Material::getKa(){
	return this->ka;
}
void Material::setKa(Vector* ka){
	this->ka=ka;
}
void Material::setKa_eachPosition(double r, double g, double b){
	ka->setPosition(0,r);
	ka->setPosition(1,g);
	ka->setPosition(2,b);
}


Vector* Material::getKs(){
	return this->ks;
}
void Material::setKs(Vector* ks){
	this->ks=ks;
}
void Material::setKs_eachPosition(double r, double g, double b){
	ks->setPosition(0,r);
	ks->setPosition(1,g);
	ks->setPosition(2,b);
}


double Material::getNs(){
	return this->ns;
}
void Material::setNs(double ns){
	this->ns = ns;
}


double Material::getNi(){
	return this->ni
}
void Material::setNi(double ni){
	this->ni=ni;
}

double Material::gettransparency(){
	return this->transparency;
}
void Material::setTransparency(double transparency){
	this->transparency = transparency;
}


void Material::showMaterialPropeties(){
	cout << "Valores em kd: " <<endl;
	this->kd->showVector();
	cout << "Valores em ka: " <<endl;
	this->ka->showVector();
	cout << "Valores em ks: " <<endl;
	this->ks->showVector();

	cout << "Valor de ns: " << this->ns <<endl;
	cout << "Valor de ni: " << this->ni <<endl;
	cout << "Valor de transparency: " << this->transparency << endl;

}


