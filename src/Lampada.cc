#include "../include/Lampada.h"

#include <string>
#include <iostream>

using namespace std;

void Lampada::SetIntensidade(int i){
    if(i >= 0 || i <= 100){
        intensidade = i;
    }
    else{
       std::cout <<"O valor inserido não é válido. Por favor, insira um número de 0 a 100" << endl;
    }
}

int Lampada::Intensidade(){
    return intensidade;
}

void Lampada::SetCor(string c){
    if(c == "amarelo" || c == "vermelho" || c == "azul" || c == "roxo"
     || c == "branco" || c == "laranja" || c == "verde")
     { 
        cor = c;
    }
    else{
       std::cout <<"Cor inválida. Por favor, insira uma das cores válidas";
    }
}

string Lampada::StatusCor(){
    return cor;
}