#include "../include/casa.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

Casa::Casa(){

}

void Casa::SetNome(string nm){
  nome_ = nm;
}

string Casa::Nome(){
  return nome_;
}

void Casa::ListarComodos(){
  for(auto it : comodos_){
    cout << "Cômodo: "<< it.first << endl;
    }
}

void Casa::AtivarModo(string nm){
    bool existe = false;             //testa se o modo existe
    for(auto it: modos_){
      if(it.first == nm){
        existe = true;
        break;;
      }
    }
  if(!existe){
    cout << "Esse modo não existe" << endl;
    return;
    }

    comodos_ = modos_[nm].comodos_;

}

void Casa::ListarModos(){
  for(auto it = modos_.begin(); it != modos_.end(); it++){
    cout << it->first;
  }
}

void Casa::AdicionarComodo(string nm){
  bool existe = false;             //testa se o nome já é usado no map
    for(auto it: comodos_){
      if(it.first == nm){
        existe = true;
        cout << "Esse cômodo já existe" <<endl;
        return;
      }
    }
    if(!existe){
    comodos_[nm];  //o map cria um valor apenas com uma chave, desde que ela não exista   
    }
    
}

void Casa::RemoverComodo(string nm){
 bool existe = false;             //testa se existe
    for(auto it: comodos_){
      if(it.first == nm){
        existe = true;
        comodos_.erase(nm);
        return;
      }
    }
    if(!existe){
    cout << "Esse cômodo não existe";  //o map cria um valor apenas com uma chave, desde que ela não exista   
    }
}