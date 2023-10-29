#include "../include/tranca.h"

#include <string>
#include <iostream>

using namespace std;

Tranca::Tranca(){   
}

void Tranca::SetNome(string name){
  nome=name;
}

string Tranca::Nome(){
  return nome;
}

void Tranca::SetAtiva(bool at){
  ativa=at;    
}

bool Tranca::Ativa(){
  return ativa;
}
