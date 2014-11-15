/**
*\author Matheus Mayron
*/

#include "../lib/main.h"

ListMaterial::ListMaterial(){
	this->first = NULL;
	this->last = NULL;
	this->size = 0;
}

ListMaterial::~ListMaterial(){}

void ListMaterial::addMaterial(Material* material){
	NodeMaterial *newNodeMaterial = new NodeMaterial;
	newNodeMaterial->material = material;
	newNodeMaterial->next = NULL;

	if(this->isEmpty()){
		this->first = newNodeMaterial;
		this->last = newNodeMaterial;
		this->size++;
	}
	else{
		this->last->next=newNodeMaterial;
		this->last=newNodeMaterial;
		this->size++;
	}
}

Material* ListMaterial::getMaterial(std::string materialName){
	NodeMaterial* anteriorNode = NULL;
	NodeMaterial* currentNode = this->first;
	bool found = false;

	while(currentNode!=NULL && !found){
		if(materialName.compare(currentNode->material->getName()) == 0){
			found = true;
		}

		else{
			anteriorNode = currentNode;
			currentNode = currentNode->next;
		}
	}

	if(!found){
		return NULL;
	}
	else{
		this->size--;
		if(this->first == currentNode){
			this->first=currentNode->next;
		}
		else if(this->last == currentNode){
			this->last == anteriorNode;
		}
		else{
			anteriorNode = currentNode->next;
		}
	}

}

bool ListMaterial::isEmpty(){
	if(this->last == NULL){
		return true;
	}
	else{
		return false;
	}
}

int ListMaterial::getSize(){
	return this->size;
}