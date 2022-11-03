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
    std::string caracteres = "(?.!;¿¡,:}]/*)#$%^@~'" ; //ver como hacer para q saque el "
    for (char c: caracteres) {
        palabra.erase(std::remove(palabra.begin(), palabra.end(), c), palabra.end());
    }
    for (int i=0; i<palabra.length(); i++){
        palabra[i]= tolower(palabra[i]);}
    return palabra;
}
int cantpalabras (const std:: string &filename)
{
    std::fstream file;
    file.open( filename);

    int cantp=0;
    if (file.is_open()) {
        std::string word, linea;
        while (std::getline(file, linea)) {
            std::stringstream lineStream (linea);
            while (std::getline(lineStream, word, ' '))
            {
                cantp++;
            }
        }
        return cantp;
    }

}
#endif //PARCIAL2_SIMESVARTANIAN_CORREGIR_H
