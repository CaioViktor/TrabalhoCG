/**
*\file vertex.h
*\class Vertex
*\author Caio Viktor
*\brief Implementa a estrutra de vértice utilizada na construção de figuras geométricas pelo OpenGl
*/

class Vertex{
	double x,y,z,w;
public:
	/**
	*	Constrói um vértice na origem do sistema de coodenadas.
	*/
	Vertex();
	//~Vertex();

	/**
	*	Constrói um vértice nos pontos especificados pelos parâmetros.<BR>
	*	Apenas as três dimensões serão levadas em consideração a quarta coordenada será setada como 0.
	*	\param coordinateX Valor da coordenada X
	*	\param coordinateY Valor da coordenada Y
	*	\param coordinateZ Valor da coordenada Z
	*/
	Vertex(double coordinateX,double coordinateY,double coordinateZ);
	
	/**
	*	Constrói um vértice nos pontos especificados pelos parâmetros. É necessário que seja passada a quata coordena.
	*	\param coordinateX Valor da coordenada X
	*	\param coordinateY Valor da coordenada Y
	*	\param coordinateZ Valor da coordenada Z
	*	\param coordinateW Valor da coordenada W
	*/
	Vertex(double coordinateX,double coordinateY,double coordinateZ,double coordinateW);
	
	/**
	*	Atualiza a coordenada X.
	*	\param X Novo valor da coordenada X
	*/
	void setCoordinateX(double X);
	
	/**
	*	Atualiza a coordenada Y.
	*	\param Y Novo valor da coordenada Y
	*/
	void setCoordinateY(double Y);
	
	/**
	*	Atualiza a coordenada Z.
	*	\param Z Novo valor da coordenada Z
	*/
	void setCoordinateZ(double Z);
	
	/**
	*	Atualiza a coordenada W.
	*	\param W Novo valor da coordenada W
	*/
	void setCoordinateW(double W);
	

	/**
	*	Imprime as coordenadas do vértice.	
	*/
	void showVertex();
	

	/**
	*	\return	Valor da coordenada X no formato double.
	*/
	double getCoordinateXd();
	

	/**
	*	\return	Valor da coordenada Y no formato double.
	*/
	double getCoordinateYd();
	
	/**
	*	\return	Valor da coordenada Z no formato double.
	*/
	double getCoordinateZd();
	
	/**
	*	\return	Valor da coordenada W no formato double.
	*/
	double getCoordinateWd();
	
	/**
	*	\return	Valor da coordenada X no formato float.
	*/
	float getCoordinateXf();
	

	/**
	*	\return	Valor da coordenada Y no formato float
	*/
	float getCoordinateYf();
	
	/**
	*	\return	Valor da coordenada Z no formato float
	*/
	float getCoordinateZf();
	
	/**
	*	\return	Valor da coordenada W no formato float
	*/
	float getCoordinateWf();
	
	/**
	*	Retorna um objeto da classe Vector representando o vértice.
	*	\return	Ponteiro para um Vector representando as coordenadas do vértice.
	*/
	Vector* toVector();
	Vector* toVector3();
};