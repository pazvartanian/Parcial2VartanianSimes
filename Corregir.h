//
// Created by Usuario on 02/11/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_CORREGIR_H
#define PARCIAL2_SIMESVARTANIAN_CORREGIR_H
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>


std::string corregirPalabra (std::string palabra) {
// vamos a correguir la palabra para mostarlas sin signos de explamacion, interrogacion ni putuacion
//recorremos toda la palabra y borramos signos .
    std::string caracteres = "(?.!;¿¡,:}]/*)-#$%^@~'" ;
    for (char c: caracteres) {
        palabra.erase(std::remove(palabra.begin(), palabra.end(), c), palabra.end());
    }
    for (int i=0; i<palabra.length(); i++){
        palabra[i]= tolower(palabra[i]);}
    return palabra;
}
int cantpalabras (const std:: string &filename)
{
    std::cout<<filename;
    std::fstream file;
    file.open( filename);
    int cpalabras=0;
    //es el contador de la cantidad de palabras
    if (file.is_open()) {
        std::string word, linea;
        while (std::getline(file, linea)) {
            std::stringstream lineStream (linea);
            while (std::getline(lineStream, word, ' '))
            {
                cpalabras++;
            }
        }
        return cpalabras;
    }else{
        exit(1);
    }

}
#endif //PARCIAL2_SIMESVARTANIAN_CORREGIR_H
