//leitor.cpp
//Autor: Francisco Lucas Falcão Pereira
//Implementação da classe responsável pela leitura do arquivo obj que será a entrada do programa
#include "../lib/main.h"

bool Leitor::eArquivoObj(std::string nomeArquivo){

    //Cria novo objeto de arquivo de entrada
    FILE* arquivo;

    //Abre o arquivo de acordo com o diretorio passado como parâmetro
    arquivo = fopen(nomeArquivo.c_str(),"r");

    //Checa se houve problemas na criação do arquivo
    if (!arquivo){
        //Informa o devido erro
        cout<<"Arquivo invalido - Erro no nome do arquivo ou diretorio informado pelo usuario\n";
        return false;
    }

    /* Verifica se o arquivo é um .obj
    A verificação será feita pegando os 4 últimos caracteres
    da String e comparando com ".obj" */

    int tamanhoString = nomeArquivo.size();
    string sufixo =""; //receberá os 4 últimos caracteres de nomeArquivo

    //O laço for a seguir adiciona os 4 últimos caracteres de nomeArquivo à
    //variavel 'sufixo'
    for(int i=tamanhoString-4;i<tamanhoString;i++){
            sufixo = sufixo + nomeArquivo[i];
    }
    //Confere se o arquivo é um .obj
    if (sufixo!=".obj"){
        cout<<"Arquivo invalido - O arquivo existe, mas nao e do formato obj\n";
        fclose(arquivo);
        return false;
    }


    fclose(arquivo);
    return true;
}

Topology* Leitor::ler(std::string nomeArquivo){

    FILE* arquivo;


    //Abre o arquivo de acordo com o diretorio passado como parâmetro
    arquivo = fopen(nomeArquivo.c_str(),"r");

    //O método lerá todo o arquivo uma vez para contar o número de objetos,
    //vértices e faces.
    int contObjetos = 0, contVertices = 0, contFaces = 0;
    char atual;

    //Variável auxiliar que servirá para armazenar temporariamente aquilo
    //que não nos interessar. Por exemplo, se encontrar um comentário,
    //o restante da linha será armazenado na variável "trash" para continuar
    //com a leitura a partir da próxima linha.
    char trash[100];

    //Variavel que guardará as coordenadas lidas dos vertices:
    double x,y,z;

    //Variavel que guardará os três vértices de cada face:
    int v1,v2,v3;

    while(!feof(arquivo)){

        //A proxima linha lerá o proximo caractere do arquivo
        atual = getc(arquivo);



        //Agora começa as comparações do caractere com as possibilidades do arquivo
        if (atual == '#'){
            //cout<<"Achou um comentário\n";
            fgets(trash,100,arquivo);

        } else if (atual == 'm' || atual == 'u' || atual == 's') {

            fgets(trash,100,arquivo);

        } else if (atual == 'f') {

            fgets(trash,100,arquivo);
            contFaces++;

        } else if (atual == 'o') {

           //cout<<"Achou um objeto de nome: ";
           fscanf(arquivo," %s",trash);
           //cout<<trash<<endl;
           contObjetos++;

        } else if (atual == 'v'){
            //cout<<"Achou um vertice de coordenadas: ";
            fscanf(arquivo," %lf %lf %lf\n",&x,&y,&z);
            //cout<<x<<" "<<y<<" "<<z<<endl;
            contVertices++;
        } else {
            //cout<<"Achou algo desconhecido"<<endl;
        }
   }

    cout<<"\n\nPRIMEIRA LEITURA:\n"
        <<"OBJETOS: "<<contObjetos<<endl
        <<"FACES: "<<contFaces<<endl
        <<"VERTICES: "<<contVertices<<endl<<endl;


    //Se preparando para a segunda leitura:

    //Vetor de vertices e faces auxiliar:
    Vertex** vertices = new Vertex*[contVertices];
    for(int i=0;i<contVertices;i++){
        vertices[i] = new Vertex();
    }
    Face** faces = new Face*[contFaces];
    for(int i=0;i<contFaces;i++){
        faces[i] = new Face();
    }

    //Variaveis que vão ajudar a receber o nome de cada objeto
    char nomeObjetoVet[100];
    string nomeObjeto;

    int indiceObjeto = 0, indiceFace = 0, indiceVertice = 0;
    //Cria ponteiro que será retornado.
    Topology* cena = new Topology;
    ListVertex* listaVertices;
    ListFace* listaFaces;
    //Vertex* verticeAtual;
   // Face* faceAtual;

    cena->ObjectNumber = contObjetos;
    cena->VertexNumber = contVertices;
    cena->FaceNumber = contFaces;


    ObjectClass** objetos = new ObjectClass*[contObjetos];
    for(int i=0;i<contObjetos;i++){
        objetos[i] = new ObjectClass();
    }


    //Move o cursor do arquivo para o início, para fazer a segunda leitura.
    fseek(arquivo,0,SEEK_SET);

    while(!feof(arquivo)){

        atual = getc(arquivo);
        if (atual == '#'){

            //cout<<"Achou um comentário\n";
            fgets(trash,100,arquivo);

        } else if (atual == 'm' || atual == 'u' || atual == 's'){
            fgets(trash,100,arquivo);
        } else if (atual == 'o'){

            //Encontrou um objeto
            fscanf(arquivo," %s\n",nomeObjetoVet);
            nomeObjeto.assign(nomeObjetoVet,strlen(nomeObjetoVet));
            objetos[indiceObjeto]->setName(nomeObjeto);

            atual = getc(arquivo);
            //Para cada objeto, irá fazer o seguinte:
            listaVertices = new ListVertex();
            listaFaces = new ListFace();

            cout<<"Iniciando leitura de vertices e faces do objeto "<<nomeObjeto<<endl;

            while (atual == 'v'){

                fscanf(arquivo," %lf %lf %lf\n",&x,&y,&z);

                vertices[indiceVertice]->setCoordinateX(x);
                vertices[indiceVertice]->setCoordinateY(y);
                vertices[indiceVertice]->setCoordinateZ(z);
                vertices[indiceVertice]->setCoordinateW(1.0);

                listaVertices->addVertex(vertices[indiceVertice]);

                indiceVertice++;

                atual = getc(arquivo);

            }


            objetos[indiceObjeto]->setListVertex(listaVertices);

            cout<<"Encontrou ate o vertice: "<<indiceVertice<<endl<<endl;

            while (atual != 'f'){

                fgets(trash,100,arquivo);
                atual = getc(arquivo);
            }

            while (atual == 'f'){


                fscanf(arquivo," %d %d %d\n",&v1,&v2,&v3);


                faces[indiceFace]->setVertice1(vertices[v1-1]);
                faces[indiceFace]->setVertice2(vertices[v2-1]);
                faces[indiceFace]->setVertice3(vertices[v3-1]);

                listaFaces->addFace(faces[indiceFace]);

                indiceFace++;
                atual = getc(arquivo);


            }
            objetos[indiceObjeto]->setListFace(listaFaces);

            //Se prepara para ler o proximo objeto
            indiceObjeto++;

            //O proximo passo serve pra voltar o cursor no arquivo em uma posição.
            //Isso é necessário porque antes de sair do while acima,ele atualiza "atual",
            //Mas quando o programa voltar pro while maior, ele atualizará de novo "atual",
            //fazendo o programa pular um caractere sem chegar exatamente o que ele é.
            fseek(arquivo,-1,SEEK_CUR);

        } else {
                fgets(trash,100,arquivo);

        }

        /*
        LEMBRETE:
            O indice do vetor de vertices começa no 0, enquanto o indice usado no padrão do .obj
            começa do 1. Logo, lembrar de modificar quando fizer o construtor da classe apontar
            para o indice k do vetor de Vertices.
        */

    }

    cena->ObjectArray = objetos;
    cena->VertexArray = vertices;
    cena->FaceArray = faces;

    fclose(arquivo);
    return cena;
}


