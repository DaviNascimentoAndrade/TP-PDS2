#include "../include/comodo.h"
#include "../include/lampada.h"
#include "../include/ar_condicionado.h"
#include "../include/tranca.h"
#include "../include/janela.h"
#include "../include/cortina.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

  Comodo::Comodo(){
    lampadas_[0] = Lampada();
    cortinas_[0] = Cortina();
    ares_condicionados_[0] = ArCondicionado();
    trancas_[0] = Tranca();
    janelas_[0] = Janela();
  }
  void Comodo::AdicionarDispositivo(int tipo, string nome){
    switch (tipo)
    {
    case 1:
        lampadas_[nome] = Lampada();
        break;
    case 2:
        cortinas_[nome] = Cortina();
        break;
    case 3:
        ares_condicionados_[nome] = ArCondicionado();
        break;
    case 4:
        trancas_[nome] = Tranca();
        break;  
    case 5:
        janelas_[nome] = Janela();
        break;          
    default:
        break;
    }
  }
  void Comodo::ListarDispositivos(int tipo){
    switch (tipo)
    {
    case 1:
         for(auto it : lampadas_){
            cout<<"Lâmpada: "<<it.first<<endl;
         }
        break;
    case 2:
        for(auto it : cortinas_){
            cout<<"Cortina: "<<it.first<<endl;
         }
        break;
    case 3:
        for(auto it : ares_condicionados_){
             cout<<"Ar condicionado: "<<it.first<<endl;
         }
        break;
    case 4:
        for(auto it : trancas_){
            cout<<"Tranca: "<<it.first<<endl;
         }
        break;  
    case 5:
        for(auto it : janelas_){
           cout<<"Janela: "<<it.first<<endl; 
         }
        break;          
    default:
        break;
    }
  }
  void Comodo::RemoverDispositivo(int tipo, string nome){
    switch (tipo)
    {
    case 1:
         for(auto it : lampadas_){
           if(it.first == nome){
            lampadas_.erase(it.first);
           }
         }
        break;
    case 2:
        for(auto it : cortinas_){
           if(it.first == nome){
            cortinas_.erase(it.first);
           }
         }
        break;
    case 3:
        for(auto it : ares_condicionados_){
             if(it.first == nome){
              ares_condicionados_.erase(it.first);
            }
         }
        break;
    case 4:
        for(auto it : trancas_){
            if(it.first == nome){
              trancas_.erase(it.first);
           }
         }
        break;  
    case 5:
        for(auto it : janelas_){
           if(it.first == nome){
             janelas_.erase(it.first);
           }
         }
        break;          
    default:
        break;
    }
  }
  void Comodo::ConfigurarTodos(int tipo){
    switch (tipo)
    {
    case 1:
         for(auto it : lampadas_){
             int x;
             string y;
            cout<<"Digite a intensidade da Lampada: ";
            cin>>x;
            cout<<"Digite a cor da Lampada: ";
            cin>>y;
            it.second.SetIntensidade(x);
            it.second.SetCor(y);
         }
        break;
    case 2:
        for(auto it : cortinas_){
            int x;
            cout<<"Digite a intensidade da Cortina: ";
            cin>>x;
            it.second.SetIntensidade(x);
         }
        break;
    case 3:
        for(auto it : ares_condicionados_){
              bool l;
              cout<<"Digite true para ligar o ar condicionado ou false para desligar: ";
              cin>>l;
              if(l == true){
                it.second.SetLigar(true);
                string y;
                cout<<"Digite o modo do ar condicionado: ";
                cin>>y;
                int x;
                cout<<"Digite a temperatura do ar condicionado: ";
                cin>>x;
                it.second.SetModo(y);
                it.second.SetTemperatura(x);
              }
             }
        break;
    case 4:
        for(auto it : trancas_){
            cout<<"Digite o modo da tranca : ";
            bool x;
            it.second.SetAtiva(x);
         }
        break;  
    case 5:
        for(auto it : janelas_){
           int x;
           cout<<"Digite a intensidade da Janela: ";
           cin>>x; 
           it.second.SetIntensidade(x);
         }
        break;          
    default:
        break;
    }
  }
  void Comodo::SetNome(string nome){
    nome_ = nome;
  }
  string Comodo::Nome(){
    return nome_;
  }
