//
// Created by Usuario on 19/10/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_LISTA_H
#define PARCIAL2_SIMESVARTANIAN_LISTA_H
#include "NodoLista.h"

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Lista {
private:
    Nodo<T> *inicio;

public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, std::string dato, int ocurrencias);

    void insertarPrimero(std::string dato, int ocurrencias);

    void insertarUltimo(std::string dato, int ocurrencias );

    void remover(int pos);

    std::string getDato(int pos);

    int getOcurr (int pos);

    void reemplazar(int pos, std::string dato, int ocurrencias);

    void vaciar();

    void print();
    void ocurrencias(std::string clave );
};

/**
 * Constructor de la clase Lista
 * @tparam T
 */
template <class T> Lista<T>::Lista() { inicio = nullptr; }

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template <class T> Lista<T>::Lista(const Lista<T> &li) { inicio = li.inicio; }

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Lista<T>::~Lista() { vaciar(); }

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool Lista<T>::esVacia() { return inicio == nullptr; }

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T> int Lista<T>::getTamanio() {
    Nodo<T> *aux = inicio;
    int size = 0;

    while (aux != nullptr) {
        aux = aux->getSiguiente();
        size++;
    }

    return size;
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template <class T> void Lista<T>::insertar(int pos, std::string dato, int ocurrencias ) {
    int posActual = 0;
    Nodo<T> *aux = inicio, *nuevo;
    nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    nuevo->setOcurr(ocurrencias);

    if (pos == 0) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux != nullptr && posActual < pos - 1) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarPrimero(std::string dato, int ocurrencias ) { insertar(0, dato, ocurrencias); }

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarUltimo(std::string dato, int ocurrencias ) {
    Nodo<T> *aux = inicio, *nuevo;
    nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    nuevo->setOcurr(ocurrencias);

    if (aux == nullptr) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T> void Lista<T>::remover(int pos) {
    Nodo<T> *aux = inicio, *aBorrar;
    int posActual = 0;

    if (pos == 0) {
        inicio = inicio->getSiguiente();
        delete aux;
        return;
    }

    while (aux != nullptr && posActual < pos - 1) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    aBorrar = aux->getSiguiente();
    aux->setSiguiente(aBorrar->getSiguiente());

    delete aBorrar;
}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template <class T> std::string Lista<T>::getDato(int pos) {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    return aux->getDato();
}
template <class T> int Lista<T>::getOcurr(int pos) {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    return aux->getOcurr();
}
/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template <class T> void Lista<T>::reemplazar(int pos, std::string dato, int ocurrencias) {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    aux->setDato( dato );
    aux->setOcurr(ocurrencias);

}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template <class T> void Lista<T>::vaciar() {
    Nodo<T> *aux = inicio, *aBorrar;

    while( aux != nullptr ){
        aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }

    inicio = nullptr;

}

template<class T>
void Lista<T>::print() {
    Nodo<T> *aux = inicio;

    while (aux != nullptr) {
        std::cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    }
    std::cout << "NULL" << std::endl;
}
template<class T> void Lista<T>::ocurrencias(std::string clave) {
    //std::cout<<" efectivamente entro a la lista (dentro del metod)"<<std::endl;
    Nodo<T> *nodorecorrer = inicio;
    if (esVacia()) {
        //std::cout<<"la lista esta vacia asi q l;o inserta primero "<<std::endl;
        insertarPrimero(clave, 1);
    } else {
        //std::cout<<" la lista no es vaciaa, entro al else "<<std::endl;
        while (nodorecorrer->getSiguiente() != nullptr && nodorecorrer->getSiguiente()->getDato() != clave) {
            nodorecorrer = nodorecorrer->getSiguiente();
            //std::cout<<"entor al while "<<std::endl;

        }
      //  std::cout<<" el primer nodo de la lista es "<<nodorecorrer->getDato()<<std::endl;
        //std::cout<<" y la clave que quiero ingresar ahora es: "<<clave<<std::endl;
        //si sale del while quiere decir q llego al final de la lista o q llego al nodo anterior al del dato
        if (nodorecorrer->getDato() == clave) //si el dato del siguiente es igual a la clave
        {
            nodorecorrer->setOcurr(nodorecorrer->getSiguiente()->getOcurr() + 1);
        } else if (nodorecorrer->getDato() != clave) {
          //  std::cout<<"el siguiente es null y "<<std::endl;
            insertarUltimo(clave, 1);
        }
    }
    //std::cout<<" LO INSERTO EN LA LISTA "<<std::endl;
}
#endif //PARCIAL2_SIMESVARTANIAN_LISTA_H
