/* main.cpp - Caio Viktor
Controle da window, inteface de usuário e chamadas de procedimentos
*/
#include "../lib/main.h"
//Declarações da Janela
GLfloat eyex,eyey,eyez,centrox, centroy, centroz;
int sizeX,sizeY;
int mainWindow,objSelected,modeExibitionFlag;
unsigned int modeExibitionValue = GL_LINE_LOOP;
//Declarações da Janela FIM


// Declarações de variáveis da interface
int transformationSelected,opRotation;
string objectName = "NULL",objectPosition = "X:0;Y:0;Z:0", objectFaces = "0",objectVertex = "0";
GLUI *glui;
GLUI_StaticText *textName, *textPosition, *textFace, *textVertex;
GLUI_Spinner *coordinateX,*coordinateY,*coordinateZ,*radians,*scaleX,*scaleY,*scaleZ,*colorR,*colorG,*colorB;
GLUI_RadioGroup *group3;
// Declarações de variáveis da interface FIM

//Declarações Gerais
int numberObjects = 0,numberVertex = 0,numberFace = 0;
Matrix *transformationMatrix = Matrix::getIdentity(), *partialTransformationMatrix = Matrix::getIdentity();
stackMatrix *stackTransformation = new stackMatrix(),*partialStackTransformation = new stackMatrix();
Vertex **arrayVertex;
ObjectClass **arrayObject;
Face **arrayFace;
Topology *topology;


//Declarações Gerais FIM


void draw(void) {

    glLoadIdentity();
    // posiciona câmera
    gluLookAt (eyex, eyey, eyez, centrox, centroy, centroz, 0.0, 1.0, 0.0);
    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // carrega matriz identidade para não acumular transformações na câmera
    //Desenha cena
   // glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    for(int c = 0;c<numberObjects;c++)
        arrayObject[c]->drawObject(modeExibitionValue);

    glFlush();
    //cout << "Display!" << endl;
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
    //cout << "Reshape!\n";
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    GLUI_Master.auto_set_viewport();
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
            centrox = centrox + 0.5;
            break;
        case 'k':
            centrox = centrox + 0.5;
            break;
        case 'a':
            eyex = eyex - 0.5;
            centrox = centrox - 0.5;
            break;
        case 'j':
            centrox = centrox - 0.5;
            break;
        case 'e':
            eyey = eyey + 0.5;
            centroy = centroy + 0.5;
            break;
        case 'q':
            eyey = eyey - 0.5;
            centroy = centroy - 0.5;
            break;
        case 's':
            eyez = eyez + 0.5;
            centroz = centroz + 0.5;
            break;
        case 'w':
            eyez = eyez - 0.5;
            centroz = centroz - 0.5;
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
    //cout << "teclou\n";
    glutPostRedisplay();
}

//callbacks GLUI interface
void render(){
    ostringstream convert;
    arrayObject[objSelected]->setColorR(colorR->get_float_val());
    arrayObject[objSelected]->setColorG(colorG->get_float_val());
    arrayObject[objSelected]->setColorB(colorB->get_float_val());
    Vector *centroide = arrayObject[objSelected]->getCentroid();
    convert << "X: " << centroide->getValue(0) << " Y: " << centroide->getValue(1) << " Z: " << centroide->getValue(2);
    objectPosition = convert.str();
    textPosition->set_text(objectPosition.c_str());
    glutSetWindow(mainWindow);
    glutPostRedisplay();

}

//Seleção de objetos

void selectObject(){
    ostringstream convert;
    objectName = arrayObject[objSelected]->getName();
    convert << arrayObject[objSelected]->getNumberFace();
    objectFaces = convert.str();
    convert.str("");
    convert.clear();
    convert << arrayObject[objSelected]->getNumberVertex();
    objectVertex = convert.str();
    convert.str("");
    convert.clear();
    Vector *centroide = arrayObject[objSelected]->getCentroid();
    convert << "X: " << centroide->getValue(0) << " Y: " << centroide->getValue(1) << " Z: " << centroide->getValue(2);
    objectPosition = convert.str();
    //TODO: posição


    textName->set_text(objectName.c_str());
    textPosition->set_text(objectPosition.c_str());
    textFace->set_text(objectFaces.c_str());
    textVertex->set_text(objectVertex.c_str());
    colorR->set_float_val(arrayObject[objSelected]->getCollorR());
    colorG->set_float_val(arrayObject[objSelected]->getCollorG());
    colorB->set_float_val(arrayObject[objSelected]->getCollorB());
}

