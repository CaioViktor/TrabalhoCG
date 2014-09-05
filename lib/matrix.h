//Author: Matheus Mayron
class Matrix
{
    double **content;

public:

    //Construtores e Destrutores.
    Matrix();
    Matrix(double array2d[4][4]);
    ~Matrix();

    //getters e setters.
    double **getContent();
    double getPosition(int lin, int col);

    void setContent(double **c);
    void setPosition(int lin, int col, double value);

    //Utilitarias.
    static Matrix* getIdentity();
    Matrix* getTransposed();
    Matrix* multiplyMatrix(Matrix* B);
    void printMatrix();


    //Transformações
    static Matrix* getTranslation(double x, double y, double z);
    static Matrix* getRotationX(double angle);
    static Matrix* getRotationY(double angle);
    static Matrix* getRotationZ(double angle);
    static Matrix* getScale(double dx, double dy, double dz, double xf, double yf, double zf);

};


