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
      Acessar dispositivos()
      Mudar nome()
      Voltar

      Dispositivo específico:
        Configurar dispositivo
        Configurar todos
        Adicionar dispositivo
        Remover dispositivo
        Listar dispositivos do comodo
        Voltar

  Modos:
    Adicionar modo() - criar no main (usar funções do map)
    Ativar modo() - tem na casa
    Remover modo() - criar no main (usar funções do map)
    Configurar modo - usar a função MenuComodos
    (ListarModos)
    Voltar

    IMPORTANTE: quanto criar o modo, passa pra ele só o map dos comodos da casa, e não o map de modos

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
void MenuComodo(Casa& house, string comodo); // configura um comodo

// MENU COMODO
void MenuDispositivo(Casa& house, string comodo);

// MODOS
void AdicionarModo(Casa& house, string nome); // Adiciona um modo na casa
void RemoverModo(Casa& house, string nome); // Remove um modo da casa

void Titulo(string titulo);

/*
=============================================================================
MAIN
=============================================================================
*/

int main(){

  Casa casa;

  // MENU PRINCIPAL
  int esc = 0;
  while (esc != 3){

    system("clear");
    Titulo("MENU PRINCIPAL - "+ casa.Nome());
    cout<<"  1 - Menu de comodos\n";
    cout<<"  2 - Menu de modos\n";
    cout<<"  3 - Sair\n";

    esc = 0;
    while(esc < 1 || esc > 3){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 3){cout<<"Escolha invalida!"<<endl;}
    }

    // MENU DE COMODOS
    if(esc == 1){
      MenuComodos(casa);
    }

    // MENU DE MODOS
    else if(esc == 2){

    }
  }
  return 0;
}

/*
=============================================================================
FUNÇÕES
=============================================================================
*/

// TITULO
void Titulo (string titulo) {
    cout<<"==============================================================\n";
    cout<<"\t"<< titulo <<"\n";
    cout<<"==============================================================\n";
    cout<<"\n";
}

// MENU COMODOS
void MenuComodos(Casa &house){

  int esc = 0;
  while(esc != 4){

    system("clear");
    Titulo("MENU DE COMODOS - "+ house.Nome());
    cout<<"  1 - Acessar comodo\n";
    cout<<"  2 - Adicionar comodo\n";
    cout<<"  3 - Remover comodo\n";
    cout<<"  4 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 4){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 4){cout<<"Escolha invalida!"<<endl;}
    }

    // ACESSAR COMODO
    if(esc == 1){

      if(house.comodos_.size() < 1){
        cout<<"Nao existem comodos, adicione um comodo para usar essta opcao!"<<endl;
        system("pause");
      }else{
        // LISTAR COMODOS DISPONÍVEIS
        cout<<"Comodos disponiveis:";
        house.ListarComodos();
        string comodo = "";

        // USUÁRIO ESCOLHE O CÔMODO QUE QUER CONFIGURAR
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
          if(!ex){cout<<"Escolha invalida!";}
        }
      
        MenuComodo(house, comodo);
      }
    }

    // ADICIONAR COMODO
    else if(esc == 2){

    }

    // REMOVER COMODO
    else if(esc == 3){

    }
  }
}

// MENU COMODO
void MenuComodo(Casa& house, string comodo){

  int esc = 0;
  while(esc != 3){

    system("clear");
    Titulo("COMODO "+ comodo +" - "+ house.Nome());
    cout<<"  1 - Acessar Dispositivos\n";
    cout<<"  2 - Mudar nome\n";
    cout<<"  3 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 3){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 3){cout<<"Escolha invalida!"<<endl;}
    }
  

    // Acessar dispositivos
    if(esc == 1){
      MenuDispositivo(house, comodo);
    }

    // Mudar nome
    else if(esc == 2){

    }
  }
}

// Menu dispositivos
void MenuDispositivo(Casa& house, string comodo){

  int esc = 0;
  while(esc != 3){

    system("clear");
    Titulo("DISPOSITIVOS DE "+ comodo +" - "+ house.Nome());
    cout<<"  1 - Configurar dispositivo\n";
    cout<<"  2 - Adicionar dispositivo\n";
    cout<<"  3 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 3){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 3){cout<<"Escolha invalida!"<<endl;}
    }

    // Acessar dispositivos
    if(esc == 1){
      
    }

    // Mudar nome
    else if(esc == 2){

    }
  }
}
