/* object.h - Cristiano Melo e Lucas Falc�o
*  Implemanta a estrutra de objeto
*/
class ObjectClass{
	string name;
	ListVertex *list ;
	Vertex *Centroid;
	
public:
	//Builders	
	ObjectClass();
	ObjectClass( string name, ListVertex list, Vertex Centroid );
	
	void setName( string Name );
	string getName();
	void setListVertex( ListVertex *list );
	ListVertex* getListVertex();
};
