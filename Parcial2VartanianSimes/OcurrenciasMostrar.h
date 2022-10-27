//
// Created by Usuario on 23/10/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_OCURRENCIASMOSTRAR_H
#define PARCIAL2_SIMESVARTANIAN_OCURRENCIASMOSTRAR_H
#include<iostream>
#include <string>
#include<fstream>
#include "HashMap.h"
#include <map>
#include <sstream>
//#include "ContadorPalabrasLetrasRenglones.h"
using namespace std;
void quickSort4(int  arrn[], std::string arrc[],  int menor, int mayor );


//transformo los caracteres de la clave en numeros
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
void Mostrar (std:: string palabra)
{
    cout<<"ENTRO A MOSTRAR"<<endl;
    string filename = "C:\\Users\\Usuario\\Documents\\2do UCC\\Parcial2-SimesVartanian\\texto";
    std::ifstream file;
    file.open(filename,std::ios::in);
    int cantp;
    //ver como tener la cant de palabras
    cantp = 34;


    HashMap<std::string, int> TH(cantp, &miHashFunc4);

    if (file.is_open()) {
        std::string word, linea;
//no estoy segura q son las cosas entre parentesis
        while (std::getline(file, linea)) {

            std::stringstream lineStream(linea);
            while (std::getline(lineStream, word, ' ')) {

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




    quickSort4(arrn, arrc,   0, cantp-1);

        for (int i=cantp-1; i>0; i--)
        {
            if (arrn[i]!=-1 && arrc[i]==palabra)
                cout<<"CLAVE "<<arrc[i]<<" OCURRENCIAS: "<<arrn[i]<<endl;

        }




}
void swap4(int arr[] , int pos1, int pos2){
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}
void swap24(std::string arr[] , int pos1, int pos2){
    std::string temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition4(int arr[], std::string arrc[],  int low, int high, int pivot){
    int i = low;
    int j = low;
    while( i <= high){
        if(arr[i] > pivot){
            i++;
        }
        else{
            swap4(arr,i,j);
            swap24(arrc, i, j);
            i++;
            j++;
        }
    }
    return j-1;
}

void quickSort4(int arr[], std::string arrc[],  int low, int high){
    if(low < high){
        int pivot = arr[high];
        int pos = partition(arr, arrc,  low, high, pivot);

        quickSort4(arr, arrc, low, pos-1);
        quickSort4(arr,arrc,  pos+1, high);
    }
}
#endif //PARCIAL2_SIMESVARTANIAN_OCURRENCIASMOSTRAR_H
