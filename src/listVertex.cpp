/*	listVertex.c - Caio Viktor
	implementa estrutura de lista encadeada de vertices utilizada na classe objeto 
*/
#include "../lib/main.h"
//Construtor da classe ListVertex. Inicia uma lista vazia
ListVertex::ListVertex(){
	this->first = NULL;
	this->last = NULL;
	cout << "Lista de Vertices criada com sucesso" << endl;
}
//Construtor da classe ListVertex, inicia a lista com um vertice passado como parâmetro
ListVertex::ListVertex(Vertex *vertex){
	Node *node = (Node *) malloc(sizeof(Node));
	node->vertex = vertex;
	node->next = NULL;
	this->first = node;
	this->last = node;
	cout << "Lista de Vertices criada com sucesso" << endl;
}
//retorna true caso a lista esteja vazia e false caso o contrário
bool ListVertex::isempty(){
	if(this->last == NULL)
		return true;
	else
		return false;
}
//adiciona um vertice passado como parâmetro na ultima posição da lista caso ele ainda não exista na lista. caso ele já exista ele retorna uma mensagem informando
void ListVertex::addVertex(Vertex *vertex){
	Node *node = (Node *) malloc(sizeof(Node));
	node->vertex = vertex;
	node->next = NULL;
	if(this->isempty()){
		this->first = node;
		this->last = node;
		cout << "Vertice adicionado com sucesso" << endl;
	}
	else{
		Node *current = this->first;
		int elementsInList = 0;
		while(current != NULL){
			Vertex *currentVertex = current->vertex;
			if(currentVertex == vertex)
				elementsInList++;
			current = current->next;
		}
		if(elementsInList == 0){
			Node *last = this->last;
			last->next = node;
			this->last = node;
			cout << "Vertice adicionado com sucesso" << endl;
		}
		else
			cout << "Vertice já existente" << endl;
	}
}
//Printa as coordenadas de todos os vértices da lista (Utilizada para teste). protótipo da função de transformação.
void ListVertex::list(){
	Node *current = this->first;
	while(current != NULL){
		Vertex *currentVertex = current->vertex;
		cout << currentVertex->getCoordinateXd() << "  " <<currentVertex->getCoordinateYd() << "  " << currentVertex->getCoordinateZd() << "  " <<currentVertex->getCoordinateWd() <<endl;
		current = current->next;
	}
}
//Aplica uma transformação em todos os vértices da lista
void ListVertex::transformation(Matrix *matrix){
	Node *currentNode = this->first;
	while(currentNode != NULL){
		Vertex *current = currentNode->vertex;
		Vector *currentVector = current->toVector();
		currentVector->multiplicationMatrix(matrix);
		currentNode = currentNode->next;
	}
	cout << "Transformação aplicada com sucesso sobre a lista de vertices\n";
}