#include "../../lib/main.h"


int main(){

    string nomeArquivo;
    Topology* cena;

    //Laço que solicitará do usuário o nome do arquivo que será lido
    //Retornará ao laço até que o arquivo seja válido, ou seja, exista e seja do tipo .obj
    do {

        cout<<"Digite o diretorio e nome do arquivo obj: ";
        cin>>nomeArquivo;

    } while(!Leitor::eArquivoObj(nomeArquivo));

    cena = Leitor::ler(nomeArquivo);
    cout<<"-------------------------------------------------------------\n"
        <<"A PARTIR DAQUI ESTA NA CLASSE TESTELEITURA\n\n";

    //Checando se os valores foram realmente passados:
    cout<<"O numero de objetos eh: "<<cena->ObjectNumber<<endl;
    cout<<"O numero de faces eh: "<<cena->FaceNumber<<endl;
    cout<<"O numero de vertices eh: "<<cena->VertexNumber<<endl;
    cout<<"\nACESSANDO O OBJETO DE INDICE 0 DE CENA:\n";
    cena->ObjectArray[0]->getListVertex()->list();
    cout<<"ACESSANDO INDICE 1 DO ARRAY DE VERTICES DE CENA:\n";
    cena->VertexArray[1]->showVertex();
    cout<<"ALTERANDO TODOS OS X's para 0\n";
    for(int i = 0;i<(cena->VertexNumber);i++){
        cena->VertexArray[i]->setCoordinateX(0.0);
    }
    cout<<"ACESSANDO NOVAMENTE O OBJETO DE INDICE 0 DE CENA:\n";
    cena->ObjectArray[0]->getListVertex()->list();
    cout<<"ACESSANDO INDICE 5 DO ARRAY DE FACES DE CENA:\n";
    cena->FaceArray[5]->showVertexs();
    cout<<"\nACESSANDO O NUMERO DE FACES E VERTICES DE CADA OBJETO\n";

    for (int i = 0;i<(cena->ObjectNumber);i++){
        cout<<"\nObjeto de nome: "<<cena->ObjectArray[i]->getName()
            <<" possui vertices: \n";
        cena->ObjectArray[i]->getListVertex()->list();
        cout<<"\ne possui faces:\n";
        cena->ObjectArray[i]->getListFace()->list();
        cout<<"ESSE OBJETO POSSUI "<<cena->ObjectArray[i]->getNumberFace()<<" faces"
        <<" e "<<cena->ObjectArray[i]->getNumberVertex()<<" vertices\n"<<endl;

    }





    return 0;
}