//Seleção de tranformação

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
            // scaleY->disable();
            // scaleZ->disable();
            break;
        //Rotação
        case 1:
            coordinateX->disable();
            coordinateY->disable();
            coordinateZ->disable();

            group3->enable();
            radians->enable();

            scaleX->disable();
            // scaleY->disable();
            // scaleZ->disable();
            break;
        //Escalamento
        case 2:
            coordinateX->disable();
            coordinateY->disable();
            coordinateZ->disable();

            group3->disable();
            radians->disable();

            scaleX->enable();
            // scaleY->enable();
            // scaleZ->enable();
            break;
    }
    //cout << transformationSelected << endl;
}

//Confirmar Transformação

void confirmTransformation(){
    Matrix *auxMatrix;
    switch(transformationSelected){
        //Translação
        case 0:
            auxMatrix = Matrix::getTranslation((double)coordinateX->get_float_val(),(double)coordinateY->get_float_val(),(double)coordinateZ->get_float_val());
            break;
        //Rotação
        case 1:
            switch(group3->get_int_val()){
                case 0:
                    auxMatrix = Matrix::getRotationX((double) radians->get_float_val());
                    break;
                case 1:
                    auxMatrix = Matrix::getRotationY((double) radians->get_float_val());
                    break;
                case 2:
                    auxMatrix = Matrix::getRotationZ((double) radians->get_float_val());
                    break;
            }
            break;
        //Escalamento
        case 2:
            //TODO: no lugar dos 0 pôr a centroide do objeto
            //auxMatrix = Matrix::getScale((double) scaleX->get_float_val(), (double) scaleY->get_float_val(), (double) scaleZ->get_float_val(), 0, 0, 0);
            auxMatrix = Matrix::getScale((double) scaleX->get_float_val(), (double) scaleX->get_float_val(), (double) scaleX->get_float_val(), 0, 0, 0);
            break;
    }

    stackTransformation->push(auxMatrix);
    *partialStackTransformation = *stackTransformation;
    *partialTransformationMatrix = *stackMatrix::concatenate(partialStackTransformation);
    cout << "transformações confirmadas Matriz Parcial:\n";
    partialTransformationMatrix->printMatrix();
    *partialTransformationMatrix = *Matrix::getIdentity();
}

//Anular Transformação
void cancelTransformation(){
    delete stackTransformation;
    stackTransformation = new stackMatrix();
    *partialStackTransformation = *stackTransformation;
    *transformationMatrix = *Matrix::getIdentity();
    *partialTransformationMatrix = *Matrix::getIdentity();
    cout << "transformações limpadas:\n";      
    partialTransformationMatrix->printMatrix();
    scaleX->set_float_val(1);
    // scaleY->set_float_val(1);
    // scaleZ->set_float_val(1);
}
//Aplicar Transformação
void applyTransformation(){
    //TODO:resto.
    transformationMatrix = stackMatrix::concatenate(stackTransformation);
    arrayObject[objSelected]->applyTransformation(transformationMatrix);
    render();
    cout << "transformações aplicadas:\n";   
    transformationMatrix->printMatrix();
    cancelTransformation();
}


void selectModeExibition(){
    if(modeExibitionFlag == 0)
        modeExibitionValue = GL_LINE_LOOP;
    else
        modeExibitionValue = GL_POLYGON;
    //cout << modeExibitionValue << endl;
    render();
}

