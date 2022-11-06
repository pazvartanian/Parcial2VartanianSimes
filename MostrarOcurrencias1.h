//
// Created by Usuario on 05/11/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_MOSTRAROCURRENCIAS1_H
#define PARCIAL2_SIMESVARTANIAN_MOSTRAROCURRENCIAS1_H
#include <iostream>
#include <string>
#include<fstream>
#include "HashMap.h"
#include <map>
#include <sstream>
using namespace std;
#include"fstream"

#include "Corregir.h"
#include "Quicksort.h"
unsigned int miHashFunc4(string clave)
{  const int p= 31 , m= 1e9 + 7 ;


    int key = 0 ;
    long p_pow = 1 ;

    for (int i=0; i<clave.length(); i++){
        clave[i]= tolower(clave[i]);
        key += (key + (clave[i] - 'a' + 1 ) * p_pow) % m ; //tolower nos cambia a minuscula
        p_pow = (p_pow * p )% m ;

    }

    return key ;
}


void Mostrar (const std::string &filename, std::string palabrasmostrar) {

    int cantp;
    cantp = cantpalabras(filename);
    std::string arreglopalabrasmostrar[cantp];
    std::string palabramos;
    std::stringstream lineStream (palabrasmostrar);

    cantp = cantpalabras(filename);
    int i = 0;
    while (std::getline(lineStream, palabramos, ',')) {
        palabramos = corregirPalabra(palabramos);
        arreglopalabrasmostrar[i] = palabramos;
        i++;
    }
    std::ifstream file;
    file.open(filename, std::ios::in);
    //ver como tener la cant de palabras
    cantp = cantpalabras(filename);


    HashMap<std::string, int> TH(cantp, &miHashFunc4);

    if (file.is_open()) {
        std::string word, linea;

        while (std::getline(file, linea)) {
            std::stringstream lineStream(linea);

            while (std::getline(lineStream, word, ' ')) {
                word = corregirPalabra(word);
                for (int j=0; j<i; j++)
                    if ( word== arreglopalabrasmostrar[j])
                    {
                        TH.put(word, 1);
                    }
            }
        }
    }
    file.close();
    int cantrepetidas = 0;
    int arrn[cantp];
    std::string arrc[cantp];
    cantrepetidas = TH.arregloconclaves(arrc, cantrepetidas); //corregir esto
    TH.arregloconocurrencias(arrn);

    cout << "ahora cantidad de repetidas: " << cantrepetidas << endl;
    //quickSort(arrn, arrc,   0, cantp-1);

    cout<<"AHORA CON SELSHORT"<<endl;
    shellsort(arrn, arrc, cantp);
    cout << "ORDENADO" << endl;
//cantp=cantp-cantrepetidas;
        for (int i = cantp - 1; i > 0; i--) {
            if (arrn[i] != -1){
                cout << "CLAVE " << arrc[i] << " OCURRENCIAS: " << arrn[i] << endl;

        }}


}
#endif //PARCIAL2_SIMESVARTANIAN_MOSTRAROCURRENCIAS1_H
