/**
*\file objectClass.h
*\class ObjectClass
*\author Cristiano Melo & Lucas Falc�o & Caio Viktor
*\brief Implemanta a estrutra de objeto
*/

class ObjectClass{
	/**
	*	Nome do objeto
	*/
	std::string name; 

	/**
	*	Lista de v�rtices
	*/
	ListVertex *list_vertex ; 

	/**
	*	N�mero de v�rtices
	*/
	int number_vertex;

	/**
	*	Lista de faces
	*/
	ListFace *list_face; 

	/**
	*	N�mero de faces
	*/
	int number_face;


	/**
	*	Cor R
	*/
    float R;

	/**
	*	Cor G
	*/
    float G;

	/**
	*	Cor B
	*/
    float B;

	/**
	*	Centr�ide
	*/    
	Vector *centroid;
	
public:

	/**
	*	Constr�i o objeto
	*/
	ObjectClass();
	

	/**
	*	Desenha o objeto
	*	\param mode Constante que define o modo em que ser� desenhado. <br>
	*	GL_LINE_LOOP - Desenha face "aramada". <br>
	*	GL_POLYGON -   Desenha face preenchida.
	*/
	void drawObject( unsigned int mode );

	/**
	*	Aplica transformação no objeto
	*	\param transformationMatrix Matrix de transforma��o
	*/
	void applyTransformation( Matrix *transformationMatrix );

	/**
	*	Configura o nome do objeto
	*	\param list_face Novo nome do objeto
	*/
	void setName(std::string Name );

	/**
	*	Configura a lista de v�rtices do objeto
	*	\param list_vertex Nova lista de v�rtices
	*/
	void setListVertex( ListVertex *list_vertex );

	/**
	*	Configura a lista de faces do objeto
	*	\param list_face Nova lista de faces
	*/
	void setListFace( ListFace *list_face );

	/**
	*	Configura a cor R do objeto.
	*	\param R Valor na faixa de 0.0 a 1.0
	*/
	void setColorR( float R );

	/**
	*	Configura a cor G do objeto.
	*	\param G Valor na faixa de 0.0 a 1.0
	*/
	void setColorG( float G );

	/**
	*	Configura a cor B do objeto.
	*	\param B Valor na faixa de 0.0 a 1.0
	*/
	void setColorB( float B );

	/**
	*	\return	Nome do objeto.
	*/
	std::string getName();

	/**
	*	\return	Lista de vértices do objeto.
	*/
	ListVertex* getListVertex();

	/**
	*	\return	Lista de faces do objeto.
	*/
	ListFace* getListFace();

	/**
	*	\return	Cor R do objeto.
	*/
	float getCollorR();

	/**
	*	\return	Cor G do objeto.
	*/
	float getCollorG();

	/**
	*	\return	Cor B do objeto.
	*/
	float getCollorB();

	/**
	*	\return	O n�mero de v�rtices do Objeto.
	*/
	int getNumberVertex();

	/**
	*	\return	O n�mero de faces do Objeto.
	*/
	int getNumberFace();

	/**
	* 	Atualiza a centroide do objeto. <br>
	* 	A coordenada homog�nia est� sendo setada com 1.
	*/
	void updateCentroide();

	/**
	*	\return	Centr�ide do objeto.
	*/
	Vector* getCentroid();
};
