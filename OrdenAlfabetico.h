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
#include <string>
#include "Corregir.h"

void Palabras (const std::string &filename, const std::string &m) {
    //creo arrglo para hacer una pruba del metodo excluir
    string arreglo_palabras[] = {"ejercito", "revolucion", "guerras", "vida"};

    if (esNumero(m)) {
        cout << "ENTRO A ARBOL ORDEN ALFABETICO" << endl;
        int n = stoi(m);
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

            if (n == 0) {
                Arbol.inorder();
            } else if (n > 0) {
                cout<<"el n es mayor q cero "<<endl;
                Arbol.inordenexcluir(n); //no se pq m dice q no existe en el template
            } else {
                cout << "La cantidad de palabras que quieren mostrarse (n) no puede ser un valor negativo" << endl;
            }
        }

    }




}
#endif //PARCIAL2_SIMESVARTANIAN_ORDENALFABETICO_H
