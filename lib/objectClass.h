/* object.h - Cristiano Melo e Lucas Falcão
*  Implemanta a estrutra de objeto
*/
class ObjectClass{
	std::string name;
	ListVertex *list ;
	Vertex *Centroid;
	
public:
	//Builders	
	ObjectClass();
	ObjectClass(std::string name, ListVertex *list );
	ObjectClass(std::string name, ListVertex list, Vertex Centroid );
	
	void setName(std::string Name );
	std::string getName();
	void setListVertex( ListVertex *list );
	ListVertex* getListVertex();
};
