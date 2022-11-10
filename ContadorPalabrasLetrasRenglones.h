//
// Created by Usuario on 23/10/2022.
//
#include <iostream>
#include<string>
#include "Corregir.h"
#include "Arbol.h"
#include "OrdenAlfabetico.h"

using namespace std;

int cantidad_letras (const std::string &filename) {
    fstream file;
    file.open(filename);
    int cletras = 0;
    //es el contador de la cantidad de letras


    if (file.is_open()){
        std::string word; //variable q va a guardarcada palabra de la linea
        //leeamos el texot
        while (std::getline (file, word, ' ')){
            //leemos cada letra de nuestro string word
            for(int n=0 ; n<(int)word.length(); n++){
                if (word[n] >= 65 && word[n]<= 90 ) {
                    // esto me decidide si es una letra mayuscula
                    cletras++;
                } else if (word[n] >= 97 && word [n] <= 122)
                    //letra minuscula
                    cletras ++ ;
            }
        }
    }else throw 404;

    return cletras;

}
int cantidad_renglones (const std:: string &filename)
{
    fstream file;
    file.open( filename);
    int crenglones=0;
    // es el contador de la cantidad de renglones
    if (file.is_open()) {
        std::string linea, word;
        while (std::getline(file, linea)) {
            std::stringstream lineStream (linea);
            while( std::getline(lineStream, word))
            {
                crenglones++;
            }
        }
        return crenglones;
    }else{
        exit(1);
    }
}
// la idea es contar los nodos izquierdos, los derechos y la raiz
// al sumarlos nos dara la cantidad de nodos en el arbol
// es decir las palabras distintas
//int palabrasDiferentes (const std::string &filename){
//
//    std::ifstream file;
//    file.open(filename);
//    ArbolBinario<std::string> Arbol;
//    int contador=0;
//
//    if(file.is_open()){
//        std::string word,linea;
//
//        while (std::getline(file,linea)){
//            std::stringstream lineStream (linea);
//            while(std::getline(lineStream,word,' ')){
//                Arbol.insertar(word);
//                contador++;
//            }
//        }
//        //Arbol.contarnodos();
//        return contador;
//    }
//}



void  Contador_Pal_Let_Ren (const std::string &filename)
{
    ArbolBinario<std::string> Arbol;
    int cpalabras = cantpalabras(filename);

    cout << "Cantidad Letras:" << cantidad_letras(filename) << "\n" << std::flush;
    cout << "Cantidad Palabras: " << cpalabras << "\n" << std::flush;
    cout << "Cantidad Renglones: " << cantidad_renglones(filename) << "\n" << std::flush;
    // cout << "Palabras Diferentes:" << palabrasDiferentes << "\n" << std::flush;


}
#ifndef PARCIAL2_SIMESVARTANIAN_CONTADORPALABRASLETRASRENGLONES_H
#define PARCIAL2_SIMESVARTANIAN_CONTADORPALABRASLETRASRENGLONES_H

#endif //PARCIAL2_SIMESVARTANIAN_CONTADORPALABRASLETRASRENGLONES_H
