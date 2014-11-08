#include "../lib/main.h"

stackMatrix::stackMatrix(){
     NoStack* no;
     Matrix* m;

     no = new NoStack;
     m = Matrix::getIdentity();

     no->content = m;
     no->botton = NULL;

     this->height = 0;
     this->top = no;
}

stackMatrix::~stackMatrix(){

    while(height >= 0){
        NoStack *aux = this->top;
        this->top = aux->botton;
        delete aux;
        height--;
    }
}


int stackMatrix::getHeight(){
    return height;
}

Matrix* stackMatrix::pull(){
    Matrix* result;
    if(height == 0){
        cout<<"\nWarning: Underflow";
        result = top->content;
    }
    else{
        height = height - 1;
        result = top->content;
        top = top->botton;
    }
    return result;
}


void stackMatrix::push(Matrix *m){
    NoStack *newTop = new NoStack;
    newTop->content = m;
    newTop->botton = top;
    top = newTop;
    height = height+1;
}

/*Autor:Caio Viktor
    método estático que recebe uma pilha de matrizes e faz a concatenação das mesmas
*/
Matrix* stackMatrix::concatenate(stackMatrix* s){
    Matrix *concatenated = Matrix::getIdentity();
    while(s->getHeight() > 0){
        concatenated = concatenated->multiplyMatrix(s->pull());
    }
    return concatenated;
}