void initGLUI(){
    //GLUI
    glui = GLUI_Master.create_glui_subwindow( mainWindow,GLUI_SUBWINDOW_BOTTOM );
    glui->set_main_gfx_window(mainWindow);
    
    //painel de objetos em cena
    GLUI_Listbox *listObjects = glui->add_listbox("Lista de Objetos: ",&objSelected, 0, (GLUI_Update_CB) selectObject );
    for(int c = 0; c < numberObjects;c++){
        //inclusão dinâmica
        listObjects->add_item(c,arrayObject[c]->getName().c_str());    
    }



    //dados do objeto selecionado
    GLUI_Panel *objDataPanel = glui->add_panel( "Dados:" );
    glui->add_statictext_to_panel(objDataPanel, "Nome:" );
    textName = glui->add_statictext_to_panel(objDataPanel,objectName.c_str() );
    glui->add_statictext_to_panel(objDataPanel, "Posicao:" );
    textPosition = glui->add_statictext_to_panel(objDataPanel, objectPosition.c_str() );
    glui->add_statictext_to_panel(objDataPanel, "Faces:" );
    textFace = glui->add_statictext_to_panel(objDataPanel, objectFaces.c_str() );
    glui->add_statictext_to_panel(objDataPanel, "Vertices:" );
    textVertex = glui->add_statictext_to_panel(objDataPanel, objectVertex.c_str() );
    glui->add_column_to_panel(objDataPanel,false); 
    colorR = glui->add_spinner_to_panel(objDataPanel , "R:" ,GLUI_SPINNER_FLOAT);
    colorR->set_float_limits( 0, 1 ,GLUI_LIMIT_CLAMP );
    colorG = glui->add_spinner_to_panel(objDataPanel , "G:" ,GLUI_SPINNER_FLOAT);
    colorG->set_float_limits( 0, 1 ,GLUI_LIMIT_CLAMP );
    colorB = glui->add_spinner_to_panel(objDataPanel , "B:" ,GLUI_SPINNER_FLOAT);
    colorB->set_float_limits( 0, 1 ,GLUI_LIMIT_CLAMP );
    glui->add_button_to_panel(objDataPanel,"Renderizar",0,(GLUI_Update_CB) render); 
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
    GLUI_Listbox *modeExibition = glui->add_listbox("Modo de Exibicao: ",&modeExibitionFlag, 0, (GLUI_Update_CB) selectModeExibition );
    modeExibition->add_item(0,"Aramado");
    modeExibition->add_item(1,"Solido");
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
    scaleX->set_float_val(1);
    scaleX->set_float_limits(0.0001,99,GLUI_LIMIT_CLAMP);
    scaleX->disable();

    
    // scaleY = glui->add_spinner_to_panel(parametersPanel , "Y" ,GLUI_SPINNER_FLOAT);
    // scaleY->set_float_val(1);
    // scaleY->disable();

    // scaleZ = glui->add_spinner_to_panel(parametersPanel , "Z" ,GLUI_SPINNER_FLOAT);
    // scaleZ->set_float_val(1);
    // scaleZ->disable();


    glui->add_button("Confirmar",0,(GLUI_Update_CB) confirmTransformation); 
    glui->add_button("Aplicar",0,(GLUI_Update_CB) applyTransformation); 
    glui->add_button("Anular",0,(GLUI_Update_CB) cancelTransformation);     
    selectObject();
}

//Main program
int main(int argc, char **argv) {
    sizeX = 1050;
    sizeY = 1000;
    //teste se o arquivo é válido
    if(!Leitor::eArquivoObj(argv[1]))
        return 0;
    //Carrega estruturas de dados
    topology = Leitor::ler(argv[1]);
    arrayObject = topology->ObjectArray;
    numberObjects = topology->ObjectNumber;
    arrayVertex = topology->VertexArray;
    numberVertex = topology->VertexNumber;
    arrayFace = topology->FaceArray;
    numberFace = topology->FaceNumber;
    //inicia o glut
    glutInit(&argc, argv);
    // sizeX = glutGet(GLUT_SCREEN_WIDTH);
    // sizeY = glutGet(GLUT_SCREEN_HEIGHT);
    /*Configura a tela
    /    -RGB color model + Alpha Channel = GLUT_RGBA
    */
    //teste();


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