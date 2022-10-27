//
// Created by Usuario on 19/10/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_HASHMAP_H
#define PARCIAL2_SIMESVARTANIAN_HASHMAP_H
#include "HashEntry.h"
#include<iostream>
#include <cstddef>
#include <string>
#include "Lista.h"
#include "NodoLista.h"
#include "Colisiones.h"

//Función HASH realiza alguna operación (la que querramos)
//al parámetro pasado por argumeto para codificarla o encriptarla.
//Devuelve un valor entero entre 0 y el tamaño de la tabla hash menos uno.
//Ese es el índice!
//Toda tabla hash tiene un tamaño preDefinido. Estructura ESTÁTICA.
//La Tabla no aplica ningún ordenamiento como lo hacen los árboles y
//demás estructuras.



template<class K, class T> class HashMap {

private:
    /**
     * Cada HashENtry es una fila de la tabla.
     */
    HashEntry<K, T> **tabla;//puntero a puntero. Convertiremos a un arreglo de punteros.

    unsigned int tamanio;//Tamaño de tabla

    //Función Hash.
    /**
     * static para poderla invocar por fuera de la
     * clase sin crear un objeto de la clase.
     * @param clave
     * @return el índice
     */
    static unsigned int hashFunc(K clave);

    //puntero a función. Dirección de memoria de función.
    //Permite cambiar de una a otra función hash.
    unsigned int (*hashFuncP)(K clave);

    Lista<T> listacolisiones4;


public:
    //tipo de dato explicit: elconstructor de tipo de dato explícito
    // permite generar una instancia de la clase pasando por
    //parámetro sin tener que definir un puntero.
    explicit HashMap(unsigned int k);//k: tamaño de tabla.

    //Constructor con puntero a función hash pasado por parámetro.
    HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave));

//Devuelve el dato a partir de la clave. COmo un array. De manera
//inmediata aunque dependiente de la cant de colisiones y el factor
// de carga: ocupación de la tabla en relación la cantidad total
// de lugares en la tabla.
/**
* Devuelve el dato a partir de la clave. COmo un array. De manera
* inmediata aunque dependiente de la cant de colisiones y el
 * factor de carga: ocupación de la tabla en relación la
 * cantidad total de lugares en la tabla.
 * @param clave
 * @return
 */
    T get(K clave);

    /**
     * Inserta un valor en una posición obtenido el función hash
     * @param clave
     * @param valor
     */
    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool esVacio();

    void print();

    void arregloconocurrencias (T arrn[]);

   int arregloconclaves (K arrc[], int cantp);

   // int rellenoArreglos (int ArrN[], std::string C[]);



};

template <class K, class T>
HashMap<K, T>::HashMap(unsigned int k) { //Constructor que acepta por parámetro el tamaño de la tabla
    tamanio = k;
    //Un arreglo de tamaño tamanio de punteros. Cada puntero es una fila de la tabla
    tabla = new HashEntry<K, T> *[tamanio];

    //Inicializamos las filas
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
    //Función de Hash por defecto
    hashFuncP = hashFunc;
}

template<class K, class T>
HashMap<K, T>::HashMap(unsigned int k, unsigned int (*fp)(K)) {
    tamanio = k;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
    hashFuncP = fp; //Función de Hash aceptada por parámetro
}

template<class K, class T>
HashMap<K, T>::~HashMap() {
    for (int i = 0; i < tamanio; i++) {
        if (tabla[i] != NULL) {
            delete tabla[i];
        }
    }
}

template<class K, class T>
T HashMap<K, T>::get(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;//operación módulo

    //Corroboramos si en esa posición
    if (tabla[pos] == NULL) {
        throw 404;
    }
    //obtenida la posición se busca dato
    return tabla[pos]->getValor();
}

