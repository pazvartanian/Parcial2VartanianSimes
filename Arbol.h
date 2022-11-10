//
// Created by Usuario on 24/10/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_ARBOL_H
#define PARCIAL2_SIMESVARTANIAN_ARBOL_H
#include<iostream>
#include "NodoArbol.h"
#include "Colisiones.h"
#include <algorithm>
#include <cctype>
#include <cstring>
#include "Corregir.h"
#include<stdio.h>


template <class T>
class ArbolBinario
{
protected:
    NodoArbol<T> *root;

public:
    ArbolBinario();

    void put(T data);

    T search(T data);

    void remover(T data);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinario();

    bool esVacio();

    void print();

    int contarPorNivel(int nivel);

    void insertar (string palabra);

    void inordenexcluir (int n);

    void excluirpu (std::string arreglo[]);

    /*int contarnodos (){
        int nodos=0;
        nodos=contarnodos(root);
        return nodos;
    };*/

    // void excluirfpu  (std::string arreglo[]);

private:
    T search(T data, NodoArbol<T> *r);
    NodoArbol<T> *put(T data, NodoArbol<T> *r);
    NodoArbol<T> *remove(T data, NodoArbol<T> *r);
    NodoArbol<T> *findMaxAndRemove(NodoArbol<T> *r, bool *found);
    void preorder(NodoArbol<T> *r);
    void inorder(NodoArbol<T> *r);
    void inordern(NodoArbol<T> *r, int n, int cont);
    void postorder(NodoArbol<T> *r);
    int contarPorNivel(int nivel, NodoArbol<T> *auxNodo);
    bool palabraRepetida (NodoArbol<T> *r, string palabra);
    std::string corregirPalabra (std::string palabra);
    void inexc (NodoArbol<T> *r, int n);
    void excluirpri (NodoArbol<T> *r, string arreglo[]);
    bool estaPalabraEnArreglo (string palabra, std::string arreglo[]);
    int contarnodos (NodoArbol<T> *r);

};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T>
ArbolBinario<T>::ArbolBinario() { root = nullptr; }

/**
 * Destructor del Arbol
 */
template <class T>
ArbolBinario<T>::~ArbolBinario() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T>
T ArbolBinario<T>::search(T data)
{
    return search(data, root);
}

