#include "../include/lampada.h"

#include <string>
#include <iostream>

using namespace std;

Lampada::Lampada(){
  intensidade_ = 0;
}

void Lampada::SetIntensidade(int i){
  if(i < 0 || i > 100){
    cout<< "A intensidade deve estar entre 0 e 100"<<endl;
    }
  else{
    intensidade_ = i;
    }
}

int Lampada::Intensidade(){
  return intensidade_;
}

void Lampada::SetCor(string c){
  bool valido = false;
  for(auto it = cores_.begin(); it != cores_.end(); it++){
    if(c == *it){
      cor_ = *it;
      valido = true;
    }
  }
  if(!(valido)){
    cout<< "Cor inválida, consulte as cores disponíveis"<<endl;
  }
}

string Lampada::Cor() {
  return cor_;
}

void Lampada::ListarCores(){
  for(auto it = cores_.begin(); it != cores_.end(); it++){
    std::cout << *it << endl;
}
}

void Lampada::SetNome(string name){
  nome_ = name;
}

string Lampada::Nome(){
  return nome_;
}
