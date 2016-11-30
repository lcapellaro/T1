#include <dirent.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "diretorio.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc !=2){
        cerr <<"Diretorio nao fornecido." <<endl;
        exit(1);
    }

    listaArquivos (argv[1]);

    return 0;
}
