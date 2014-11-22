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

    ListMaterial *materiais = Leitor::lerMaterial(nomeArquivo);
    cout<<"Quantidade de materiais armazenados: "<<materiais->getSize()<<endl;

    //return NULL;

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
    cena->Materials = materiais;
    cena->MaterialNumber = materiais->getSize();


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

        } else if (atual == 'm' || atual == 's'){
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

            //Variaveis que guardarao o nome do material.
            char nomeMaterialVET[100];
            string nomeMaterial;

            while (atual == 'f' || atual == 'u'){

                if (atual == 'u'){

                    fscanf(arquivo,"semtl %s\n", nomeMaterialVET);
                    nomeMaterial.assign(nomeMaterialVET,strlen(nomeMaterialVET));
                    cout<<"As proximas faces terao o material "<<nomeMaterial<<endl;

                    atual = getc(arquivo);

                    if (atual == 's'){
                        fgets(trash,100,arquivo);
                        atual = getc(arquivo);
                    }
                }

                if (atual == 'f'){

                    fscanf(arquivo," %d %d %d\n",&v1,&v2,&v3);


                    faces[indiceFace]->setVertice1(vertices[v1-1]);
                    faces[indiceFace]->setVertice2(vertices[v2-1]);
                    faces[indiceFace]->setVertice3(vertices[v3-1]);

                    //Seta o material usando uma funcao da lista de materiais.
                    //Obrigado por essa funçao, Matheus Mayrôn.
                    faces[indiceFace]->setMaterial(materiais->getMaterial(nomeMaterial));

                    listaFaces->addFace(faces[indiceFace]);

                    indiceFace++;
                    atual = getc(arquivo);
                }


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

void Leitor::salvarMaterial(Topology* cena, std::string nomeArquivo){


    cout<<"Iniciando exportação de materiais."<<endl;

    //Caso o arquivo não termine com .obj, ele adiciona ao nome
    string prefixo="";
    string sufixo=".mtl";
    string nomeReal="";
    int tamanhoString = nomeArquivo.size();

    for(int i=0;i<tamanhoString-4;i++){
            prefixo = prefixo + nomeArquivo[i];
    }

    nomeReal = prefixo + sufixo;

    cout<<"O nome do arquivo sera: "<<nomeReal<<endl;

    FILE* arquivo;

    //Cria o arquivo:
    arquivo = fopen(nomeReal.c_str(),"w");

        fprintf(arquivo,"# BRrender MTL File\n# Material Count: %d\n\n",cena->MaterialNumber);

        Material **materiais = cena->Materials->toVector();

        for (int i = 0; i < cena->MaterialNumber ; i++){

            fprintf(arquivo,"newmtl %s\n",materiais[i]->getName().c_str());
            fprintf(arquivo,"Ns %lf\n",materiais[i]->getNs());

            Vector* Ka = materiais[i]->getKa();
            fprintf(arquivo,"Ka %lf %lf %lf\n",Ka->getValue(0), Ka->getValue(1), Ka->getValue(2));

            Vector* Kd = materiais[i]->getKd();
            fprintf(arquivo,"Kd %lf %lf %lf\n",Kd->getValue(0), Kd->getValue(1), Kd->getValue(2));

            Vector* Ks = materiais[i]->getKs();
            fprintf(arquivo,"Ks %lf %lf %lf\n",Ks->getValue(0), Ks->getValue(1), Ks->getValue(2));

            fprintf(arquivo,"Ni %lf\n",materiais[i]->getNi());
            fprintf(arquivo,"d %lf\nillum 2\n",materiais[i]->gettransparency());

            //Preciosismo desnecessario:
            if (i!=cena->MaterialNumber-1)
                fprintf(arquivo,"\n");


        }








    fclose(arquivo);
}

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

    Leitor::salvarMaterial(cena,nomeArquivo);

    FILE* arquivo;
    //Cria o arquivo:
    arquivo = fopen(nomeArquivo.c_str(),"w");

    //Imprimir comentários iniciais:
    fprintf(arquivo,"#BRrender 1.2 - Trabalho de Computacao Grafica - OBJ File: '%s'\n",nomeArquivo.c_str());

    //Imprimir mtllib, que vai ser sempre o mesmo nome mais o .mtl

    string prefixoMTL="";
    string sufixoMTL=".mtl";
    string nomeRealMTL="";
    int tamanhoStringMTL = nomeArquivo.size();

    for(int i=0;i<tamanhoStringMTL-4;i++){
            prefixoMTL = prefixoMTL + nomeArquivo[i];
    }

    nomeRealMTL = prefixoMTL + sufixoMTL;
    fprintf(arquivo, "mtllib %s\n",nomeRealMTL.c_str());


    int nObjetos = cena->ObjectNumber;
    ListMaterial *materiais = cena->Materials;

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

            Material *materialAtual;

            Face *faceAtual = facesDoObjeto->getFace(k);

            if (materialAtual != faceAtual->getMaterial()){
                materialAtual = faceAtual->getMaterial();
                fprintf(arquivo,"usemtl %s\n",materialAtual->getName().c_str());
            }

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
    cout << "Arquivos exportados com sucesso!\n";
}

ListMaterial* Leitor::lerMaterial(std::string nomeArquivo){

    //Primeiro passo: pegar o nome do arquivo, remover o .obj e adicionar o .mtl =D

    int tamNome = nomeArquivo.size();

    string novoNome = "";

    for (int i = 0; i < (tamNome-4); i++){
        novoNome = novoNome + nomeArquivo[i];
    }
    //Adicionar .mtl:
    novoNome.append(".mtl");

    FILE *arquivo;
    ListMaterial *lista = new ListMaterial();

    arquivo = fopen(novoNome.c_str(),"r");

    char atual;
    char trash[100];
    double r,g,b,ni,ns,d,illum;
    string nomeMtl;
    char nomeMtlVET[100];

    while (!feof(arquivo)){

        atual = fgetc(arquivo);

        if ((atual == '#') || (atual == '\n')){
            fseek(arquivo,-1,SEEK_CUR);
            fgets(trash,100,arquivo);
        }
        else{
            fseek(arquivo,-1,SEEK_CUR);
            fscanf(arquivo,"newmtl %s\n",nomeMtlVET);
            nomeMtl.assign(nomeMtlVET,strlen(nomeMtlVET));

            fscanf(arquivo,"Ns %lf\n",&ns);

            fscanf(arquivo,"Ka %lf %lf %lf\n",&r,&g,&b);
            Vector *Ka = new Vector(r,g,b);

            fscanf(arquivo,"Kd %lf %lf %lf\n",&r,&g,&b);
            Vector *Kd = new Vector(r,g,b);

            fscanf(arquivo,"Ks %lf %lf %lf\n",&r,&g,&b);
            Vector *Ks = new Vector(r,g,b);

            fscanf(arquivo,"Ni %lf\n",&ni);

            fscanf(arquivo,"d %lf\n",&d);

            fscanf(arquivo,"illum %lf\n",&illum);

            Material *materialAtual = new Material(nomeMtl,Kd,Ka,Ks,ns,ni,d);
            lista->addMaterial(materialAtual);

        }


    }

    fclose(arquivo);

    return lista;

}

