#include <iostream>
#include "include/arcondicionado.h"

using namespace std;

int main(){
  ArCondicionado teste;
  teste.SetNome("joao");
  cout << "O nome do aparelho é " << teste.Nome() << endl;
  teste.SetModo("cool");
  cout << "O modo do aparelho é " << teste.Modo() << endl;
  teste.SetLigar(true);
  cout << "O estado do aparelho é: " << teste.Ligado() << endl;
  teste.SetTemperatura(22);
  cout << "A temperatura do aparelho é " << teste.Temperatura() << endl;

}
