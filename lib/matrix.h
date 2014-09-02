//Author: Matheus Mayron
class Matrix
{
    double **content;

public:

    Matrix();
    Matrix(double array2d[4][4]);

    ~Matrix();

    double **getContent();
    double getPosition(int lin, int col);

    static Matrix getIdentity();
    Matrix getTransposed();
    Matrix multiplyMatrix(Matrix B);

    void setContent(double **c);
    void setPosition(int lin, int col, double value);
    void printMatrix();

};


