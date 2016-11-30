#include <dirent.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "diretorio.h"

int listaArquivos (std::string nomeDir)
{
    DIR *dir = 0;                                                               //Ponteiro dir que apontar� para o diret�rio fornecido
    struct dirent *entrada = 0;                                                 //Ponteiro percorrer� os elementos do diret�rio
    unsigned char isDir = 0x4;                                                  //Indica se � um diret�rio
    unsigned char isFile = 0x8;                                                 //Indica se � um arquivo

    dir = opendir(nomeDir.c_str());                                             //Obt�m o endere�o do diret�rio

    if (dir == 0) {
        std::cerr <<"Nao foi possivel abrir o diretorio." << std::endl;         // Verifica se o diret�rio fornecido � n�o nulo
        exit(1);
    }


    while (entrada = readdir(dir)){                                             // Percorre o diret�rio para verificar os arquivos, ignorando os diret�rios internos
        if (entrada->d_type == isFile)
            std::cout <<entrada->d_name << std::endl;                           // Se for um arquivo e n�o um diret�rio, imprime o nome dos arquivos.
    }

    closedir(dir);                                                              //Fecha o diret�rio

    return 0;
}
