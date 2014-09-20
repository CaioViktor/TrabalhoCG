/**
*\file stackMatrix.h
*\class stackMatrix
*\author Matheus Mayron
*\brief Armazenar matrizes e facilitar as operações feitas com matrizes.
*/

/** 
*\brief Um nó da pilha.
*/
typedef struct No_{
    Matrix *content;  ///< Ponteiro para um objeto do tipo Matrix armazenado pelo nó.  
    No_ *botton;      ///< Ponteiro para o elemento inferior a ele na pilha.
} NoStack;


class stackMatrix{
    //!Guarda o tamanho da pilha. Valor inicial é 0.
    int height;
    //!Ponteiro para o nó do topo da pilha.
    NoStack *top;

public:
    /**
    *   Controi uma objeto staticMatrix. O valor inicial de height é 0 e top aponta para a base da pilha: um NoStack contendo uma matriz identidade.
    */
    stackMatrix();

    /**
    *   Destroi o objeto, desalocando também o que foi alocado em seu interior
    */
    ~stackMatrix();

    /**
    *   \return A altura da pilha.
    */
    int getHeight();

    /**
    *   Retira o topo da pilha e desincrementa o tamanho da pilha.<BR>
    *   Caso a pilha esteja vazia, uma mensagem de erro será mostrada e o retorno será uma matriz identidade.
    *   \result Ponteiro para o objeto Matrix que estava sendo referênciada pelo NoStack que estava no topo da pilha.
    */
    Matrix* pull();

    /**
    *   Empilha um objeto NoStack na pilha. Esse NoStack irá referênciar um objeto Matrix passado como parâmentro.<BR>
    *   Incrementa o tamanho da pilha.        
    *   \param matrix Um objeto do tipo matrix que será referênciado pelo NoStack que será empilhado.
    */
    void push(Matrix* matrix);

    /**
    *   Multiplica todas as matrizes armazenadas na pilha passada como parametro do topo até a base e retorna o resultado.
    *   \param stack Um ponteiro para um objeto do tipo stackMatrix.
    *   \result Resultado da multiplicação.
    */
    static Matrix* concatenate(stackMatrix* stack);
};
