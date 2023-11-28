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
  // Declaração do Construtor 
  Comodo::Comodo(){

  }
  //Adiciona um novo dispositivo de algum tipo
  void Comodo::AdicionarDispositivo(int tipo, string nome){
    // 
    switch (tipo)
    {
    // Case = 1, adiciona Lampada  
    case 1:
        lampadas_[nome] = Lampada();
        break;
    // Case = 2, adiciona Cortina    
    case 2:
        cortinas_[nome] = Cortina();
        break;
    case 3:
    // Case = 3, adiciona Ar condicionado
        ares_condicionados_[nome] = ArCondicionado();
        break;
    case 4:
    // Case = 4, adiciona Tranca
        trancas_[nome] = Tranca();
        break;  
    case 5:
    // Case = 5, adiciona Janela
        janelas_[nome] = Janela();
        break;          
    default:
        // Tratamento de exceção do tipo 
        cout<<"Tipo invalido"<<endl;
        break;
    }
  }
  //Lista todos os dispositivos de um tipo, sendo Lampada,Cortina,Arcondicionado,Tranca e Janela, 1,2,3,4 e 5 respectivamente
  void Comodo::ListarDispositivos(int tipo){
    switch (tipo)
    {
    // Case = 1, imprime todas as Lampadas  
    case 1:
        cout<<"Lâmpada:"<<endl;
         for(auto it : lampadas_){
            cout <<it.first;
            cout <<"[intensidade: "<<lampadas_[it.first].Intensidade();
            cout <<", cor: "<<lampadas_[it.first].Cor()<<"]"<<endl;       
         }
        break;
     // Case = 2, imprime todas as Cortinas     
    case 2:
        cout<<"Cortina:"<<endl;   
        for(auto it : cortinas_){
            cout <<it.first;
            cout <<"[intensidade: "<<cortinas_[it.first].Intensidade();
            cout <<"]"<<endl;
         }
        break;
    case 3:
     // Case = 3, imprime todos os Ar condicionados
        cout<<"Ar condicionado:"<<endl;
        for(auto it : ares_condicionados_){
            cout <<it.first;
            cout <<"[intensidade: "<<ares_condicionados_[it.first].Intensidade();
            cout <<", temperatura: "<<ares_condicionados_[it.first].Temperatura();
            cout <<", status: "<<ares_condicionados_[it.first].Ligado()<<"]"<<endl;
         }
        break;
    case 4:
    // Case = 4, imprime todas as Trancas 
        cout<<"Tranca:"<<endl; 
        for(auto it : trancas_){
            cout <<it.first;
            cout <<"[status: "<<trancas_[it.first].Ativa();
            cout <<"]"<<endl;
         }
        break;  
    case 5:
    // Case = 5, imprime todas as janelas
        cout<<"Janela:"<<endl;
        for(auto it : janelas_){
            cout <<it.first;
            cout <<"[intensidade: "<<janelas_[it.first].Intensidade();
            cout <<", status da tranca: "<<janelas_[it.first].Tranca()<<"]"<<endl;
         }
        break;          
    default:
    // Tratamento de exceção do tipo 
        cout<<"Tipo invalido"<<endl;
        break;
    }
  }
  //Remove um dispositivo, de um tipo, do comodo, sendo Lampada,Cortina,Arcondicionado,Tranca e Janela, 1,2,3,4 e 5 respectivamente
  void Comodo::RemoverDispositivo(int tipo, string nome){
    switch (tipo)
    {
    case 1:
    //Remove um dispositivo, do tipo Lampada, caso haja o mesmo nome
         for(auto it : lampadas_){
           if(it.first == nome){
            lampadas_.erase(nome);
            break;
           }
         }
        
    //Remove um dispositivo, do tipo Cortina, caso haja o mesmo nome    
    case 2:
        for(auto it : cortinas_){
           if(it.first == nome){
            cortinas_.erase(nome);
            break;
           }
         }
    //Remove um dispositivo, do tipo Ar condicionado, caso haja o mesmo nome    
    case 3:
        for(auto it : ares_condicionados_){
             if(it.first == nome){
              ares_condicionados_.erase(nome);
              break;
            }
         }
    //Remove um dispositivo, do tipo Tranca, caso haja o mesmo nome    
    case 4:
        for(auto it : trancas_){
            if(it.first == nome){
              trancas_.erase(nome);
              break;
           }
         }
    //Remove um dispositivo, do tipo Janela, caso haja o mesmo nome    
    case 5:
        for(auto it : janelas_){
           if(it.first == nome){
             janelas_.erase(nome);
             break;
           }
         }      
    default:
    // Tratamento de exceção do tipo 
        cout<<"Tipo invalido"<<endl;
        break;
    }
  }
  //Configura todos os dispositivos de um mesmo tipo no comodo, sendo Lampada,Cortina,Arcondicionado,Tranca e Janela, 1,2,3,4 e 5 respectivamente
  void Comodo::ConfigurarTodos(int tipo){
    switch (tipo)
    {
    //Configura todos os dispositivos do tipo Lampada  
    case 1:{
         int x;
         string y;
         cout<<"Digite a intensidade da Lampada de 0 a 100: ";
         cin>>x;
         cout<<"Digite a cor da Lampada (Amarelo, Vermelho, Azul, Branco, Laranja, Verde ou Roxo): ";
         cin>>y;
        
        for(auto it : lampadas_){
        lampadas_[it.first].SetIntensidade(x);
        lampadas_[it.first].SetCor(y);
          
        } 
        break;
      }
    //Configura todos os dispositivos do tipo Cortina    
    case 2:{
         int x;
         cout<<"Digite a intensidade da Cortina: ";
         cin>>x;     
        for(auto it : cortinas_){
            cortinas_[it.first].SetIntensidade(x);
         }
        break;
      }
    //Configura todos os dispositivos do tipo Ar condicionado    
    case 3:{
         bool l;
         cout<<"Digite true para ligar o ar condicionado ou false para desligar: ";
         cin>>l;
         int i;
         cout<<"Digite a intensidade do ar condicionado: ";
         cin>>i;
         int x;
         cout<<"Digite a temperatura do ar condicionado: ";
         cin>>x;      
        for(auto it : ares_condicionados_){
              if(it.second.Ligado() == true){
                ares_condicionados_[it.first].SetLigar(true);
                ares_condicionados_[it.first].SetIntensidade(i);
                ares_condicionados_[it.first].SetTemperatura(x);
              }
          }
        break;
    }
    //Configura todos os dispositivos do tipo Ar condicionado  
    case 4:{
         cout<<"Digite o modo da tranca : ";
         bool x;
        for(auto it : trancas_){
            trancas_[it.first].SetAtiva(x);
         }
        break;  
      } 
     //Configura todos os dispositivos do tipo janela   
    case 5:{
        int x;
        bool y;
        cout<<"Digite a config. da tranca (1 fechado, 0 aberto): ";
        cin>>y; 
        cout<<"Digite a intensidade da Janela: ";
        cin>>x; 
        for(auto it : janelas_){
           janelas_[it.first].SetIntensidade(x);
           janelas_[it.first].SetTranca(y);
         }
        break;          
    }  
    // Tratamento de exceção do tipo 
    default:
        cout<<"Tipo invalido"<<endl;
        break;
    }
  }
  //Configura o nome do comodo;
  void Comodo::SetNome(string nome){
    nome_ = nome;
  }
  //Retorna o nome do Comodo
  string Comodo::Nome(){
    return nome_;
  }