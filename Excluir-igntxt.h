//
// Created by Usuario on 09/11/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_EXCLUIRIGNTXT_H
#define PARCIAL2_SIMESVARTANIAN_EXCLUIRIGNTXT_H

#include "Arbol.h"
#include <iostream>
#include <map>
#include <sstream>
#include<fstream>
#include <string>
#include "Corregir.h"

// buscamos llenar un arreglo con las palabras del texto a ignorar
// luego con el metodo anterior de excluir las excluimos del texto
// para luego poder insertar e imprimir el arbol ordenado alfabeticamente

void ExcluirpalabraIgntxt (const std::string &filename,const std::string &igntxt){

    std::ifstream file;
    file.open(filename, std::ios::in);
    string linea, word;
    int cantp;
    cantp= cantpalabras(filename);

    ArbolBinario<std::string> Arbol;

    if (file.is_open()) {
        std::string word, linea;

        while (std::getline(file, linea)) {

            std::stringstream lineStream(linea);
            while (std::getline(lineStream, word, ' ')) {
                Arbol.insertar(word);
            }
        }

    }

    file.close();
    std::ifstream file2;
        file2.open(igntxt);
        std::string arrigno[cantp];
        int i=0;

        if (file2.is_open()){

            std::string word, linea;
            while (std::getline(file2, linea)) {
                std::stringstream lineStream(linea);
                while (std::getline(lineStream, word, ' ')) {
                    word = corregirPalabra(word);
                    //guardo la palabra del igntxt en un arreglo
                    arrigno[i] = word;
                    i++;
                }
            }
            Arbol.excluirpu(arrigno);
            Arbol.inorder();
    }

}



#endif //PARCIAL2_SIMESVARTANIAN_EXCLUIRIGNTXT_H