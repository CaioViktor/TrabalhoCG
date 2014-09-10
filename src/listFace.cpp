/*	listFace.c - Caio Viktor
	implementa estrutura de lista encadeada de faces utilizada na classe objeto 
*/
#include "../lib/main.h"
//Construtor da classe ListFace. Inicia uma lista vazia
ListFace::ListFace(){
	this->first = NULL;
	this->last = NULL;
	cout << "Lista de Faces criada com sucesso" << endl;
}
//Construtor da classe ListFace, inicia a lista com uma face passado como parâmetro
ListFace::ListFace(Face *face){
	NodeFace *node = new NodeFace;
	node->face = face;
	node->next = NULL;
	this->first = node;
	this->last = node;
	cout << "Lista de Faces criada com sucesso" << endl;
}
//retorna true caso a lista esteja vazia e false caso o contrário
bool ListFace::isempty(){
	if(this->last == NULL)
		return true;
	else
		return false;
}
//adiciona uma face passado como parâmetro na ultima posição da lista caso ele ainda não exista na lista. caso ele já exista ele retorna uma mensagem informando
void ListFace::addFace(Face *face){
	NodeFace *node = new NodeFace;
	node->face = face;
	node->next = NULL;
	if(this->isempty()){
		this->first = node;
		this->last = node;
		cout << "Face adicionado com sucesso" << endl;
	}
	else{
		NodeFace *current = this->first;
		int elementsInList = 0;
		while(current != NULL){
			Face *currentFace = current->face;
			if(currentFace == face)
				elementsInList++;
			current = current->next;
		}
		if(elementsInList == 0){
			NodeFace *last = this->last;
			last->next = node;
			this->last = node;
			cout << "Face adicionado com sucesso" << endl;
		}
		else
			cout << "Face já existente" << endl;
	}
}
//Printa as coordenadas de todos os vértices da lista (Utilizada para teste). protótipo da função de transformação.
void ListFace::list(){
	NodeFace *current = this->first;
	while(current != NULL){
		Face *currentFace = current->face;
		currentFace->showVertexs();
		current = current->next;
	}
}
//Pinta todos as faces da lista em aramado
void ListFace::drawWired(){
	NodeFace *currentNode = this->first;
	while(currentNode != NULL){
		Face *current = currentNode->face;
		current->desenhar();
		currentNode = currentNode->next;
	}
	cout << "Face desenhada aramada\n";
}
//Pinta todos as faces da lista em sólido
void ListFace::drawSolid(){
	NodeFace *currentNode = this->first;
	while(currentNode != NULL){
		Face *current = currentNode->face;
		current->desenhar();
		currentNode = currentNode->next;
	}
	cout << "Face desenhada sólida\n";
}
//Retorna o número de faces existentes na lista
int ListFace::numberFaces(){
	NodeFace *currentNode = this->first;
	int number = 0;
	while(currentNode != NULL){
		Face *current = currentNode->face;
		number++;
		currentNode = currentNode->next;
	}
	return number;
}