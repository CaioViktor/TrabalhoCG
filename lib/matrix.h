//Author: Matheus Mayron
#include "../lib/main.h"
class Matrix
{
    double **content;

public:

    Matrix(void);
    Matrix(double c[4][4]);

    static Matrix getIdentity(void);
    Matrix getTransposed(void);

    double **getContent(void);
    double getPosition(int,int);

    void setContent(double**);
    void setPosition(int,int,double);
    void printMatrix();

};


