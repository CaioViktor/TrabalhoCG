#include "../lib/main.h"
GLfloat eyex,eyey,eyez,centrox, centroy, centroz;

void draw(void) {

    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // carrega matriz identidade para não acumular transformações na câmera
    glLoadIdentity();
    // posiciona câmera
    gluLookAt (eyex, eyey, eyez, centrox, centroy, centroz, 0.0, 1.0, 0.0);
    //Draw i
    // Define a cor padrão como verde
    glColor3f (0.5, 0.0, 0.);

    glBegin(GL_LINE_LOOP);
        glVertex3d( 1.007973, 0.225403,2.654285);
        glVertex3d( 1.007973, -1.774597,2.654285);
        glVertex3d( -0.992027, -1.774597,2.654285);
        glVertex3d( -0.992027, 0.225403,2.654285);
    glEnd();

    glColor3f (0.0, 0.5, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3d( 1.007973, -1.774597,2.654285);
        glVertex3d( 1.007973, -1.774597,4.654285);
        glVertex3d( -0.992027, -1.774597,4.654285);
        glVertex3d( -0.992027, -1.774597,2.654285);
    glEnd();

    glColor3f (0.0, 0.0, 0.5);
    glBegin(GL_LINE_LOOP);
        glVertex3d( 1.007973, -1.774597,4.654285);
        glVertex3d( 1.007973, 0.225403,4.654285);
        glVertex3d( -0.992027, 0.225403,4.654285);
        glVertex3d( -0.992027, -1.774597,4.654285);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3d( 1.007973, 0.225403,4.654285);
        glVertex3d( 1.007973, 0.225403,2.654285);
        glVertex3d( -0.992027, 0.225403,2.654285);
        glVertex3d( -0.992027, 0.225403,4.654285);
    glEnd();

    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3d( -0.992027, 0.225403,2.654285);
        glVertex3d( -0.992027, -1.774597,2.654285);
        glVertex3d( -0.992027, -1.774597,4.654285);
        glVertex3d( -0.992027, 0.225403,4.654285);
    glEnd();

    glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex3d( 1.007973, 0.225403,4.654285);
        glVertex3d( 1.007973, -1.774597,4.654285);
        glVertex3d( 1.007973, -1.774597,2.654285);
        glVertex3d( 1.007973, 0.225403,2.654285);
    glEnd();

    glFlush();
    cout << "Display!" << endl;
}

void init (void)
{
    /* Seleciona a cor de fundo para limpeza da tela */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
    //eixo x horizontal
    eyex = 0.0;
    //eixo y vertical
    eyey = 0.0;
    //eixo z perpendicular cresce para fora se valor for alto pode sair do volume de projeção
    eyez = 10.0;
    //origem de referencial da câmera (0,0,0 é a origem do global)
    centrox=0.0;
    centroy=0.0;
    centroz=0.0;

    /* inicializa os valores de visualização */
    glMatrixMode(GL_PROJECTION);
    /* Faz com que a matriz corrente seja inicializada com a matriz identidade
    (nenhuma transformação é acumulada)
    */
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void reshape (int w, int h)
{   
    cout << "Reshape!\n";
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 50.0);
    //glFrustum (-1.0, 1.0:são o volume dos lados, -1.0, 1.0:são o volume da altura, 1.0 : proximidade da câmera, 50.0:volume de profundidade);
    glMatrixMode (GL_MODELVIEW);
}
void input(unsigned char tecla, int x, int y)
{
    // deveria ser assim, mas pelo modelo do blender não
    // switch (tecla) {
    //     case 'w':
    //         eyex = eyex + 0.5;
    //         break;
    //     case 's':
    //         eyex = eyex - 0.5;
    //         break;
    //     case 'd':
    //         eyey = eyey + 0.5;
    //         break;
    //     case 'a':
    //         eyey = eyey - 0.5;
    //         break;
    //     case 'e':
    //         eyez = eyez + 0.5;
    //         break;
    //     case 'q':
    //         eyez = eyez - 0.5;
    //         break;
    //     case 'O':
    //     case 'o':
    //         eyex = 0.0;
    //         eyey = 0.0;
    //         eyez = 5.0;
    //         centrox=0.0;
    //         centroy=0.0;
    //         centroz=0.0;
    //     break;
    
    // }
    // Não sei o motivo de ter que ser assim, mesmo convertendo coordenadas do blender continau desta maneira louca
    switch (tecla) {
        case 'd':
            eyex = eyex + 0.5;
            break;
        case 'a':
            eyex = eyex - 0.5;
            break;
        case 'e':
            eyey = eyey + 0.5;
            break;
        case 'q':
            eyey = eyey - 0.5;
            break;
        case 's':
            eyez = eyez + 0.5;
            break;
        case 'w':
            eyez = eyez - 0.5;
            break;
        case 'O':
        case 'o':
            eyex = 0.0;
            eyey = 0.0;
            eyez = 10.0;
            centrox=0.0;
            centroy=0.0;
            centroz=0.0;
        break;    
    }
    cout << "teclou\n";
    glutPostRedisplay();
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

    glutKeyboardFunc(input);
    init();
    glutReshapeFunc(reshape);
    //Call to the drawing function
    glutDisplayFunc(draw);
    // Loop require by OpenGL
    glutMainLoop();
    return 0;
}