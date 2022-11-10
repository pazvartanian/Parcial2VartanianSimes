//
// Created by Usuario on 23/10/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_FUNCIONOCURRENCIAS_H
#define PARCIAL2_SIMESVARTANIAN_FUNCIONOCURRENCIAS_H
#include<iostream>
#include <string>
#include<fstream>
#include "HashMap.h"
#include <map>
#include "esNumero.h"
#include <sstream>
#include "Corregir.h"
#include "QuickSort.h"
#include "Colisiones.h"
using namespace std;


void Ocurrencias (const std::string &filename, const std::string &m ) {
    if (esNumero(m)) {
        int n= atoi(m.c_str());
        std::ifstream file;
        file.open(filename, std::ios::in);
        int cantp;

        cantp = cantpalabras(filename);


        HashMap<std::string, int> TH(cantp, &miHashFunc);

        if (file.is_open()) {
            std::string word, linea;

            while (std::getline(file, linea)) {
                std::stringstream lineStream(linea);

                while (std::getline(lineStream, word, ' ')) {
                    word = corregirPalabra(word);
                    TH.put(word, 1);
                }
            }
        }
        file.close();
        int cantrepetidas = 0;
        int arr_cant_ocurrencias[cantp];
        //arr_cant_ocurrencias es el arreglo con la cantidad de ocurrencias
        std::string arrc[cantp];
        cantrepetidas = TH.arregloconclaves(arrc, cantrepetidas); //corregir esto
        TH.arregloconocurrencias(arr_cant_ocurrencias);

        quickSort(arr_cant_ocurrencias, arrc,   0, cantp-1);


        //shellsort(arr_cant_ocurrencias, arrc, cantp);

        if (n==0) {
            for (int i = cantp - 1; i > 0; i--) {
                if (arr_cant_ocurrencias[i] != -1)
                    cout << arrc[i]  <<" "<<  arr_cant_ocurrencias[i] << "\n" << std::flush;
            }

        } else if (n > 0 && n < cantp) {
            for (int i = cantp - 1; i > cantp - 1 - n; i--) {
                if (arr_cant_ocurrencias[i] != -1)
                    cout <<  arrc[i] <<" "<<  arr_cant_ocurrencias[i] << "\n" << std::flush;
            }
        }
    }
}

#endif //PARCIAL2_SIMESVARTANIAN_FUNCIONOCURRENCIAS_H
