typedef struct No_{
    Matrix *content;
    No_ *botton;

} NoStack;


class stackMatrix{
    int height;
    NoStack *top;

public:
    stackMatrix();
    ~stackMatrix();

    int getHeight();

    Matrix* pull();
    void push(Matrix* m);

};
