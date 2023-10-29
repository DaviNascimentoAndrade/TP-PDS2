#include "../include/Lampada.h"

#include <string>
#include <iostream>

using namespace std;

Lampada::Lampada(){   
}

void Lampada::SetIntensidade(int i){
    if(i < 0 || i > 100){
        throw Intensidade_invalida{i};
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
       throw Cor_Invalida{c};
}

string Lampada::Cor(){
    return cor;
}

void Lampada::ListarCores(){
  for(auto it = cores.begin(); it != cores.end(); it++){
    std::cout << *it << endl;
}
}

void Lampada::SetNome(string name){
  nome = name;
}

string Lampada::Nome(){
    return nome;
}
