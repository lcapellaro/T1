#include <dirent.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "diretorio.h"

int listaArquivos (std::string nomeDir)
{
    DIR *dir = 0;                                                               //Ponteiro dir que apontará para o diretório fornecido
    struct dirent *entrada = 0;                                                 //Ponteiro percorrerá os elementos do diretório
    unsigned char isDir = 0x4;                                                  //Indica se é um diretório
    unsigned char isFile = 0x8;                                                 //Indica se é um arquivo

    dir = opendir(nomeDir.c_str());                                             //Obtém o endereço do diretório

    if (dir == 0) {
        std::cerr <<"Nao foi possivel abrir o diretorio." << std::endl;         // Verifica se o diretório fornecido é não nulo
        exit(1);
    }


    while (entrada = readdir(dir)){                                             // Percorre o diretório para verificar os arquivos, ignorando os diretórios internos
        if (entrada->d_type == isFile)
            std::cout <<entrada->d_name << std::endl;                           // Se for um arquivo e não um diretório, imprime o nome dos arquivos.
    }

    closedir(dir);                                                              //Fecha o diretório

    return 0;
}
