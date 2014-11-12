/* main.cpp - Caio Viktor
Controle da window, inteface de usuário e chamadas de procedimentos
*/

#include "../lib/main.h"
//Declarações da Janela
GLfloat eyex,eyey,eyez,centrox, centroy, centroz,rotationX,rotationY,rotationZ;
int sizeX,sizeY;
int mainWindow,objSelected,modeExibitionFlag;
unsigned int modeExibitionValue = GL_LINE_LOOP;
int modeProjectionValue = PROJECTION_OPENGL;
//Declarações da Janela FIM


// Declarações de variáveis da interface
int transformationSelected,opRotation;
string objectName = "NULL",objectPosition = "X:0;Y:0;Z:0", objectFaces = "0",objectVertex = "0";
char *nameSave;
GLUI *glui;
GLUI *gluiSave;
GLUI_StaticText *textName, *textPosition, *textFace, *textVertex;
GLUI_Spinner *coordinateX,*coordinateY,*coordinateZ,*radians,*scaleX,*scaleY,*scaleZ,*colorR,*colorG,*colorB;
GLUI_RadioGroup *group3;
GLUI_EditText *nameSaveBox;
// Declarações de variáveis da interface FIM

//Declarações Gerais
int numberObjects = 0,numberVertex = 0,numberFace = 0;
Matrix *transformationMatrix = Matrix::getIdentity(), *partialTransformationMatrix = Matrix::getIdentity();
stackMatrix *stackTransformation = new stackMatrix(),*partialStackTransformation = new stackMatrix();
Vertex **arrayVertex;
ObjectClass **arrayObject;
Face **arrayFace;
Topology *topology;
View *view = new View(PROJECTION_PESPECTIVE);

//Declarações Gerais FIM

//Configura os valores da Câmera
void setCamera(){
    //TODO: selecionar mode de visualização entre pespectiva e orthogonal
    // posiciona câmera
    if(modeProjectionValue == PROJECTION_OPENGL){
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt (eyex, eyey, eyez, centrox, centroy, centroz, 0.0, 1.0, 0.0);
    }
    view->setCameraPosition(eyex,eyey,eyez,rotationX,rotationY,rotationZ);

}

