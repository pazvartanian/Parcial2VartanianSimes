//
// Created by Usuario on 09/11/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_EXCLUIR_PALABRA_ALF_H
#define PARCIAL2_SIMESVARTANIAN_EXCLUIR_PALABRA_ALF_H

#include "Arbol.h"
#include <iostream>
#include <map>
#include <sstream>
#include<fstream>
#include <string>
#include "Corregir.h"

// con esta funcion ponemos las palabras ingresado por el usuario en un arreglo
// luego usamos el metodo excluir que nos permite no insertarla en el arbol
//una vez que todas las palabras (menos las del arreglo) estan en el arbol
// lo imprimimos inorden para que se impriman alfabeticamente

void ExcluirpalabrasAlf (const std::string &filename, std::string arreglo_palabras) {

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

#endif //PARCIAL2_SIMESVARTANIAN_EXCLUIR_PALABRA_ALF_H