template<class K, class T>
void HashMap<K, T>::put(K clave, T valor) {

    unsigned int pos = hashFuncP(clave) % tamanio;
    int keyrepetida = pos;
    int bandera = 0;


    if (tabla[pos] != NULL) {

        //MANEJO DE COLISIÓN NECESARIO!!!
        if (tabla[pos]->getClave() == clave) {

            //si ya existe esa clave entonces que le agregue uno a su valor
            tabla[pos]->setValor(tabla[pos]->getValor() + 1);

            return;
        } else {
            pos = Colisiones(clave) % tamanio;

            if (tabla[pos] != NULL) {

                if (tabla[pos]->getClave() == clave) {
                    tabla[pos]->setValor(tabla[pos]->getValor() + 1);
                    return;
                } else {
                    pos = Colisiones2(clave) % tamanio;

                    if (tabla[pos] != NULL) {

                        if (tabla[pos]->getClave() == clave) {
                            tabla[pos]->setValor(tabla[pos]->getValor() + 1);

                            return;
                        } else {
                            pos = Colisiones3(clave) % tamanio;


                            if (tabla[pos] != NULL) {

                                if (tabla[pos]->getClave() == clave) {

                                    tabla[pos]->setValor(tabla[pos]->getValor() + 1);

                                    return;
                                } //aca deberia agregar el metodo de la lista agregar nodo courrencias a la lista y agregar una lista a la fila del hash q simule tener otra fila per en relidad sea un nodo
                                else {

                                    listacolisiones4.ocurrencias(clave);
                                    bandera = 1;

                                }

                            }
                        }
                    }

                }
            }
        }
    }

    if (bandera == 0) {
        tabla[pos] = new HashEntry<K, T>(clave, valor); //Corresponde a una nueva fila en la tabla

    }
}


template<class K, class T>
void HashMap<K, T>::remove(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;
    tabla[pos] = NULL;
}

template<class K, class T>
bool HashMap<K, T>::esVacio() {
    for (int i = 0; i < tamanio; i++) {
        if (tabla[i] != NULL) { //Si al menos una de sus filas es != a nulo
            return false; //No es vacía
        }
    }
    return true;
}

template<class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave) { //Función de Hash por defecto
    return (unsigned int) clave; //Funciona sólo si K = int
}

template<class K, class T>
void HashMap<K, T>::print() {
    std::cout << "i" << "\t" << "Clave" << "\t" << "Valor" << std::endl;
    std::cout << "---------------------" << std::endl;
    for (int pos = 0; pos < tamanio; pos++) {
        std::cout << pos << "\t";
        if (tabla[pos] != NULL) {
            std::cout << tabla[pos]->getClave() << "\t";
            std::cout << tabla[pos]->getValor();
        }
        std::cout << std::endl;
    }
}

//metodo q m devuelva arreglo con ocurrencuas
template<class K, class T>
void HashMap<K, T>::arregloconocurrencias(T arrn[]) {
    for (int i = 0; i < tamanio; i++) {

        if (tabla[i] != NULL) {
            arrn[i] = tabla[i]->getValor();
        }else if (!listacolisiones4.esVacia()){
            arrn[i] = listacolisiones4.getOcurr(0);

            listacolisiones4.remover(0);

        }
        else if (tabla[i]==NULL)
        {
            arrn[i]= -1;
        }

    }

}
template<class K, class T>
int HashMap<K, T>::arregloconclaves(K *arrc, int cantrepetidas) {

    for (int i = 0; i < tamanio; i++) {

        if (tabla[i] != NULL) {
            arrc[i] =tabla[i]->getClave();
        }else if (!listacolisiones4.esVacia()) {
            arrc[i] = listacolisiones4.getDato(0);

            listacolisiones4.remover(0);
        }
        else {
            arrc[i]= " NULL";
            cantrepetidas++;
        }

    }
    return cantrepetidas;

}


/* template <class K, class T> int HashMap<K,T>::rellenoArreglos(int arregloOcu[], std:: string arregloPal[]) {
    int contador= 0 ;

    for (int i=0; i<tamanio; i++){
        if (tabla[i] != NULL){
            arregloOcu[i] = tabla[i]->getValor();
            arregloPal[i] = tabla[i] ->getClave();
        } else {
            arregloOcu[i]= -1;
            arregloPal[i]= "NULL" ;

            contador++ ;
        }
    }
    return contador ;
}
 */

#endif //PARCIAL2_SIMESVARTANIAN_HASHMAP_H

//pq funciona el put solo con algunas palabfas