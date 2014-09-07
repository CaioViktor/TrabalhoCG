/* object.h - Cristiano Melo e Lucas Falcão
*  Implemanta a estrutra de objeto
*/
class ObjectClass{
	char* name;
	ListVertex *list ;
	Vertex *Centroid;
	
public:
	//Builders	
	ObjectClass();
	ObjectClass( char* name, ListVertex list, Vertex Centroid );
	
	void setName( char* Name );
	char* getName();
	void setListVertex( ListVertex *list );
	ListVertex* getListVertex();
};
