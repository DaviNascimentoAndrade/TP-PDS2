#include "../include/arcondicionado.h"

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
 void ArCondicionado::SetModo(string modo){
  if(modo == "cool" || modo == "heat" || modo == "dry"
  || modo == "fan"){
  modo_ = modo;
  }
  else{
  cout << "Modo inválido. Por favor, insira um dos modos válidos";
  }
 }
 string ArCondicionado::Modo(){
  return modo_;
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
