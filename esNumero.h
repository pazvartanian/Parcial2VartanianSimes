//
// Created by Usuario on 03/11/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_ESNUMERO_H
#define PARCIAL2_SIMESVARTANIAN_ESNUMERO_H
#include<iostream>
bool esNumero(const std::string &num){
    for (auto &c: num){
        if (std::isdigit(c)==0) return false;

    }
    return true;
}
#endif //PARCIAL2_SIMESVARTANIAN_ESNUMERO_H
