//
// Created by Usuario on 24/10/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_ORDENALFABETICO_H
#define PARCIAL2_SIMESVARTANIAN_ORDENALFABETICO_H
#include "Arbol.h"
#include <iostream>
#include <map>
#include <sstream>
#include<fstream>

void Palabras (int n) {
    cout << "ENTRO A ARBOL ORDEN ALFABETICO" << endl;
    string filename = "C:\\Users\\Usuario\\Documents\\2do UCC\\Parcial2-SimesVartanian\\texto";
    std::ifstream file;
    file.open(filename, std::ios::in);
    ArbolBinario<std::string> Arbol;
    if (file.is_open()) {
        std::string word, linea;

        while (std::getline(file, linea)) {

            std::stringstream lineStream(linea);
            while (std::getline(lineStream, word, ' ')) {
                try {
                    Arbol.insertar(word);
                } catch (int error){}
            }
        }
    }
        Arbol.inorder();
}

#endif //PARCIAL2_SIMESVARTANIAN_ORDENALFABETICO_H
