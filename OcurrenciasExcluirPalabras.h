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
//#include "ContadorPalabrasLetrasRenglones.h"
using namespace std;
void quickSort3(int  arrn[], std::string arrc[],  int menor, int mayor );


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
void Excluir (std::string palabra)
{
    cout<<"ENTRO A EXCLUIR UNA O UNAS PALABRAS"<<endl;
    string filename = "C:\\Users\\Usuario\\Documents\\2do UCC\\Parcial2-SimesVartanian\\texto";
    std::ifstream file;
    file.open(filename,std::ios::in);
    int cantp;
    //ver como tener la cant de palabras
    cantp = 34;


    HashMap<std::string, int> TH(cantp, &miHashFunc3);

    if (file.is_open()) {
        std::string word, linea;

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

    quickSort3(arrn, arrc,   0, cantp-1);



cout<<" la palabra q no se puede poner es "<<palabra<<endl;
        for (int i=cantp-1; i>0; i--)
        {
            if (arrn[i]!=-1 && arrc[i]!=palabra)
                cout<<"CLAVE "<<arrc[i]<<" OCURRENCIAS: "<<arrn[i]<<endl;

        }

}
void swap3(int arr[] , int pos1, int pos2){
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}
void swap23(std::string arr[] , int pos1, int pos2){
    std::string temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition3(int arr[], std::string arrc[],  int low, int high, int pivot){
    int i = low;
    int j = low;
    while( i <= high){
        if(arr[i] > pivot){
            i++;
        }
        else{
            swap3(arr,i,j);
            swap23(arrc, i, j);
            i++;
            j++;
        }
    }
    return j-1;
}

void quickSort3(int arr[], std::string arrc[],  int low, int high){
    if(low < high){
        int pivot = arr[high];
        int pos = partition(arr, arrc,  low, high, pivot);

        quickSort3(arr, arrc, low, pos-1);
        quickSort3(arr,arrc,  pos+1, high);
    }
}
#endif //PARCIAL2_SIMESVARTANIAN_OCURRENCIASEXCLUIRPALABRAS_H
