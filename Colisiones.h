//
// Created by Usuario on 20/10/2022.
//
#ifndef PARCIAL2_SIMESVARTANIAN_COLISIONES_H
#define PARCIAL2_SIMESVARTANIAN_COLISIONES_H

#include <iostream>
#include <string>
#include<cmath>
#include <cctype>
#include <cstring>

int Colisiones (std::string clave);

int Colisiones (std::string clave){


    int key=0;
    const int  p=37;
    const int  m=1e9 + 9;
    long p_pow = 1 ;
    //le da valor a la key
    for (int i=0; i<clave.length(); i++){
        clave[i]= tolower(clave[i]);
        key = (key + (clave[i] - 'a' + 1 ) * p_pow) % m ; //tolower nos cambia a minuscula
        p_pow = (p_pow * p )% m ;
    }
    return key;


}
int Colisiones2 (std::string clave )
{
    int key=0;
    const int  p=26;
    const int  m=1e9 + 5;
    long p_pow = 1 ;
    //le da valor a la key
    for (int i=0; i<clave.length(); i++){
        clave[i]= tolower(clave[i]);
        key = (key + (clave[i] - 'a' + 1 ) * p_pow) % m ; //tolower nos cambia a minuscula
        p_pow = (p_pow * p )% m ;
    }
    return key;
}int Colisiones3 (std::string clave )
{
    int key=0;
    const int  p=89;
    const int  m=1e9 + 12;
    long p_pow = 1 ;
    //le da valor a la key
    for (int i=0; i<clave.length(); i++){
        clave[i]= tolower(clave[i]);
        key = (key + (clave[i] - 'a' + 1 ) * p_pow) % m ; //tolower nos cambia a minuscula
        p_pow = (p_pow * p )% m ;
    }
    return key;
}
// esta la funcion la usamos para cuando hay una clave repetida, volvemos a meter la palabra repetida para generar una nueva clave

#endif //PARCIAL2_SIMESVARTANIAN_COLISIONES_H
