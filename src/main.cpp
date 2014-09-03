#include "../lib/main.h"
GLfloat eyex,eyey,eyez,centrox, centroy, centroz;

void draw(void) {

    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //Draw i
    gluLookAt (eyex, eyey, eyez, centrox, centroy, centroz, 0.0, 1.0, 0.0);
    // Define a cor padrão como verde
    glColor3f (0.2, 1.0, 0.2);

    glBegin(GL_LINE_LOOP);
        glVertex3d(2.654285, 1.007973, 0.225403);
        glVertex3d(2.654285, 1.007973, -1.774597);
        glVertex3d(2.654285, -0.992027, -1.774597);
        glVertex3d(2.654285, -0.992027, 0.225403);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3d(2.654285, 1.007973, -1.774597);
        glVertex3d(4.654285, 1.007973, -1.774597);
        glVertex3d(4.654285, -0.992027, -1.774597);
        glVertex3d(2.654285, -0.992027, -1.774597);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3d(4.654285, 1.007973, -1.774597);
        glVertex3d(4.654285, 1.007973, 0.225403);
        glVertex3d(4.654285, -0.992027, 0.225403);
        glVertex3d(4.654285, -0.992027, -1.774597);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3d(4.654285, 1.007973, 0.225403);
        glVertex3d(2.654285, 1.007973, 0.225403);
        glVertex3d(2.654285, -0.992027, 0.225403);
        glVertex3d(4.654285, -0.992027, 0.225403);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3d(2.654285, -0.992027, 0.225403);
        glVertex3d(2.654285, -0.992027, -1.774597);
        glVertex3d(4.654285, -0.992027, -1.774597);
        glVertex3d(4.654285, -0.992027, 0.225403);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3d(4.654285, 1.007973, 0.225403);
        glVertex3d(4.654285, 1.007973, -1.774597);
        glVertex3d(2.654285, 1.007973, -1.774597);
        glVertex3d(2.654285, 1.007973, 0.225403);
    glEnd();

    glFlush();

}

void init (void)
{
    /* Seleciona a cor de fundo para limpeza da tela */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
    eyex = 0.0;
    eyey = 0.0;
    eyez = 5.0;
    centrox=0.0;
    centroy=0.0;
    centroz=0.0;

    /* inicializa os valores de visualização */
    glMatrixMode(GL_PROJECTION);
    /* Faz com que a matriz corrente seja inicializada com a matriz identidade
    (nenhuma transformação é acumulada)
    */
    glLoadIdentity();
    //glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
}

//Main program

int main(int argc, char **argv) {

    glutInit(&argc, argv);

    /*Setting up  The Display
    /    -RGB color model + Alpha Channel = GLUT_RGBA
    */
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);

    //Configure Window Postion
    glutInitWindowPosition(50, 25);

    //Configure Window Size
    glutInitWindowSize(1000,1000);

    //Create Window
    glutCreateWindow("CG");

    init();
    glutReshapeFunc(reshape);

    //Call to the drawing function
    glutDisplayFunc(draw);

    // Loop require by OpenGL
    glutMainLoop();
    return 0;
}