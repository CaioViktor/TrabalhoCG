class Face{

public:
	Face(Vertex *vertice1, Vertex *vertice2, Vertex *vertice3);

	void setVertice1(Vertex *vertice);
	Vertex* getVertice1();

	void setVertice2(Vertex *vertice);
	Vertex* getVertice2();

	void setVertice3(Vertex *vertice);
	Vertex* getVertice3();

//	void setNormal(Vector vnormal);
//	Vector* getNormal();

	void desenhar();

private:
	Vertex *vertice1;
	Vertex *vertice2;
	Vertex *vertice3;
//	Vector *normal;

};