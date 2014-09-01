class Face{
public:
	void setVertice1(Vertex *vertice){
		vertice1 = vertice;
	}

	Vertex* getVertice1(){
		return *vertice1;
	}

	void setVertice2(Vertex *vertice){
		vertice2 = vertice;
	}

	Vertex* getVertice2(){
		return *vertice2;
	}

	void setVertice3(Vertex *vertice){
		vertice3 = vertice;
	}

	Vertex* getVertice3(){
		return *vertice3;
	}	

	void setNormal(vetor vnormal){
		normal = vnormal;
	}

	normal getNormal(){
		return normal;
	}

	void desenhar(){
		
	}

private:
	Vertex *vertice1;
	Vertex *vertice2;
	Vertex *vertice3;
	vetor normal;

}