//
// Created by Usuario on 23/10/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_OCURRENCIASEXCLUIRPALABRAS_H
#define PARCIAL2_SIMESVARTANIAN_OCURRENCIASEXCLUIRPALABRAS_H
#include<iostream>
#include <string>
#include<fstream>
#include "HashMap.h"
#include <map>
#include <sstream>
#include "QuickSort.h"
#include "Colisiones.h"

using namespace std;




void Excluir (const std::string &filename, std::string palabrasexcluir)
{


    int cantp;
    cantp= cantpalabras(filename);
    std::string arreglopalabrasexcluir[cantp];
    std::string palabraexc;
    std::stringstream lineStream (palabrasexcluir);

    cantp = cantpalabras(filename);
    int i=0;
            while (std::getline(lineStream,palabraexc, ','))
            {
                palabraexc= corregirPalabra(palabraexc);
                arreglopalabrasexcluir[i]=palabraexc;
                i++;
            }


    std::ifstream file;
    file.open(filename,std::ios::in);


    HashMap<std::string, int> TH(cantp-i, &miHashFunc);

    if (file.is_open()) {
        std::string word, linea;

        while (std::getline(file, linea)) {

            std::stringstream lineStream(linea);
            while (std::getline(lineStream, word, ' ')) {
                word = corregirPalabra(word);

                 TH.put(word, 1 );


            }
        }
    }



    file.close();
    int arrn[cantp];
    std::string arrc[cantp];
    TH.arregloconocurrencias(arrn);
    TH.arregloconclaves(arrc, cantp);

    quickSort(arrn, arrc,   0, cantp-1);
    int bandera=0;

    for (int i=cantp-1; i>0; i--) {
        int h = 0;
        while (bandera == 0 && h < cantp) {
            if (arrc[i] == arreglopalabrasexcluir[h]) {
                bandera = 1; //lo quiero sacar del bucle

            }
            h++;
        }
        if (bandera == 0 && arrn[i] != -1){
            cout <<  arrc[i]  << arrn[i] << endl;}

        bandera = 0;
    }
}

#endif //PARCIAL2_SIMESVARTANIAN_OCURRENCIASEXCLUIRPALABRAS_H
