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
//#include "ContadorPalabrasLetrasRenglones.h"
using namespace std;
void quickSort(int  arrn[], std::string arrc[],  int menor, int mayor );


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
    string filename = "C:\\Users\\Usuario\\Documents\\2do UCC\\Parcial2-SimesVartanian\\texto";
    std::ifstream file;
    file.open(filename,std::ios::in);
    int cantp;
    //ver como tener la cant de palabras
    cantp = 34;


HashMap<std::string, int> TH(cantp, &miHashFunc);

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

cout<<"Sin ordenar segun ocurrencias"<<endl;
file.close();
//otra forma hacer quicksort con array fuera de los metodos del hash
//voy a pedirle al hash q me traiga dos arreglos uno con las claves otro con ocurrencias
int cantrepetidas=0;
int arrn[cantp];
std::string arrc[cantp];
cantrepetidas=TH.arregloconclaves(arrc, cantrepetidas);
TH.arregloconocurrencias(arrn);


for (int i=0; i<cantp; i++)
{
if (arrn[i]!=-1) {

cout << "CLAVE: " << arrc[i] << " OCURRENCIAS: " << arrn[i] << endl;
}

}
cout<<"ahora cantidad de repetidas: "<<cantrepetidas<<endl;
quickSort(arrn, arrc,   0, cantp-1);
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
    cout<<"n "<<n<<endl;
    for (int i=cantp-1; i>cantp-1-n; i--)
    {
        if (arrn[i]!=-1)
            cout<<"CLAVE "<<arrc[i]<<" OCURRENCIAS: "<<arrn[i]<<endl;

    }
}

}
void swap(int arr[] , int pos1, int pos2){
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}
void swap2(std::string arr[] , int pos1, int pos2){
    std::string temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], std::string arrc[],  int low, int high, int pivot){
    int i = low;
    int j = low;
    while( i <= high){
        if(arr[i] > pivot){
            i++;
        }
        else{
            swap(arr,i,j);
            swap2(arrc, i, j);
            i++;
            j++;
        }
    }
    return j-1;
}

void quickSort(int arr[], std::string arrc[],  int low, int high){
    if(low < high){
        int pivot = arr[high];
        int pos = partition(arr, arrc,  low, high, pivot);

        quickSort(arr, arrc, low, pos-1);
        quickSort(arr,arrc,  pos+1, high);
    }
}


#endif //PARCIAL2_SIMESVARTANIAN_FUNCIONOCURRENCIAS_H
