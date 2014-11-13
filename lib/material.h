//Autor: Matheus Mayron Vlw Flws


/*
	Informações Uteis:
	/*Ns = Phong specular component. Ranges from 0 to 1000. 
	Kd = Diffuse color weighted by the diffuse coefficient.
	Ka = Ambient color weighted by the ambient coefficient.
	Ks = Specular color weighted by the specular coefficient.
	d = Dissolve factor (pseudo-transparency). Values are from 0-1. 0 is completely transparent, 1 is opaque.
	Ni = Refraction index. Values range from 1 upwards. A value of 1 will cause no refraction. A higher value implies refraction.
*/

class Material{
	std::string name; 
	Vector* kd;
	Vector* ka;
	Vector* ks;
	double ns;
	double ni;
	double transparency;

public:
	Material();
	Material(std::string name, Vector* kd, Vector* ka, Vector* ks, double ns, double ni, double transparency);
	~Material();


	void setName(std::string name);
	std::string getName();

	Vector* getKd();
	void setKd(Vector* kd);
	void setKd_eachPosition(double r, double g, double b);

	Vector* getKa();
	void setKa(Vector* ka);
	void setKa_eachPosition(double r, double g, double b);

	Vector* getKs();
	void setKs(Vector* ks);
	void setKs_eachPosition(double r, double g, double b);

	double getNs();
	void setNs(double ns);

	double getNi();
	void setNs(double ni);

	double gettransparency();
	void setTransparency(double transparency);

	void showMaterialPropeties();
}