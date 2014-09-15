/* object.h - Cristiano Melo e Lucas Falcão
*  Implemanta a estrutra de objeto
*/

class ObjectClass{
    //Nome do objeto
	std::string name; 
	//Lista de Vertice
	ListVertex *list_vertex ; 
	//Numero de Vertices
	int number_vertex;
	//Lista de Face
	ListFace *list_face; 
	//Numero de Faces
	int number_face;
	//Cores:
    float R;
    float G;
    float B;
    
	//Vertex *Centroid;
	Vector *centroid;
	
public:
	//Builder	
	ObjectClass();
	
	
	void drawObject( unsigned int mode );
	void applyTransformation( Matrix *transformationMatrix );
	void setName(std::string Name );
	void setListVertex( ListVertex *list_vertex );
	void setListFace( ListFace *list_face );
	void setColorR( float R );
	void setColorG( float G );
	void setColorB( float B );
	std::string getName();
	ListVertex* getListVertex();
	ListFace* getListFace();
	float getCollorR();
	float getCollorG();
	float getCollorB();
	int getNumberVertex();
	int getNumberFace();
	void updateCentroide();
	Vector* getCentroid();
};