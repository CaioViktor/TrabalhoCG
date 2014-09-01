class Matrix
{
    double **conteudo;
public:
    Matrix(void);
    Matrix(double c[4][4]);

    static Matrix getIdentity(void);
    Matrix getTransposed(void);

    double** getConteudo(void);
    double getPosition(int,int);

    void setConteudo(double**);
    void setPosition(int,int,double);
    void printMatrix();

};