template <class T>
T ArbolBinario<T>::search(T data, NodoArbol<T> *r)
{
    if (r == nullptr)
    {
        throw 404;
    }

    if (r->getData() == data)
    {
        return r->getData();
    }

    if (r->getData() > data)
    {
        return search(data, r->getLeft());
    }
    else
    {
        return search(data, r->getRight());
    }
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T>
void ArbolBinario<T>::put(T data) { root = put(data, root); }

template <class T>
NodoArbol<T> *ArbolBinario<T>::put(T data, NodoArbol<T> *r)
{
    if (r == nullptr)
    {
        return new NodoArbol<T>(data);
    }

    if (r->getData() == data)
    {
        //si el dato esta repetido deberiamos aumentar en uno las ocurrencias
        r->setOcurrencias();
        throw 200;
    }

    if (r->getData() > data)
    {
        r->setLeft(put(data, r->getLeft()));
    }
    else
    {
        r->setRight(put(data, r->getRight()));
    }

    return r;
}

/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template <class T>
void ArbolBinario<T>::remover(T data)
{
    //iguala la raiz a la funcion pq al ser recursivo es como si volviera hacia atras y llegara hasta el inicio y root seguira siendo root

    root = remove(data, root);
}

template <class T>
NodoArbol<T> *ArbolBinario<T>::remove(T data, NodoArbol<T> *r)
{
    NodoArbol<T> *aux;

    if (r == nullptr)
    {
        throw 404;
    }

    if (r->getData() == data)
    {
        //que para ambos lafos no haya nada
        if (r->getLeft() == nullptr && r->getRight() == nullptr)
        {
            delete r;
            return nullptr;
        }
            //q solo haya para unm lado
        else if (r->getLeft() != nullptr && r->getRight() == nullptr)
        {
            //amtes de borrarlo lo guardamos en un auxiliar para luego de borrarlo no perder su decendencia
            aux = r->getLeft();
            delete r;
            return aux;
        }
        else if (r->getLeft() == nullptr && r->getRight() != nullptr)
        {
            aux = r->getRight();
            delete r;
            return aux;
        }
            //q haya para los dos lados
        else if (r->getLeft() != nullptr && r->getRight() != nullptr)
        {

            if (r->getLeft()->getRight() != nullptr)
            {
                // Aca tenemos que buscar el valor maximo (osea q npo tenga nada a la dere)
                //entonces lo seteamos dond3e borramos el r, para la derecha tendra el q tenia a la derecha r
                // y a la iz la izq d r
                bool found;
                aux = findMaxAndRemove(r->getLeft(), &found);
                //este algoritmo busca el maximo a la derecha
                //osea q a su derecha no tenga nada y se encarga de q lo estaba a la izq lo ponga  la derecha del anterior, yua q es mayor

                aux->setRight(r->getRight());
                //el d la derecha de este maximo q acabamos d encontrar sera la derecha d r al igual  qla izq
                aux->setLeft(r->getLeft());
            }
            else
            {
                aux = r->getLeft();
                r->getLeft()->setRight(r->getRight());
            }
            delete r;
            return aux;
        }
    }
    else if (r->getData() > data)
    {

        r->setLeft(remove(data, r->getLeft()));
    }
    else
    {
        r->setRight(remove(data, r->getRight()));
    }

    return r;
}
/* mis casos para borrar cuando del nodo salenj dos hojas son dos opciones
1) r es el que quiero borrar, el aux va a ser el ezqieuirdo de r y le voy a setear
la derecha de r, y luego borrar r
 2) el nodo izquierdo de r tiene dos hijos/ramas (izq y derecho) voy a hacer una busqueda de maximos en
 los minimos, recorro hasta encontrar el que apunte a null
 */
template <class T>
NodoArbol<T> *ArbolBinario<T>::findMaxAndRemove(NodoArbol<T> *r, bool *found)
{
    NodoArbol<T> ret; // es el maximo que quiero encontrar
    *found = false;
//condicion base (encontro el maximo)
    if (r->getRight() == nullptr) //si a la derecha no hay nada entonces es el maximo
    {
        *found = true;
        return r;
    }
//si no lo encontre lo vuelvo a buscar recursivamente
    ret = findMaxAndRemove(r->getRight(), found);

    // salio de la funcion pq toco return r
    if (*found)
    {
        r->setRight(nullptr);
        *found = false;
    }

    return ret;
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T>
bool ArbolBinario<T>::esVacio() { return root == nullptr; }

/**
 * Recorre un árbol en preorden
 */
template <class T>
void ArbolBinario<T>::preorder()
{
    preorder(root);
     std::cout << "\n" << std::flush;
}

template <class T>
void ArbolBinario<T>::preorder(NodoArbol<T> *r)
{
    if (r == nullptr)
    {
        return;
    }

    std::cout << r->getData() << " ";
    preorder(r->getLeft());
    preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
template <class T>
void ArbolBinario<T>::inorder()
{

    inorder(root);

    std::cout << "\n" << std::flush;

}

template <class T>
void ArbolBinario<T>::inorder(NodoArbol<T> *r)
{

    if (r == nullptr)
    {
        return;
    }

    inorder(r->getLeft());
    std::cout << r->getData() << " ";
    inorder(r->getRight());
}


template <class T>
void ArbolBinario<T>::inordern(NodoArbol<T> *r, int n, int cont)
{

    if (r == nullptr || cont==n)
    {
        return;
    }

    inordern(r->getLeft(), n, cont++);
    std::cout << r->getData() << " ";
    inordern(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
template <class T>
void ArbolBinario<T>::postorder()
{
    postorder(root);
    std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::postorder(NodoArbol<T> *r)
{
    if (r == nullptr)
    {
        return;
    }

    postorder(r->getLeft());
    postorder(r->getRight());
    std::cout << r->getData() << " ";
}

/**
 * Muestra un árbol por consola
 */
template <class T>
void ArbolBinario<T>::print()
{
    if (root != NULL)
        root->print(false, "");
}

template <class T> int ArbolBinario<T>::contarPorNivel(int nivel) {
    return contarPorNivel(nivel, root);
}

template <class T> int ArbolBinario<T>::contarPorNivel(int nivel, NodoArbol<T> *auxNodo) {

    if(auxNodo==NULL)
        return 0;
    if (nivel == 0)
        return 1;
    return contarPorNivel(nivel-1, auxNodo->getLeft()) + contarPorNivel(nivel-1, auxNodo->getRight());
}

template <class T> bool ArbolBinario<T>::palabraRepetida(NodoArbol<T> *r, string palabra)
{
    if (r == nullptr)
    {
        return false;
    }else if (palabraRepetida(r->getLeft(), palabra)) {
        //si devuelve verdadero
        return true;
    } else if (r->getData()==palabra){
        //si en el subarbol izquierdo no esta la palabra reviso en la raiz
        return true;
    }else if (palabraRepetida(r->getRight(),palabra)) {
        // si tampoco esta en la raiz reviso el subarbol derecho
        return true;
    } else {
        return false;
        // no esta en ese subarbol.
    }
}

template<class T> std::string ArbolBinario<T>::corregirPalabra (std::string palabra) {
    // vamos a correguir la palabra para mostarlas sin signos de explamacion, interrogacion ni putuacion
    //recorremos toda la palabra y borramos signos .
    std::string caracteres = "?.!;¿¡,-:()$#@%`+=^_[]{}<>" ;

    for (char c: caracteres) {
        palabra.erase(std::remove(palabra.begin(), palabra.end(), c), palabra.end());
        //.erase es una tecnica que usamos paa eliminar los caracteres declarados antes
    }
    for (int i=0; i<palabra.length(); i++){
        palabra[i]= tolower(palabra[i]);}
    return palabra;


}

template<class T> void ArbolBinario<T>::insertar(std::string palabra) {
    //lo vamos a insertar en orden
    palabra = corregirPalabra(palabra);
    NodoArbol<string> *nuevo=new NodoArbol<string>(palabra);
    // ya creo un nuevo nodo con la palabra que le va a corresponder

    //vemos si el arbol esta vacio
    if (this->root == NULL){
        this->root = nuevo;
    } else if (!this->palabraRepetida(this->root, palabra)){
        //creo un nodo anterior y uno para recorrer
        NodoArbol<string> *anterior = NULL;
        NodoArbol<string> *recorrer = this->root;



        while (recorrer != NULL) {
            anterior = recorrer;
            if (palabra < recorrer->getData() ) {
                // me voy a la izquierda
                recorrer = recorrer->getLeft();
            } else {
                recorrer = recorrer->getRight();
            }
            //recorro el arbol como quiero insertar, hasta que llegue al lugar vacio que es donde inserto
        }

        if (palabra < anterior->getData()) {
            //lo inserto izquierda
            anterior->setLeft(nuevo);
        } else {
            anterior->setRight(nuevo);
        }
    }

}

template <class T> void ArbolBinario<T>::inordenexcluir(int  n) {
    inexc(root, n);
    cout<<"\n";
}

template<class T> void ArbolBinario<T>::inexc(NodoArbol<T> *r, int n) //privado
{

    static int contador = 0;

    if (r == nullptr)
    {
        return;
    }

    if(contador <= n) {
        inexc(r->getLeft(), n);
        contador++;

        if(contador <= n + 1) {
            std::cout << r->getData() << " ";
        }

        inexc(r->getRight(), n);
    }
}

template<class T> void ArbolBinario<T>::excluirpu(std::string arreglo[]) {
    // vamos a llamar al privado para pasarle la raiz
    excluirpri(root, arreglo);
}
//esta funcion es para ver si la palabra esta en el arreglo
template<class T> bool ArbolBinario<T>:: estaPalabraEnArreglo (std::string palabra, std::string arreglo[]){
    int i=0;
    bool esta = false;


    while(i<50 && !esta){
        if(arreglo[i] == palabra){
            esta=true;
        }
        i++;
    }
    return esta;
}

template<class T> void ArbolBinario<T>:: excluirpri (NodoArbol<T> *r, std::string arreglo[]) {
    if (r == nullptr) {
        return;
    }

    // para que imprima alfabeticamente
    excluirpri(r->getLeft(), arreglo);
    //si no esta en el arreglo la podemos imprimir
    if (!estaPalabraEnArreglo(r->getData(), arreglo)) {
        std::cout << r->getData() << " ";
    }
    excluirpri(r->getRight(), arreglo);
}
    //imprime izquierda, raiz y derecha lo hace en caso que la palabra no este en el arreglo.
    //si da flaso la palabra en el arreglo imprimir el dato

    /*template<class T> int ArbolBinario<T>::contarnodos(NodoArbol<T> *r)
    {
        if ( r != nullptr){
            return 1+ contarnodos(r->getLeft()) + contarnodos(r->getRight());
        }
        return 0;
    }
     */

#endif //PARCIAL2_SIMESVARTANIAN_ARBOL_H
