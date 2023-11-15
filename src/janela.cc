#include "../include/janela.h"
#include<iostream>

using namespace std;

// cria uma janela sem nome
Janela::Janela(){
    tranca_ = 0;
    intensidade_ = 0;
}

// muda o nome da janela
void Janela::SetNome(string nm){
    nome_ = nm;
}

// retorna nome da janela
string Janela::Nome(){
    return nome_;
}

// muda intensidade da abertura da janela
void Janela::SetIntensidade(int in){
    if(in < 0 || in > 100){
        cout<< "A intensidade deve estar entre 0 e 100"<<endl;
    }
    else{
        intensidade_ = in;
    }
}

// retorna intensidade da janela
int Janela::Intensidade(){
    return intensidade_;
}

// muda a tranca da janela (0 aberto)
void Janela::SetTranca(bool tr){
    tranca_ = tr;
}

// retorna status da tranca da janela
bool Janela::Tranca(){
    return tranca_;
}