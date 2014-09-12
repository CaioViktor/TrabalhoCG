/* main.cpp - Caio Viktor
Controle da window, inteface de usuário e chamadas de procedimentos
*/
#include "../lib/main.h"
GLfloat eyex,eyey,eyez,centrox, centroy, centroz;
int sizeX,sizeY;
int mainWindow;
GLUI *glui;

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

void init (void){
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

void reshape (int w, int h){   
    cout << "Reshape!\n";
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 50.0);
    //glFrustum (-1.0, 1.0:são o volume dos lados, -1.0, 1.0:são o volume da altura, 1.0 : proximidade da câmera, 50.0:volume de profundidade);
    glMatrixMode (GL_MODELVIEW);
}

void input(unsigned char tecla, int x, int y){
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

//callbacks GLUI interface
void render(){
    glutSetWindow(mainWindow);
    glutPostRedisplay();
}

//Seleção de objetos
GLUI_StaticText *textName, *textPosition, *textFace, *textVertex;
int objSelected;
string objectName = "NULL",objectPosition = "X:0;Y:0;Z:0", objectFaces = "0",objectVertex = "0";
void selectObject(){
    objectName = "oi";
    cout << objSelected << endl;
    //TODO: tratamento de informações
    textName->set_text(objectName.c_str());
    textPosition->set_text(objectPosition.c_str());
    textFace->set_text(objectFaces.c_str());
    textVertex->set_text(objectVertex.c_str());
}

//Seleção de tranformação
int transformationSelected,opRotation;
GLUI_Spinner *coordinateX,*coordinateY,*coordinateZ,*radians,*scaleX,*scaleY,*scaleZ;
GLUI_RadioGroup *group3;
void selectTransformation(){
    switch(transformationSelected){
        //Translação
        case 0:
            coordinateX->enable();
            coordinateY->enable();
            coordinateZ->enable();

            group3->disable();
            radians->disable();

            scaleX->disable();
            scaleY->disable();
            scaleZ->disable();
            break;
        //Rotação
        case 1:
            coordinateX->disable();
            coordinateY->disable();
            coordinateZ->disable();

            group3->enable();
            radians->enable();

            scaleX->disable();
            scaleY->disable();
            scaleZ->disable();
            break;
        //Escalamento
        case 2:
            coordinateX->disable();
            coordinateY->disable();
            coordinateZ->disable();

            group3->disable();
            radians->disable();

            scaleX->enable();
            scaleY->enable();
            scaleZ->enable();
            break;
    }
    cout << transformationSelected << endl;
}

//Confirmar Transformação

void confirmTransformation(){
    //TODO:resto.
    cout << "transformações confirmadas\n";
}

//Aplicar Transformação
void applyTransformation(){
    //TODO:resto.
    cout << "transformações aplicadas\n";   
}

//Anular Transformação
void cancelTransformation(){
    //TODO:resto.
    cout << "transformações canceladas\n";      
}

//Matriz de transformação
GLUI_StaticText *row1, *row2, *row3, *row4;
string row1Text = "1 0 0 0", row2Text = "0 1 0 0", row3Text = "0 0 1 0", row4Text = "0 0 0 1";
void showMatrix(){
    //TODO: imprimir matriz

    row1->set_text( row1Text.c_str() );
    row2->set_text( row2Text.c_str() );
    row3->set_text( row3Text.c_str() );
    row4->set_text( row4Text.c_str() );
}

// int check;
// void func1(){
//     cout << check << endl;
// }
void initGLUI(){
    //GLUI
    glui = GLUI_Master.create_glui_subwindow( mainWindow,GLUI_SUBWINDOW_BOTTOM );
    glui->set_main_gfx_window(mainWindow);
    
    //painel de objetos em cena
    GLUI_Panel *objPanel = glui->add_panel( "Objetos em cena" );
    GLUI_Listbox *listObjects = glui->add_listbox_to_panel( objPanel,"lista de Objetos",&objSelected, 0, (GLUI_Update_CB) selectObject );
    for(int c = 0; c <= 20;c++){
        //inclusão dinâmica
        string label = "Sphere ";
        listObjects->add_item(c,label.c_str());    
    }



    //dados do objeto selecionado
    glui->add_statictext( "Nome:" );
    textName = glui->add_statictext( objectName.c_str() );
    glui->add_statictext( "Posicao:" );
    textPosition = glui->add_statictext( objectPosition.c_str() );
    glui->add_statictext( "Faces:" );
    textFace = glui->add_statictext( objectFaces.c_str() );
    glui->add_statictext( "Vertices:" );
    textVertex = glui->add_statictext( objectVertex.c_str() );
    glui->add_separator();
    //dados do objeto selecionado
    glui->add_column(true); 
    

    //Transformações
    GLUI_Panel *transformationsPanel = glui->add_panel( "Transformações" );
    GLUI_RadioGroup *group2 = glui->add_radiogroup_to_panel(transformationsPanel,&transformationSelected,3);
    //TODO:Criação dinâmica
    glui->add_radiobutton_to_group( group2, "Translacao" );
    glui->add_radiobutton_to_group( group2, "Rotacao" );
    glui->add_radiobutton_to_group( group2, "Escala" );
    glui->add_button("Adicionar",0,(GLUI_Update_CB)selectTransformation); 
    glui->add_separator();
    glui->add_button("Renderizar",0,(GLUI_Update_CB) render); 

    glui->add_column(true); 

    //parâmetros
    GLUI_Panel *parametersPanel = glui->add_panel( "Parametros" );
    //translação
    glui->add_statictext_to_panel(parametersPanel, "Translacao" );
    coordinateX = glui->add_spinner_to_panel(parametersPanel , "X" ,GLUI_SPINNER_FLOAT);
    coordinateX->disable();
    
    coordinateY = glui->add_spinner_to_panel(parametersPanel , "Y" ,GLUI_SPINNER_FLOAT);
    coordinateY->disable();

    coordinateZ = glui->add_spinner_to_panel(parametersPanel , "Z" ,GLUI_SPINNER_FLOAT);
    coordinateZ->disable();
    //translação
    glui->add_column_to_panel(parametersPanel);
    glui->add_statictext_to_panel( parametersPanel,"Rotacao" );
    group3 = glui->add_radiogroup_to_panel(parametersPanel,&opRotation);
    glui->add_radiobutton_to_group( group3, "X" );
    glui->add_radiobutton_to_group( group3, "Y" );
    glui->add_radiobutton_to_group( group3, "Z" );
    group3->disable();
    radians= glui->add_spinner_to_panel(parametersPanel , "Radianos:" ,GLUI_SPINNER_FLOAT);
    radians->disable();

    //escalamento
    glui->add_column_to_panel(parametersPanel);
    glui->add_statictext_to_panel( parametersPanel,"Escala" );
    scaleX = glui->add_spinner_to_panel(parametersPanel , "X" ,GLUI_SPINNER_FLOAT);
    scaleX->disable();
    
    scaleY = glui->add_spinner_to_panel(parametersPanel , "Y" ,GLUI_SPINNER_FLOAT);
    scaleY->disable();

    scaleZ = glui->add_spinner_to_panel(parametersPanel , "Z" ,GLUI_SPINNER_FLOAT);
    scaleZ->disable();
    //TODO: Entradas de parâmetros para cada transformação


    glui->add_button("Confirmar",0,(GLUI_Update_CB) confirmTransformation); 
    glui->add_button("Aplicar",0,(GLUI_Update_CB) applyTransformation); 
    glui->add_button("Anular",0,(GLUI_Update_CB) cancelTransformation); 


    //Matriz de transformação
    glui->add_column(true); 
    glui->add_statictext( "Matriz:" );
    row1 = glui->add_statictext( row1Text.c_str() );
    row2 = glui->add_statictext( row2Text.c_str() );
    row3 = glui->add_statictext( row3Text.c_str() );
    row4 = glui->add_statictext( row4Text.c_str() );
    
}


//Main program
int main(int argc, char **argv) {
    sizeX = 1000;
    sizeY = 1000;
    
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
    mainWindow = glutCreateWindow("Imperio Britanico");
    glutKeyboardFunc(input);
    init();
    glutReshapeFunc(reshape);
    //Chamada da função de desenhar
    glutDisplayFunc(draw);
    initGLUI();
    
    // Loop require by OpenGL
    glutMainLoop();
    return 0;
}