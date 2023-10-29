#include "../include/Lampada.h"

#include <string>
#include <iostream>

using namespace std;

Lampada::Lampada(){   
}

void Lampada::SetIntensidade(int i){
    if(i < 0 || i > 100){
        throw Intensidade_inválida{i};
    }
    else{
       intensidade = i;
    }
}

int Lampada::Intensidade(){
    return intensidade;
}

void Lampada::SetCor(string c){
    bool valido = false;
    for(auto it = cores.begin(); it != cores.end(); it++){
        if(c == *it){
            c == *it;
            valido = true;
        }
    }
    if(!(valido))
       throw Cor_Inválida{c};
}

string Lampada::StatusCor(){
    return cor;
}