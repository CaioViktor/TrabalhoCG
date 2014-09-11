#include "../lib/main.h"

void display(void){
	Vertex *vertice1 = new Vertex( (double) 0.7,(double) 0.7,(double) 0);
	Vertex *vertice2 = new Vertex( (double) 0.9,(double) 0.9,(double) 0);
	Vertex *vertice3 = new Vertex( (double) 0.8,(double) 0.8,(double) 0);

	Face *face1 = new Face(vertice1, vertice2, vertice3);

	Vertex *vertice4 = new Vertex( (double) 0.1,(double) 0.1,(double) 0);
	Vertex *vertice5 = new Vertex( (double) 0.2,(double) 0.2,(double) 0);
	Vertex *vertice6 = new Vertex( (double) 0.3,(double) 0.3,(double) 0);

	Face *face2 = new Face(vertice4, vertice5, vertice6);	

	cout<< "Face 1, Vertice 1 x: " << face1->getVertice1()->getCoordinateXd() << endl;
	cout<< "Face 2, Vertice 1 x: " << face2->getVertice1()->getCoordinateXd() << endl;

	face1->draw(GL_LINE_LOOP);	
	face2->draw(GL_POLYGON);

	glFlush();
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

    glClear (GL_COLOR_BUFFER_BIT);


    glutDisplayFunc(display);

    glutMainLoop();

}

