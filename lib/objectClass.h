/* object.h - Cristiano Melo e Lucas Falcão
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
