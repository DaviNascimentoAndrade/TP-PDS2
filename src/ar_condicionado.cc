#include "../include/ar_condicionado.h"

#include <string>
#include <iostream>

using namespace std;

 ArCondicionado::ArCondicionado(){
 }
 void ArCondicionado::SetNome(string nome){
  nome_ = nome;
 }
 string ArCondicionado::Nome(){
  return nome_;
 }
 void ArCondicionado::SetIntensidade(int in){
  if(in >= 0 && in <= 100){
  intensidade_ = in;
  }
  else{
  cout << "Intensidade inválida, selecione um valor de 0 a 100";
  }
 }
 int ArCondicionado::Intensidade(){
  return intensidade_;
 }
 void ArCondicionado::SetLigar(bool li){
  ligado_ = li;
 }
 bool ArCondicionado::Ligado(){
  return ligado_;
 }
 void ArCondicionado::SetTemperatura(int temp){
  if(temp > 16 || temp < 32){
  temperatura_ = temp;
  }
  else{
  cout << "Temperatura inválida. Por favor, insira um dos valores válidos";
  }
 }
 int ArCondicionado::Temperatura(){
  return temperatura_;
 }