void draw(void) {
    glEnable (GL_DEPTH_TEST);
    glClear (GL_DEPTH_BUFFER_BIT);
    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
        
    setCamera();
    GLfloat model[16]; 
    glGetFloatv(GL_MODELVIEW_MATRIX, model); 
    cout <<endl;
    for(int i = 0; i < 4 ; i++)
        cout << model[i] << "  " << model[i+4] << "  " << model[i+8] << "  " << model[i+12] << " \n";
    cout << "--------------------------------------------------\n";
    // carrega matriz identidade para não acumular transformações na câmera
    //Desenha cena
    Matrix *modelView = view->getModelViewMatrix();
    cout << "consegui a modelView\n";
    modelView->printMatrix();
    Matrix *projection = view->getProjectionMatrix();
    


    
    glGetFloatv(GL_PROJECTION_MATRIX, model); 
    cout <<endl;
    for(int i = 0; i < 4 ; i++)
        cout << model[i] << "  " << model[i+4] << "  " << model[i+8] << "  " << model[i+12] << " \n";
    cout << "--------------------------------------------------\n";
    cout << "consegui a projection\n";
    projection->printMatrix();
    Matrix *viewProjection = projection->multiplyMatrix(modelView);
    cout << "Consegui viewProjection\n";
    
    if(modeProjectionValue == PROJECTION_OPENGL){
        viewProjection = Matrix::getIdentity();
    }
    
    viewProjection->printMatrix();
    for(int c = 0;c<numberObjects;c++)
        arrayObject[c]->drawObject(modeExibitionValue,viewProjection);

    glFlush();
    //cout << "Display!" << endl;
}
//Configura os valores iniciais da Câmera
void initCamera(){
    //eixo x horizontal
    eyex = 0.0;
    //eixo y vertical
    eyey = 0.0;
    //eixo z perpendicular cresce para fora se valor for alto pode sair do volume de projeção
    eyez = 7.0;
    //origem de referencial da câmera (0,0,0 é a origem do global)
    centrox=0.0;
    centroy=0.0;
    centroz=0.0;

    rotationX = 0;
    rotationY = 0;
    rotationZ = 0;
}
void init (void){
    /* Seleciona a cor de fundo para limpeza da tela */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);

    initCamera();
    /* inicializa os valores de visualização */
    if(modeProjectionValue == PROJECTION_OPENGL){
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
    }
    /* Faz com que a matriz corrente seja inicializada com a matriz identidade
    (nenhuma transformação é acumulada)
    */
    setCamera();

}
//trata das transformações necessária ao redimensionar a tela
void reshape (int w, int h){   
    //cout << "Reshape!\n";
    // glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    // auto_set_viewport();
    int tx, ty, tw, th;
    GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
    glViewport( tx, ty, tw, th );

    if(modeProjectionValue == PROJECTION_OPENGL){
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        //glFrustum (-1.0, 1.0:são o volume dos lados, -1.0, 1.0:são o volume da altura, 1.0 : proximidade da câmera, 50.0:volume de profundidade);
        glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 50.0);
        //glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, 50);
        glMatrixMode (GL_MODELVIEW);
    }
    
    view->setVolumeVisualization(-1.0, 1.0, -1.0, 1.0, 1.0, 50.0);
    // glutPostRedisplay();
    // cout << "Setou o volume\n";

}
// trata a entrada do teclado
void input(unsigned char tecla, int x, int y){
    switch (tecla) {
        case 'd':
            eyex = eyex + 0.5;
            centrox = centrox + 0.5;
            break;
        case 'k':
            centrox = centrox + 0.5;
            rotationY = rotationY - 0.05;
            break;
        case 'a':
            eyex = eyex - 0.5;
            centrox = centrox - 0.5;
            break;
        case 'j':
            centrox = centrox - 0.5;
            rotationY = rotationY + 0.05;
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
        case 'i':
            centroy = centroy + 0.5;
            rotationX = rotationX + 0.05;
            break;
        case 'm':
            centroy = centroy - 0.5;
            rotationX = rotationX - 0.05;
            break;
        case 'O':
        case 'o':
            initCamera();
        break;    
    }
    //cout << "teclou\n";
    glutPostRedisplay();
}
//eventos mouse
void mouse(int button, int state, int x, int y)
{
   // Wheel reports as button 3(scroll up) and button 4(scroll down)
   if ((button == 3) || (button == 4)) // It's a wheel event
   {    //para cima
        Matrix *scale;
        if(button == 3){
            scale = Matrix::getScale(1.1,1.1,1.1,0,0,0);
        }
        //para baixo
        if(button == 4){
            scale = Matrix::getScale(0.9,0.9,0.9,0,0,0);
        }
        for(int i = 0 ; i < numberObjects; i++)
            arrayObject[i]->applyTransformation(scale);
        glutPostRedisplay();
       // Each wheel event reports like a button click, GLUT_DOWN then GLUT_UP
       if (state == GLUT_UP) return; // Disregard redundant GLUT_UP events
       //printf("Scroll %s At %d %d\n", (button == 3) ? "Up" : "Down", x, y);
   }else{  // normal button event
       //printf("Button %s At %d %d\n", (state == GLUT_DOWN) ? "Down" : "Up", x, y);
        //esquerdo
        if(button == 0){

        }
        //direito
        if(button == 2){

        }
   }
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
//TODO:Modo de projeção
void selectModeProjection(){
    if(modeProjectionValue != PROJECTION_OPENGL){
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        glMatrixMode (GL_MODELVIEW);
        glLoadIdentity ();
        if(view->getModeProjection() != modeProjectionValue){
            if(modeProjectionValue == PROJECTION_PESPECTIVE)
                view->setModeProjection(PROJECTION_PESPECTIVE);
            if(modeProjectionValue == PROJECTION_ORTOGONAL)
                view->setModeProjection(PROJECTION_ORTOGONAL);
            glutPostRedisplay();
        }
    }else{
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        //glFrustum (-1.0, 1.0:são o volume dos lados, -1.0, 1.0:são o volume da altura, 1.0 : proximidade da câmera, 50.0:volume de profundidade);
        glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 50.0);
        //glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, 50);
        glMatrixMode (GL_MODELVIEW);
        glutPostRedisplay();
    }
    
}
void save(){
    //TODO: pedir nome para salvar
    gluiSave->close();
    string aux(nameSave);
    string name = "model/" + aux;
    Leitor::salvar(topology,name);
}
void clickSave(){
    initGLUISave();
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
    //cout << transformationSelected << endl;
}
//carrega a pilha com a matriz selecionada
void pushInStack(Matrix *auxMatrix){
    stackTransformation->push(auxMatrix);
    *partialStackTransformation = *stackTransformation;
    *partialTransformationMatrix = *stackMatrix::concatenate(partialStackTransformation);
    cout << "transformações confirmadas Matriz Parcial:\n";
    partialTransformationMatrix->printMatrix();
    *partialTransformationMatrix = *Matrix::getIdentity();
}

//Confirmar Transformação

void confirmTransformation(){
    Matrix *auxMatrix,*start,*center;
    Vector *centroide = arrayObject[objSelected]->getCentroid();
    switch(transformationSelected){
        //Translação
        case 0:
            auxMatrix = Matrix::getTranslation((double)coordinateX->get_float_val(),(double)coordinateY->get_float_val(),(double)coordinateZ->get_float_val());
            pushInStack(auxMatrix);
            break;
        //Rotação
        case 1:
            start = Matrix::getTranslation(-centroide->getValue(0),-centroide->getValue(1),-centroide->getValue(2));
            // cout << "Start:\n";
            // start->printMatrix();
            pushInStack(start);
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
            // cout << "Rotação:\n";
            // auxMatrix->printMatrix();
            pushInStack(auxMatrix);
            center = Matrix::getTranslation(centroide->getValue(0),centroide->getValue(1),centroide->getValue(2));
            // cout << "Center:\n";
            // center->printMatrix();
            pushInStack(center);
            break;
        //Escalamento
        case 2:
            auxMatrix = Matrix::getScale((double) scaleX->get_float_val(), (double) scaleY->get_float_val(), (double) scaleZ->get_float_val(), centroide->getValue(0), centroide->getValue(1), centroide->getValue(2));
            // auxMatrix = Matrix::getScale((double) scaleX->get_float_val(), (double) scaleX->get_float_val(), (double) scaleX->get_float_val(), centroide->getValue(0), centroide->getValue(1), centroide->getValue(2));
            pushInStack(auxMatrix);
            break;
    }

    
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
    scaleY->set_float_val(1);
    scaleZ->set_float_val(1);
}
//Aplicar Transformação
void applyTransformation(){
    transformationMatrix = stackMatrix::concatenate(stackTransformation);
    arrayObject[objSelected]->applyTransformation(transformationMatrix);
    render();
    cout << "transformações aplicadas:\n";   
    transformationMatrix->printMatrix();
    cancelTransformation();
}

