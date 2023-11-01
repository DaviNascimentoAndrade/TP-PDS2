#include "../include/cortina.h"
#include <iostream>
#include <string>

using namespace std;
  Cortina::Cortina(){
      intensidade_cortina_ = 0;
    }
    void Cortina::SetIntensidade(int novaIntensidade) {
      if (novaIntensidade >= 0 && novaIntensidade <= 100) {
          intensidade_cortina_ = novaIntensidade;
        } 
      else {
          cout << "A intensidade deve estar entre 0 e 100." <<endl;
        }
    }
    int Cortina::Intensidade() {
      return intensidade_cortina_;
    }
    string Cortina::Nome(){
      return nome_;
    }
    void Cortina::SetNome(string novoNome){
      nome_ = novoNome;
    } 