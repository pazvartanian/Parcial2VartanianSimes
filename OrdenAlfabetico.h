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

void Palabras (const std::string &filename) {
    cout << "ENTRO A ARBOL ORDEN ALFABETICO" << endl;
   /* string filename = "C:\\Users\\Usuario\\Desktop\\parcial 2\\Parcial2VartanianSimes\\texto";*/
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
    //if (n==0){
        Arbol.inorder();}
   /* else if (n>0)
    {
        int cont = 0;
        Arbol.inordern( n, cont); //no se pq m dice q no existe en el template

    }else {
        cout<<"La cantidad de palabras que quieren mostrarse (n) no puede ser un valor negativo"<<endl;
    }*/


#endif //PARCIAL2_SIMESVARTANIAN_ORDENALFABETICO_H
