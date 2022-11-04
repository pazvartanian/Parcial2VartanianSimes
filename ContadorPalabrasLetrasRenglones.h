//
// Created by Usuario on 23/10/2022.
//
#include <iostream>
#include<string>
#include "Corregir.h"
using namespace std;
int cantletras (const std::string &filename) {
    fstream file;
    file.open(filename);
    int cantl = 0;


    if (file.is_open()){
        std::string word; //variable q va a guardarcada palabra de la linea
        //leeamos el texot
        while (std::getline (file, word, ' ')){
            //leeamo cada letra de nuestro string word
            for(int n=0 ; n<(int)word.length(); n++){
                if (word[n] >= 65 && word[n]<= 90 ) {
                    // esto me decidide si es una letra mayuscula
                    cantl++;
                } else if (word[n] >= 97 && word [n] <= 122)
                    //letra minuscula
                    cantl ++ ;

                // faltarian agregar if para ver si tiene comas op algun otro signo
            }

        }
    }else throw 404;

    return cantl;

}
int cantrenglones (const std:: string &filename)
{
    fstream file;
    file.open( filename);
    int cantr=0;
    if (file.is_open()) {
        std::string linea, word;
        while (std::getline(file, linea)) {
            std::stringstream lineStream (linea);
            while( std::getline(lineStream, word))
            {
                cantr++;
            }
        }
        return cantr;
    }else{
        exit(1);
    }

}
void  ContPalLetRen (const std::string &filename)
{
    //std::ifstream file;

    //file.open(filename,std::ios::in);
    int cantp = cantpalabras(filename);

    cout << "Cantidad letras:" << cantletras(filename) << endl;
    cout << "cantidad palabras: " << cantp << endl;
    cout << "cantidad renglones: " << cantrenglones(filename) << endl;


}
#ifndef PARCIAL2_SIMESVARTANIAN_CONTADORPALABRASLETRASRENGLONES_H
#define PARCIAL2_SIMESVARTANIAN_CONTADORPALABRASLETRASRENGLONES_H

#endif //PARCIAL2_SIMESVARTANIAN_CONTADORPALABRASLETRASRENGLONES_H