//configura modo de exibição
void selectModeExibition(){
    if(modeExibitionFlag == 0)
        modeExibitionValue = GL_LINE_LOOP;
    else
        modeExibitionValue = GL_POLYGON;
    //cout << modeExibitionValue << endl;
    render();
}
//inicia UI
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
    glui->add_button_to_panel(objDataPanel,"Salvar",0,(GLUI_Update_CB) clickSave); 
    //dados do objeto selecionado
    glui->add_column(true); 
    

    //Transformações
    GLUI_Panel *transformationsPanel = glui->add_panel( "Transformacoes" );
    GLUI_RadioGroup *group2 = glui->add_radiogroup_to_panel(transformationsPanel,&transformationSelected,3);
    glui->add_radiobutton_to_group( group2, "Translacao" );
    glui->add_radiobutton_to_group( group2, "Rotacao" );
    glui->add_radiobutton_to_group( group2, "Escala" );
    glui->add_button("Adicionar",0,(GLUI_Update_CB)selectTransformation); 
    glui->add_separator();
    GLUI_Listbox *modeExibition = glui->add_listbox("Modo de Exibicao: ",&modeExibitionFlag, 0, (GLUI_Update_CB) selectModeExibition );
    modeExibition->add_item(0,"Aramado");
    modeExibition->add_item(1,"Solido");
    GLUI_Listbox *modeProjection = glui->add_listbox("Modo de Projecao: ",&modeProjectionValue, PROJECTION_OPENGL, (GLUI_Update_CB) selectModeProjection );
    modeProjection->add_item(PROJECTION_OPENGL,"OpenGL");
    modeProjection->add_item(PROJECTION_PESPECTIVE,"Pespectiva");
    modeProjection->add_item(PROJECTION_ORTOGONAL,"Ortogonal");
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

    
    scaleY = glui->add_spinner_to_panel(parametersPanel , "Y" ,GLUI_SPINNER_FLOAT);
    scaleY->set_float_val(1);
    scaleY->disable();

    scaleZ = glui->add_spinner_to_panel(parametersPanel , "Z" ,GLUI_SPINNER_FLOAT);
    scaleZ->set_float_val(1);
    scaleZ->disable();


    glui->add_button("Confirmar",0,(GLUI_Update_CB) confirmTransformation); 
    glui->add_button("Aplicar",0,(GLUI_Update_CB) applyTransformation); 
    glui->add_button("Anular",0,(GLUI_Update_CB) cancelTransformation);     
    selectObject();
}

void initGLUISave(){
    nameSave = new char();
    gluiSave = GLUI_Master.create_glui( "Salvar",0,abs(sizeX/2),abs(sizeY/2) );
    gluiSave->add_statictext( "Digite o nome do arquivo que deseja salvar:" );
    nameSaveBox = gluiSave->add_edittext( "model/",GLUI_EDITTEXT_TEXT, nameSave);
    gluiSave->add_button("Salvar",0,(GLUI_Update_CB) save);
    //gluiSave->set_main_gfx_window(mainWindow);
}

//Main program
int main(int argc, char **argv) {
    if(argc < 2){
        cout << "Entre com o arquivo contendo o modelo!\n";
        return 1;
    }
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
    sizeX = glutGet(GLUT_SCREEN_WIDTH);
    sizeY = glutGet(GLUT_SCREEN_HEIGHT);
    /*Configura a tela
    /    -RGB color model + Alpha Channel = GLUT_RGBA
    */


    glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_SINGLE);
    
    //Ativa profundidade para superfícies escondidas
    glEnable (GL_DEPTH_TEST);

    //Configura a posição da janela
    glutInitWindowPosition(0, 0);

    //Configura o tamanho da janela
    glutInitWindowSize(sizeX,sizeY);

    //Criação da janela
    mainWindow = glutCreateWindow("BRitish EmpiRE: V 1.6 Victorian");
    glutKeyboardFunc(input);
    glutMouseFunc(mouse);
    init();
    glutReshapeFunc(reshape);
    //Chamada da função de desenhar
    glutDisplayFunc(draw);
    initGLUI();
    // Loop require by OpenGL
    glutMainLoop();
    return 0;
    
}
