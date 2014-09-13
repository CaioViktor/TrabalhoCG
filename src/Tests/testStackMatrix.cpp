#include "../../lib/main.h"

int main (int argc, char *args[]){
    stackMatrix *s = new stackMatrix();
    Matrix *m;
    double a[4][4]={{4,0,8,1},{0,5,0,0},{0,0,6,7},{1,1,0,1}};
    Matrix *am = new Matrix(a);
    double b[4][4]={{2,0,8,1},{0,3,0,0},{0,4,6,7},{1,1,6,1}};
    Matrix *bm = new Matrix(b);
    s->push(am);
    s->push(bm);
    am->printMatrix();
    bm->printMatrix();
    m = s->concatenate(s);
    m->printMatrix();
    // m = s->pull();
    // m->printMatrix();
    // m = s->pull();
    // m->printMatrix();
}

