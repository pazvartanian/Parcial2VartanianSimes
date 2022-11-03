//
// Created by Usuario on 23/10/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_OCURRENCIASEXCLUIR_H
#define PARCIAL2_SIMESVARTANIAN_OCURRENCIASEXCLUIR_H
#include<iostream>
#include <string>
#include<fstream>
#include "HashMap.h"
#include <map>
#include <sstream>
#include "Corregir.h"
#include "QuickSort.h"
using namespace std;


//transformo los caracteres de la clave en numeros
unsigned int miHashFunc2(string clave)
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
void Excluirf (const std::string &igntext)
{
    cout<<"ENTRO A EXCLUIR "<<endl;
    string filename = "C:\\Users\\Usuario\\Desktop\\parcial 2\\Parcial2VartanianSimes\\texto";
    std::ifstream file;
    file.open(filename,std::ios::in);
    int cantp;
    //ver como tener la cant de palabras
    cantp = cantpalabras(filename);


    HashMap<std::string, int> TH(cantp, &miHashFunc2);

    if (file.is_open()) {
        std::string word, linea;
//no estoy segura q son las cosas entre parentesis
        while (std::getline(file, linea)) {

            std::stringstream lineStream(linea);
            while (std::getline(lineStream, word, ' ')) {
                word=corregirPalabra(word);

                TH.put(word, 1);

            }
        }
    }
    file.close();
//otra forma hacer quicksort con array fuera de los metodos del hash
//voy a pedirle al hash q me traiga dos arreglos uno con las claves otro con ocurrencias
    int cantrepetidas=0;
    int arrn[cantp];
    std::string arrc[cantp];
    cantrepetidas=TH.arregloconclaves(arrc, cantrepetidas);
    TH.arregloconocurrencias(arrn);


    quickSort(arrn, arrc,   0, cantp-1);

    fstream file2;
    file2.open( igntext);
    std::string arrign[cantp];
    int j=0;

    if (file2.is_open()) {
        std::string word, linea, nuevaword;
        while (std::getline(file2, linea)) {
            std::stringstream lineStream (linea);
            while (std::getline(lineStream, word, ' '))
            {
                word= corregirPalabra(word);
                TH.put(word, 1);
                //guardemos cada palabra del texto ignorar en un arreglo
                cout<<"primer palabra a ignorar : "<<nuevaword<<endl;
                arrign[j]=word;
                j++;
            }
            }
        }
    //para leer el texto que compare cada palabra del arreglo orgininal on las del arreglo excliuir
    int bandera=0;
    for (int i=cantp-1; i>0; i--)
    {
        int h=0;
        while (bandera==0 && h<cantp) {
                if (arrc[i] == arrign[h]) {
                    bandera = 1;
                    //quiero q salga del bucle
                }

            h++;
        }
        if (bandera==0 && arrn[i]!=-1)
        {
            cout << "CLAVE " << arrc[i] << " OCURRENCIAS: " << arrn[i] << endl;
        }
        bandera=0;


    }


    }


#endif //PARCIAL2_SIMESVARTANIAN_OCURRENCIASEXCLUIR_H
