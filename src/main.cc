/*
Menu principal:
  Comodos
  Modos
  Desligar

  Comodos:
    Adicionar cômodo()
    Remover cômodo()
    Acessar cômodo
    Voltar

    Comodo específico:
      Ares condiciondados
      Cortinas
      Janelas
      Lâmpadas
      Trancas
      Mudar nome()
      Voltar

      Dispositivo específico:
        configs()
        Adicionar()
        Remover()
        Configurar todos()
        (listar dispositivos)
        Voltar

  Modos:
    Adicionar modo()
    Ativar modo()
    Remover modo()
    Configurar modo
    (ListarModos)
    Voltar

    Config. modo:
      Comodos()

*/


#include "../include/casa.h"
#include <iostream>

using namespace std;

/*
=============================================================================
PROTOTIPES
=============================================================================
*/

// MENU PRINCIPAL
void MenuComodos(Casa &house); // Configura uma casa

// MENU CÔMODOS
void AdicionarComodo(Casa& house, string nome); // Adiciona um cômodo na casa
void RemoverComodo(Casa& house, string nome); // Remove um comodo da casa
void MenuComodo(string comodo); // configura um comodo

// MENU COMODO
void MudarNome(string& atual); // Muda o nome do cômodo informado

// MODOS
void AdicionarModo(Casa& house, string nome); // Adiciona um modo na casa
void RemoverModo(Casa& house, string nome); // Remove um modo da casa

/*
=============================================================================
MAIN
=============================================================================
*/

int main(){



  return 0;
}

/*
=============================================================================
FUNÇÕES
=============================================================================
*/

void Titulo (string titulo) {
    cout<<"==============================================================\n";
    cout<<"\t"<< titulo <<"\n";
    cout<<"==============================================================\n";
    cout<<"\n";
}

void MenuComodos(Casa &house){

  int esc = 0;
  while(esc != 4){

    Titulo("MENU DE COMODOS");
    cout<<"  1 - Acessar comodo\n";
    cout<<"  2 - Adicionar comodo\n";
    cout<<"  3 - Remover comodo\n";
    cout<<"  4 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 4){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      while(esc < 1 || esc > 4){cout<<"Escolha invalida!";}
    }

    // ACESSAR COMODO
    if(esc == 1){

      cout<<"Comodos disponiveis:";
      house.ListarComodos();
      string comodo = "";
      bool ex = 0;
      while(!ex){

        cout<<"Digite o nome do comodo que deseja acessar: ";
        cin>>comodo;
        bool ex = 0;
      
        for(auto it : house.comodos_){
          if(it.first == comodo){
            ex = 1;
          }
          
        }
      }

    }

  }
}