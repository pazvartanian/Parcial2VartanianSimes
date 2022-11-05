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
//#include "ContadorPalabrasLetrasRenglones.h"
using namespace std;



//transformo los caracteres de la clave en numeros
unsigned int miHashFunc3(string clave)
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
void Excluir (const std::string &filename, std::string palabrasexcluir)
{
    cout<<"ENTRO A EXCLUIR UNA O UNAS PALABRAS"<<endl;

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
            cout<<"Las palabras a excluir son: "<<endl;

        for (int j=0; j<i; j++)
        {
            cout<<arreglopalabrasexcluir[j]<<endl;
        }


    std::ifstream file;
    file.open(filename,std::ios::in);


    HashMap<std::string, int> TH(cantp, &miHashFunc3);
    int bandera=0;
    if (file.is_open()) {
        std::string word, linea;

        while (std::getline(file, linea, ' ')) {

            std::stringstream lineStream(linea);
            while (std::getline(lineStream, word, ' ')) {
                word = corregirPalabra(word);

                for (int j=0; j<i; j++){
                    if (word==arreglopalabrasexcluir[j])
                    {
                        bandera=1;
                    }
                }
                if (bandera!=1)
                {
                    TH.put(word, 1); //recorre el arreglo de las palabras aexcluir y si esta pone al abnderfa en 1

                }
                bandera=0;
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

    shellsort(arrn, arrc, cantp);

        for (int i=cantp-1; i>0; i--)
        {
            if (arrn[i]!=-1)
                cout<<"CLAVE "<<arrc[i]<<" OCURRENCIAS: "<<arrn[i]<<endl;
        }

}

#endif //PARCIAL2_SIMESVARTANIAN_OCURRENCIASEXCLUIRPALABRAS_H
