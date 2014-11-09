/**
*\file leitor.h
*\class Leitor
*\author Francisco Lucas Falcão Pereira
*\brief Usada para transformar .obj em nossa estrutura topológica.
*/

/*Durante os testes precisei fazer os seguintes includes:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
*/

#define LEITOR_SAIDA_DEFAULT "vilaOutput.obj"

class Leitor{

public:
	/**
	*	Dado o nome do arquivo, verifica se ele é do tipo obj ou não.
	*	Verifica se o parametro é realmente um arquivo do tipo obj e retorna um booleano
	*	\param nomeArquivo Nome do aquivo a ser verificado.
	*	\result Valor \c true caso o arquivo seja do tipo obj e \c false caso contrário.
	*/
    static bool eArquivoObj(std::string nomeArquivo);

	/**
	*	Percorre um arquivo .obj preenchendo uma estrutura topologica.
	*	\param nomeArquivo Nome do arquivo .obj
	*	\result Estrutura topológica preenchida pela função
	*/
    static Topology* ler(std::string nomeArquivo);

    static void salvar(Topology* cena, std::string nomeArquivo = LEITOR_SAIDA_DEFAULT);

};




