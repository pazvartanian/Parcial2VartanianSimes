//
// Created by Usuario on 23/10/2022.
//
#include <iostream>
#include<string>
#include "Corregir.h"
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
void  Contador_Pal_Let_Ren (const std::string &filename)
{
    //std::ifstream file;

    //file.open(filename,std::ios::in);
    int cpalabras = cantpalabras(filename);

    cout << "Cantidad letras:" << cantidad_letras(filename) << endl;
    cout << "cantidad palabras: " << cpalabras << endl;
    cout << "cantidad renglones: " << cantidad_renglones(filename) << endl;


}
#ifndef PARCIAL2_SIMESVARTANIAN_CONTADORPALABRASLETRASRENGLONES_H
#define PARCIAL2_SIMESVARTANIAN_CONTADORPALABRASLETRASRENGLONES_H

#endif //PARCIAL2_SIMESVARTANIAN_CONTADORPALABRASLETRASRENGLONES_H
