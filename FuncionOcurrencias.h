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
#include <sstream>
#include "Corregir.h"
#include "QuickSort.h"

using namespace std;

/* Code to sort array using shell sort */
void shellsort(int arrn[], std::string arrc[], int cantp)
{
    int i = 0, j = 0, k = 0, mid = 0;
    std::string midn;
    for (k = cantp / 2;k > 0;k /= 2)
    {
        for (j = k;j < cantp;j++)
        {
            for (i = j - k;i >= 0;i -= k)
            {
                if (arrn[i + k] >= arrn[i])
                {
                    break;
                }
                else
                {
                    mid = arrn[i];
                    midn=arrc[i];
                    arrn[i] = arrn[i + k];
                    arrc[i]=arrc[i+k];
                    arrn[i + k] = mid;
                    arrc[i+k]=midn;

                }
            }
        }
    }
    return;
}

//transformo los caracteres de la clave en numeros
unsigned int miHashFunc(string clave)
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
void Ocurrencias ( int n)
{
    string filename = "C:\\Users\\Usuario\\Desktop\\parcial 2\\Parcial2VartanianSimes\\texto";
    std::ifstream file;
    file.open(filename,std::ios::in);
    int cantp;
    //ver como tener la cant de palabras
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
int cantrepetidas=0;
int arrn[cantp];
std::string arrc[cantp];
cantrepetidas=TH.arregloconclaves(arrc, cantrepetidas); //corregir esto
TH.arregloconocurrencias(arrn);

cout<<"ahora cantidad de repetidas: "<<cantrepetidas<<endl;
//quickSort(arrn, arrc,   0, cantp-1);
shellsort(arrn, arrc, cantp);
cout<< "ORDENADO"<<endl;
    cout<<"n "<<n<<endl;
//cantp=cantp-cantrepetidas;
if (n==0)
{
    for (int i=cantp-1; i>0; i--)
    {
        if (arrn[i]!=-1)
            cout<<"CLAVE "<<arrc[i]<<" OCURRENCIAS: "<<arrn[i]<<endl;

    }

}
else if (n>0 && n<cantp)
{
    for (int i=cantp-1; i>cantp-1-n; i--)
    {
        if (arrn[i]!=-1)
            cout<<"CLAVE "<<arrc[i]<<" OCURRENCIAS: "<<arrn[i]<<endl;

    }
}

}


#endif //PARCIAL2_SIMESVARTANIAN_FUNCIONOCURRENCIAS_H