//Alterações pós 06/11:

void Leitor::salvar(Topology* cena, std::string nomeArquivo){

    cout<<"Iniciando exportação de arquivo."<<endl;

    //Caso o arquivo não termine com .obj, ele adiciona ao nome
    string sufixo="";
    int tamanhoString = nomeArquivo.size();

    for(int i=tamanhoString-4;i<tamanhoString;i++){
            sufixo = sufixo + nomeArquivo[i];
    }

    if (sufixo != ".obj"){
        nomeArquivo = nomeArquivo + ".obj";
    }


    FILE* arquivo;
    //Cria o arquivo:
    arquivo = fopen(nomeArquivo.c_str(),"w");

    //Imprimir comentários iniciais:
    fprintf(arquivo,"#BRrender 1.2 - Trabalho de Computacao Grafica - OBJ File: '%s'\n",nomeArquivo.c_str());

    int nObjetos = cena->ObjectNumber;

    //Para cada objeto:
    for (int i = 0; i < nObjetos; i++){
        //Imprime o nome do objeto:
        fprintf(arquivo,"o %s\n",cena->ObjectArray[i]->getName().c_str());

        //Imprimir os vértices:
        ListVertex *verticesDoObjeto = cena->ObjectArray[i]->getListVertex();

        for (int k = 0; k < verticesDoObjeto->numberVertex(); k++){
            Vertex *verticeAtual = verticesDoObjeto->getVertex(k);
            fprintf(arquivo,"v %lf %lf %lf\n", verticeAtual->getCoordinateXd(),verticeAtual->getCoordinateYd(),verticeAtual->getCoordinateZd());
        }

        ListFace *facesDoObjeto = cena->ObjectArray[i]->getListFace();

        for (int k = 0; k < facesDoObjeto->numberFaces(); k++){
            Face *faceAtual = facesDoObjeto->getFace(k);

            Vertex *vertice1 = faceAtual->getVertice1();
            Vertex *vertice2 = faceAtual->getVertice2();
            Vertex *vertice3 = faceAtual->getVertice3();

            int indiceV1;
            int indiceV2;
            int indiceV3;

            int nTotalVertices = cena->VertexNumber;
            for (int j = 0; j < nTotalVertices; j++){

                if (vertice1 == cena->VertexArray[j]){
                    indiceV1 = j+1; //O "+1" se dá pois o índice de faces no obj começa do 1
                }
                if (vertice2 == cena->VertexArray[j]){
                    indiceV2 = j+1;
                }
                if (vertice3 == cena->VertexArray[j]){
                    indiceV3 = j+1;
                }
            }

            fprintf(arquivo,"f %d %d %d\n", indiceV1, indiceV2,indiceV3);

        }

    }

    fclose(arquivo);
    cout << "Arquivo exportado com sucesso!\n";
}

