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
//#include "ContadorPalabrasLetrasRenglones.h"
using namespace std;
void quickSort(int  arrn[], std::string arrc[],  int menor, int mayor );


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
    string filename = "C:\\Users\\Usuario\\Documents\\2do UCC\\Parcial2-SimesVartanian\\texto";
    std::ifstream file;
    file.open(filename,std::ios::in);
    int cantp;
    //ver como tener la cant de palabras
    cantp = 34;


    HashMap<std::string, int> TH(cantp, &miHashFunc2);

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


    quickSort(arrn, arrc,   0, cantp-1);

    fstream file2;
    file2.open( igntext);
    std::string arrign[100];
    int j=0;

    if (file2.is_open()) {
        std::string word, linea;
        while (std::getline(file2, linea)) {
            std::stringstream lineStream (linea);
            while (std::getline(lineStream, word, ' '))
            {
                //guardemos cada palabra del texto ignorar en un arreglo
                cout<<"primer palabra a ignorar : "<<word<<endl;
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





void swap2(int arr[] , int pos1, int pos2){
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}
void swap22(std::string arr[] , int pos1, int pos2){
    std::string temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition2(int arr[], std::string arrc[],  int low, int high, int pivot){
    int i = low;
    int j = low;
    while( i <= high){
        if(arr[i] > pivot){
            i++;
        }
        else{
            swap2(arr,i,j);
            swap22(arrc, i, j);
            i++;
            j++;
        }
    }
    return j-1;
}

void quickSort2(int arr[], std::string arrc[],  int low, int high){
    if(low < high){
        int pivot = arr[high];
        int pos = partition2(arr, arrc,  low, high, pivot);

        quickSort2(arr, arrc, low, pos-1);
        quickSort2(arr,arrc,  pos+1, high);
    }
}

#endif //PARCIAL2_SIMESVARTANIAN_OCURRENCIASEXCLUIR_H
