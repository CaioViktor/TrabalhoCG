/**
*\file face.h
*\class Face
*\author Geraldo Braz Duarte Filho & Caio Viktor
*\brief Implementação da estrutura de face
*/

class Face{

public:
	/**
	*	Constrói face de vértices nulos.
	*/
	Face();

	/**
	*	Constrói face de 3 vértices.
	*	\param vertice1 Vértice 1 da face
	*	\param vertice2 Vértice 2 da face
	*	\param vertice3 Vértice 3 da face
	*/
	Face(Vertex *vertice1, Vertex *vertice2, Vertex *vertice3);

	/**
	*	Desenha a face.
	*	\param mode Constante que define o modo em que será desenhado. <br>
	*	GL_LINE_LOOP - Desenha face "aramada". <br>
	*	GL_POLYGON -   Desenha face preenchida.
	*/
	void draw(unsigned int mode,Matrix* viewProjection,bool opengl);

	/**
	*Imprime os vértices da face.
	*/
	void showVertexs();

	/**
	*	Atualiza o vértice 1 da face.
	*	\param vertice Novo vértice 1 da face
	*/
	void setVertice1(Vertex *vertice);

	/**
	*	Atualiza o vértice 2 da face.
	*	\param vertice Novo vértice 2 da face
	*/
	void setVertice2(Vertex *vertice);

	/**
	*	Atualiza o vértice 3 da face.
	*	\param vertice Novo vértice 3 da face
	*/
	void setVertice3(Vertex *vertice);

	/**
	*	\return	Vértice 1 da face.
	*/
	Vertex* getVertice1();

	/**
	*	\return	Vértice 2 da face.
	*/
	Vertex* getVertice2();

	/**
	*	\return	Vértice 3 da face.
	*/
	Vertex* getVertice3();

	/**
	*	\return	Normal da face.
	*/
	Vector* getNormal();

private:
	/**
	*	Vértice 1
	*/
	Vertex *vertice1;

	/**
	*	Vértice 2
	*/
	Vertex *vertice2;

	/**
	*	Vértice 2
	*/
	Vertex *vertice3;

	/**
	*	Normal
	*/
	Vector *normal;

};
