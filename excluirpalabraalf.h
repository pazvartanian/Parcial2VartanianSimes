//
// Created by Usuario on 09/11/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_EXCLUIRPALABRAALF_H
#define PARCIAL2_SIMESVARTANIAN_EXCLUIRPALABRAALF_H

#include "Arbol.h"
#include <iostream>
#include <map>
#include <sstream>
#include<fstream>
#include <string>
#include "Corregir.h"

void ExcluirpalabrasAlf (const std::string &filename, std::string arreglo_palabras) {
    //creo arrglo para hacer una pruba del metodo excluir
    //string arreglo_palabras[] = {"ejercito", "revolucion", "guerras", "vida"};

        /* string filename = "C:\\Users\\Usuario\\Desktop\\parcial 2\\Parcial2VartanianSimes\\texto";*/
        std::ifstream file;
        file.open(filename, std::ios::in);
        ArbolBinario<std::string> Arbol;
        if (file.is_open()) {
            std::string word, linea;

            while (std::getline(file, linea)) {

                std::stringstream lineStream(linea);
                while (std::getline(lineStream, word, ' ')) {
                    Arbol.insertar(word);
                }
            }

            std::stringstream linea2(arreglo_palabras);
            std::string word2;
            int i= 0;
            std::string arreglo[100];

            while(std::getline(linea2, word, ',')){
                arreglo[i] = word;
                i++;
            }


            Arbol.excluirpu(arreglo);
            Arbol.inorder();


        }

    }






#endif //PARCIAL2_SIMESVARTANIAN_EXCLUIRPALABRAALF_H
