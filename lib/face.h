class Face{

public:
	Face();
	Face(Vertex *vertice1, Vertex *vertice2, Vertex *vertice3);

	void setVertice1(Vertex *vertice);
	Vertex* getVertice1();

	void setVertice2(Vertex *vertice);
	Vertex* getVertice2();

	void setVertice3(Vertex *vertice);
	Vertex* getVertice3();

	Vector* getNormal();

	void desenhar(void);
	void showVertexs();
private:
	Vertex *vertice1;
	Vertex *vertice2;
	Vertex *vertice3;
	Vector *normal;

};