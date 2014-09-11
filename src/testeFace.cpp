#include "../lib/main.h"

void display(void){
	Vertex *vertice1 = new Vertex( (double) 0.7,(double) 0.7,(double) 0);
	Vertex *vertice2 = new Vertex( (double) 0.2,(double) 0.2,(double) 0);
	Vertex *vertice3 = new Vertex( (double) 0.3,(double) 0.3,(double) 0);

	Face *face1 = new Face(vertice1, vertice2, vertice3);

	Vertex *vet = face1->getVertice1();

	cout<< "Vertice 1 x: " << vet->getCoordinateXd() << endl;

	face1->desenhar();	
}

int main(int argc, char **argv){

	double sizeX = 400;
    double sizeY = 400;
    
	glutInit(&argc, argv);

  
    
    /*Configura a tela
    /    -RGB color model + Alpha Channel = GLUT_RGBA
    */
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);

    //Configura a posição da janela
    glutInitWindowPosition(0, 0);

    //Configura o tamanho da janela
    glutInitWindowSize(sizeX,sizeY);

    //Criação da janela
    glutCreateWindow("Imperio Britanico");

    glClearColor (0.0, 0.0, 0.0, 0.0);
/* inicializa os valores de visualização */
	glMatrixMode(GL_PROJECTION);

/*	    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // carrega matriz identidade para não acumular transformações na câmera
    glLoadIdentity();
    // posiciona câmera
    gluLookAt (eyex, eyey, eyez, centrox, centroy, centroz, 0.0, 1.0, 0.0);
    //Draw i
    // Define a cor padrão como verde
    glColor3f (0.5, 0.0, 0.);
*/	
    glClear (GL_COLOR_BUFFER_BIT);



    glutDisplayFunc(display);

    glutMainLoop();

}

