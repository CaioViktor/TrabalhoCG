#include "../lib/main.h"

int main (int argc, char *args[]){
    stackMatrix *s = new stackMatrix();
    Matrix *m;
    double a[4][4]={{4,0,8,1},{0,5,0,0},{0,0,6,7},{1,1,0,1}};
    Matrix *am = new Matrix(a);
    s->push(am);
    m = s->pull();
    m->printMatrix();
    m = s->pull();
    m->printMatrix();
}

