#include "../include/tranca.h"

#include <string>
#include <iostream>

using namespace std;

Tranca::Tranca(){
  ativa_=0;
}

void Tranca::SetNome(string name){
  nome_=name;
}

string Tranca::Nome(){
  return nome_;
}

void Tranca::SetAtiva(bool at){
  ativa_=at;    
}

bool Tranca::Ativa(){
  return ativa_;
}
