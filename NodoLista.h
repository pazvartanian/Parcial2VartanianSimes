//
// Created by Usuario on 19/10/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_NODOLISTA_H
#define PARCIAL2_SIMESVARTANIAN_NODOLISTA_H
template<class T>
class Nodo{
private:
    std::string dato;
    Nodo<T> *siguiente;
    int ocurr;

public:
    std::string getDato(){
        return dato;
    }

    void setDato(std::string d){
        dato = d;
    }

    int getOcurr(){
        return ocurr;
    }
    void setOcurr (int o){
        ocurr=o;
    }
    Nodo<T> *getSiguiente(){
        return siguiente;
    }

    void setSiguiente(Nodo<T> *siguiente){
        this->siguiente = siguiente;
    }


};
#endif //PARCIAL2_SIMESVARTANIAN_NODOLISTA_H
