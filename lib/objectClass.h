/**
*\file objectClass.h
*\class ObjectClass
*\author Cristiano Melo & Lucas Falcão & Caio Viktor
*\brief Implemanta a estrutra de objeto
*/

class ObjectClass{
	/**
	*	Nome do objeto
	*/
	std::string name; 

	/**
	*	Lista de vértices
	*/
	ListVertex *list_vertex ; 

	/**
	*	Número de vértices
	*/
	int number_vertex;

	/**
	*	Lista de faces
	*/
	ListFace *list_face; 

	/**
	*	Número de faces
	*/
	int number_face;


	/**
	*	Cor Red
	*/
    float R;

	/**
	*	Cor Green
	*/
    float G;

	/**
	*	Cor Blue
	*/
    float B;

	/**
	*	Centróide
	*/    
	Vector *centroid;
	
public:

	/**
	*	Constrói o objeto
	*/
	ObjectClass();
	

	/**
	*	Desenha o objeto
	*	\param mode Constante que define o modo em que será desenhado. <br>
	*	GL_LINE_LOOP - Desenha face "aramada". <br>
	*	GL_POLYGON -   Desenha face preenchida.
	*/
	void drawObject(unsigned int mode, Matrix* viewProjection, Illumination *illumination, Vector* camPosition);

	/**
	*	Aplica transformações no objeto
	*	\param transformationMatrix Matrix de transformação
	*/
	void applyTransformation( Matrix *transformationMatrix );

	/**
	*	Configura o nome do objeto
	*	\param Name Novo nome do objeto
	*/
	void setName(std::string Name );

	/**
	*	Configura a lista de vértices do objeto
	*	\param list_vertex Nova lista de vértices
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
	*	\return	Lista de vÃ©rtices do objeto.
	*/
	ListVertex* getListVertex();

	/**
	*	\return	Lista de faces do objeto.
	*/
	ListFace* getListFace();

	/**
	*	\return	Cor Red do objeto.
	*/
	float getCollorR();

	/**
	*	\return	Cor Green do objeto.
	*/
	float getCollorG();

	/**
	*	\return	Cor Blue do objeto.
	*/
	float getCollorB();

	/**
	*	\return	O número de vértices do Objeto.
	*/
	int getNumberVertex();

	/**
	*	\return	O número de faces do Objeto.
	*/
	int getNumberFace();

	/**
	* 	Atualiza a centroide do objeto. <br>
	* 	A coordenada homogênia está sendo setada com 1.
	*/
	void updateCentroide();

	/**
	*	\return	Centróide do objeto.
	*/
	Vector* getCentroid();
};
