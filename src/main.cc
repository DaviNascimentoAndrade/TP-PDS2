/*
Menu principal: (feito)
  Comodos
  Modos
  mudar nome
  Desligar

  Comodos: (feito)
    Acessar cômodo
    Adicionar cômodo()
    Remover cômodo()
    Status
    Voltar

    Comodo específico:
      Acessar dispositivos()
      Mudar nome()
      Voltar

      Dispositivos:
        Lampadas
        cortinas
        ares_condionados
        trancas
        janelas
        voltar

        Dispositivo específico:
          Listar
          Configurar dispositivo
          Adicionar dispositivo
          Remover
          Configurar todas
          Voltar

  Modos:
    Adicionar modo() - criar no main (usar funções do map)
    Ativar modo() - tem na casa
    Remover modo() - criar no main (usar funções do map)
    Configurar modo - usar a função MenuComodos
    Mudar nome
    Voltar

    IMPORTANTE: quanto criar o modo, passa pra ele só o map dos comodos da casa, e não o map de modos

    Config. modo:
      Comodos()

*/


#include "../include/casa.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
=============================================================================
PROTOTIPES
=============================================================================
*/

// MENU PRINCIPAL
void MenuComodos(Casa &house); // Configura uma casa
void MenuModos(Casa& house); // menu de modos

// MENU CÔMODOS
void AdicionarComodo(Casa& house, string nome); // Adiciona um cômodo na casa
void RemoverComodo(Casa& house, string nome); // Remove um comodo da casa
void MenuComodo(Casa& house, string comodo); // configura um comodo

// MENU COMODO
void MenuDispositivo(Casa& house, string comodo);

//MENU DISPOSITIVO
void MenuLampada(Comodo& comodo);
void MenuCortina(Comodo& comodo);
void MenuArCondicionado(Comodo& comodo);
void MenuTrancas(Comodo& comodo);
void MenuJanelas(Comodo& comodo);

// MODOS
void AdicionarModo(Casa& house, string nome); // Adiciona um modo na casa
void RemoverModo(Casa& house, string nome); // Remove um modo da casa

void Titulo(string titulo);
void Wait1();

/*
=============================================================================
MAIN
=============================================================================
*/

int main(){

  Casa casa;

  // MENU PRINCIPAL
  int esc = 0;
  while (esc != 4){

    esc = 0;
    system("clear");
    Titulo("MENU PRINCIPAL - "+ casa.Nome());
    cout<<"  1 - Menu de comodos\n";
    cout<<"  2 - Menu de modos\n";
    cout<<"  3 - Mudar nome da casa\n";
    cout<<"  4 - Sair\n";

    if(casa.Nome().size() == 0){
      cout<<"(Dica: dê um nome para sua casa com a opção n° 3)"<<endl;
    }

    esc = 0;
    while(esc < 1 || esc > 4){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 4){
        cout<<"Escolha invalida!"<<endl;
        Wait1();
      }
    }

    // MENU DE COMODOS
    if(esc == 1){
      MenuComodos(casa);
    }

    // MENU DE MODOS
    else if(esc == 2){
      MenuModos(casa);
    }

    // MUDAR NOME
    else if(esc == 3){
      string nm = "";
      cout<<"Digite o novo nome: ";
      cin.ignore();
      getline(cin, nm);
      casa.SetNome(nm);
    }
  }
  return 0;
}
/*
=============================================================================
FUNÇÕES
=============================================================================
*/

// COMODIDADES
void Titulo (string titulo) {
    cout<<"==============================================================\n";
    cout<<"\t"<< titulo <<"\n";
    cout<<"==============================================================\n";
    cout<<"\n";
}
void Wait1(){

  int ex = 0;
  while(ex != 1){
    cout<< " Digite 1 para voltar: ";
    cin>> ex;
  }
}

// MENU COMODOS
void MenuComodos(Casa &house){

  int esc = 0;
  while(esc != 5){

    esc = 0;
    system("clear");
    Titulo("MENU DE COMODOS - "+ house.Nome());
    cout<<"  1 - Acessar comodo\n";
    cout<<"  2 - Adicionar comodo\n";
    cout<<"  3 - Remover comodo\n";
    cout<<"  4 - Status geral\n";
    cout<<"  5 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 5){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 5){
        cout<<"Escolha invalida!"<<endl;
        Wait1();
      }
    }

    // ACESSAR COMODO
    if(esc == 1){

      if(house.comodos_.size() < 1){

        cout<<"Nao existem comodos, adicione um comodo para usar essta opcao!"<<endl;
        Wait1();
      }else{

        // LISTAR COMODOS DISPONÍVEIS
        house.ListarComodos();
        string comodo = "";

        // USUÁRIO ESCOLHE O CÔMODO QUE QUER CONFIGURAR
        bool ex = 0;
        while(!ex){

          cout<<"Digite o nome do comodo que deseja acessar: ";
          cin.ignore();
          getline(cin, comodo);
      
          for(auto it : house.comodos_){

            if(it.first == comodo){
             ex = 1;
            }
          }

          if(!ex){
            cout<<"Escolha invalida!\n";
          }
        }

        MenuComodo(house, comodo);
      }
    }

    // ADICIONAR COMODO
    else if(esc == 2){

      string comodo = "";
      cout <<"Digite o nome do cômodo que deseja adicionar: ";
      cin.ignore();
      getline(cin, comodo);
      house.AdicionarComodo(comodo);
      house.comodos_[comodo].SetNome(comodo);
      cout << "Comôdo " << comodo << " salvo!";
      Wait1();
    }

    // REMOVER COMODO
    else if(esc == 3){
      if(house.comodos_.size() < 1){
        cout<<"Nao existem comodos para serem removidos!"<<endl;
        Wait1();
      }
      else{
        // LISTAR COMODOS DISPONÍVEIS PARA REMOVER
        house.ListarComodos();
        string comodo = "";

        // USUÁRIO ESCOLHE O CÔMODO QUE QUER REMOVER
        bool ex = 0;
        while(!ex){

          cout<<"Digite o nome do comodo que deseja remover: ";
          cin.ignore();
          getline(cin, comodo);
      
          for(auto it : house.comodos_){
            if(it.first == comodo){
             ex = 1;
            }
          }
          if(!ex){
            cout<<"Esse cômodo não existe!\n";
          }
        }
      
        house.RemoverComodo(comodo);
        cout << "Cômodo " << comodo << " removido!";
        Wait1();
      }
    }

    // STATUS GERAL
    else if(esc == 4){

      if(house.comodos_.size() < 1){
        cout << "Não há nenhum comodo!\n";
        cout << "Para verificar os status, adicione um comodo com a opção 2!"<< endl;
        Wait1();
      }
      else{
        
        cout << "Status geral (Todos os dispositivos em cada comodo):" << endl;
        for(auto it : house.comodos_){
          
          cout<<endl;
          cout << it.first << ":" << endl;
          cout << "Lâmpadas:" << endl;
          it.second.ListarDispositivos(1);
          cout << "Cortinas:" << endl;
          it.second.ListarDispositivos(2);
          cout << "Ares:" << endl;
          it.second.ListarDispositivos(3);
          cout << "Trancas:" << endl;
          it.second.ListarDispositivos(4);
          cout << "Janelas:" << endl;
          it.second.ListarDispositivos(5);
        }
        Wait1();
      }
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
      string novo_nome = "";
      cout<<"Digite o novo nome do comodo: ";
      cin.ignore();
      getline(cin, novo_nome);
      //basicamente cria um novo valor para o map, substitui oq tinha no antigo
      //para o novo e apaga o velho
      house.comodos_[comodo].SetNome(novo_nome);
      house.comodos_[novo_nome] = move(house.comodos_[comodo]);
      house.comodos_.erase(comodo);
      comodo = novo_nome;

      cout << "Cômodo " << comodo << " renomeado!";
      Wait1();
    }  
  }
}

// Menu dispositivos
void MenuDispositivo(Casa& house, string comodo){

  int esc = 0;
  while(esc != 6){

    system("clear");
    Titulo("DISPOSITIVOS DE "+ comodo +" - "+ house.Nome());
    cout<<"  1 - Lampadas\n";
    cout<<"  2 - Cortinas\n";
    cout<<"  3 - Ares condicionados\n";
    cout<<"  4 - Trancas\n";
    cout<<"  5 - Janelas\n";
    cout<<"  6 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 6){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 6){cout<<"Escolha invalida!"<<endl;}
    }

    // Acessar a lampada
    if(esc == 1){
      MenuLampada(house.comodos_[comodo]);
    }

    // Acessar o Cortina
    else if(esc == 2){
     MenuCortina(house.comodos_[comodo]);
    }

    //Acessar as Ar condicionado
    else if(esc == 3){
     MenuArCondicionado(house.comodos_[comodo]);
    }

    //Acessar as tranca
    else if(esc == 4){
     MenuTrancas(house.comodos_[comodo]);
    }

    //Acessar as janela
    else if(esc == 5){
     MenuJanelas(house.comodos_[comodo]);
    }
  }
}

void MenuLampada(Comodo& comodo){

  int esc = 0;
  while(esc != 6){

    system("clear");
    Titulo("LÂMPADAS DE " + comodo.Nome());
    cout<<"  1 - Listar Lâmpadas\n";
    cout<<"  2 - Configurar Lâmpadas\n";
    cout<<"  3 - Adicionar Lâmpadas\n";
    cout<<"  4 - Remover Lâmpadas\n";
    cout<<"  5 - Configurar todas as Lâmpadas\n";
    cout<<"  6 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 6){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 6){
        cout<<"Escolha invalida!"<<endl;
      }
    }

    if((esc == 2 || esc == 4 || esc == 5) && comodo.lampadas_.size() == 0){
      cout<<"Não há lâmpadas! Escolha inválida!"<<endl;
      esc = 0;
      Wait1();
    }

    // listar as lampadas
    if(esc == 1){
      cout << "Lâmpadas:" << endl;
      comodo.ListarDispositivos(1); 
      Wait1();
    }
    
    //Configurar uma lâmpada
    if(esc == 2){

      cout<<"Lâmpadas para configurar: \n";
      comodo.ListarDispositivos(1);
      string lampada = "";

      // USUÁRIO ESCOLHE A LAMAPADA QUE QUER ALTERAR
      bool ex = 0;
      while(!ex){

        cout<<"Digite o nome da lâmpada que deseja configurar: ";
        cin.ignore();
        getline(cin, lampada);
      
        for(auto it : comodo.lampadas_){
          if(it.first == lampada){
            ex = 1;
          }
        }
        if(!ex){cout<<"Essa lâmpada não existe!\n";}
      }

      int intensidade = 0;
      string cor = "";
      //setando a intensidade
      cout<< "Digite a intensidade da lâmpada de 0 a 100: ";
      cin>>intensidade; //lampada.cc já trata essa excessão
      comodo.lampadas_[lampada].SetIntensidade(intensidade);

      //setando a cor
      cout<< "Digite a cor da lâmpada (Amarelo, Vermelho Azul, Branco, Laranja, Verde ou Roxo): ";
      cin>>cor;
      comodo.lampadas_[lampada].SetCor(cor);

      cout << "Lâmpada " << lampada << " configurada!";
      Wait1();
    }

    //ADICIONAR LAMPADA
    if(esc == 3){

      string nome = "";
      cout<< "Digite o nome da nova lâmpada: ";
      cin.ignore();
      getline(cin, nome);
      comodo.AdicionarDispositivo(1, nome);

      cout << "Lâmpada " << nome << " salva!";
      Wait1();
    }

    //REMOVER LAMPADA
    if(esc == 4){
      
      cout<< "Lâmpadas disponíveis:"<<endl;
      comodo.ListarDispositivos(1);

      // USUÁRIO ESCOLHE A LAMPADA QUE QUER REMOVER
      bool ex = 0;
      string lampada = "";
      while(!ex){

        cout<<"Digite o nome da lâmpada que deseja remover: ";
        cin.ignore();
        getline(cin, lampada);
      
        for(auto it : comodo.lampadas_){
          if(it.first == lampada){
            ex = 1;
          }
        }
        if(!ex){cout<<"Essa lâmpada não existe!\n";}
      }
      
      comodo.RemoverDispositivo(1,lampada);
      cout << "Lâmpada " << lampada << " removida!";
      Wait1();
    }


    //CONFIGURAR TODAS AS LAMPADAS
    if(esc == 5){
      comodo.ConfigurarTodos(1);
      cout << "Lampadas configuradas!";
      Wait1();
    }
  }
}

void MenuCortina(Comodo& comodo){

  int esc = 0;
  while(esc != 6){

    system("clear");
    Titulo("CORTINAS DE " + comodo.Nome());
    cout<<"  1 - Listar Cortinas\n";
    cout<<"  2 - Configurar Cortina\n";
    cout<<"  3 - Adicionar Cortinas\n";
    cout<<"  4 - Remover Cortinas\n";
    cout<<"  5 - Configurar todas as Cortinas\n";
    cout<<"  6 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 6){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 6){cout<<"Escolha invalida!"<<endl;}
    }

    if((esc == 2 || esc == 4 || esc == 5) && comodo.cortinas_.size() == 0){
      cout<<"Não há cortinas! Escolha inválida!"<<endl;
      esc = 0;
      Wait1();
    }

    // listar as cortinas
    if(esc == 1){

      cout <<"Cortinas:"<< endl;
      comodo.ListarDispositivos(2); 
      Wait1();
    }
    
    //Configurar uma cortina
    if(esc == 2){

      cout<<"Cortinas para configurar: \n";
      comodo.ListarDispositivos(2);
      string cortina = "";

      // USUÁRIO ESCOLHE A CORTINA QUE QUER ALTERAR
      bool ex = 0;
      while(!ex){

        cout<<"Digite o nome da cortina que deseja configurar: ";
        cin.ignore();
        getline(cin, cortina);
      
          for(auto it :comodo.cortinas_){
            if(it.first == cortina){
             ex = 1;
            }
          }
          if(!ex){cout<<"Essa cortina não existe!\n";}
      }

      int intensidade = 0;
      //setando a intensidade
      cout<< "Digite a intensidade da cortina de 0 a 100: ";
      cin>>intensidade;
      comodo.cortinas_[cortina].SetIntensidade(intensidade);
      cout << "Cortina " << cortina << " configurada!";
      Wait1();
    }

    //ADICIONAR CORTINA
    if(esc == 3){

      string nome = "";
      cout<< "Digite o nome da nova cortina: ";
      cin.ignore();
      getline(cin, nome);
      comodo.AdicionarDispositivo(2, nome);
      cout << "Cortina " << nome << " salva!";
      Wait1();
    }

    //REMOVER CORTINA
    if(esc == 4){

      cout <<"Cortinas:"<< endl;
      comodo.ListarDispositivos(2);
      // USUÁRIO ESCOLHE A CORTINA QUE QUER REMOVER
      bool ex = 0;
      string cortina = "";
      while(!ex){

        cout<<"Digite o nome da cortina que deseja remover: ";
        cin.ignore();
        getline(cin, cortina);
      
        for(auto it : comodo.cortinas_){
          if(it.first == cortina){
            ex = 1;
          }
        }
        if(!ex){cout<<"Essa cortina não existe!\n";}
      }
      
      comodo.RemoverDispositivo(2, cortina);
      cout << "Cortina " << cortina << " removida!";
      Wait1();
    }


    //CONFIGURAR TODAS AS CORTINAS
    if(esc == 5){

      comodo.ConfigurarTodos(2);
      cout << "Cortinas configuradas!";
      Wait1();
    }
  }
}

void MenuArCondicionado(Comodo& comodo){

  int esc = 0;
  while(esc != 6){

    system("clear");
    Titulo("ARES CONDICIONADOS DE " + comodo.Nome());
    cout<<"  1 - Listar Ares Condicionados\n";
    cout<<"  2 - Configurar Ar Condicionado\n";
    cout<<"  3 - Adicionar Ar Condicionado\n";
    cout<<"  4 - Remover Ares Condicionados\n";
    cout<<"  5 - Configurar todas os Ares Condicionados\n";
    cout<<"  6 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 6){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 6){cout<<"Escolha invalida!"<<endl;}
    }

    if((esc == 2 || esc == 4 || esc == 5) && comodo.ares_condicionados_.size() == 0){
      cout<<"Não há ares! Escolha inválida!"<<endl;
      esc = 0;
      Wait1();
    }

    // listar a ar condicionado
    if(esc == 1){

      cout << "Ares: " << endl;
      comodo.ListarDispositivos(3); 
      Wait1();
    }
    
    //Configurar um ar condicionado
    if(esc == 2){

      cout<<"Ares para configurar: \n";
      comodo.ListarDispositivos(3);
      string ArCondicionado = "";

      // USUÁRIO ESCOLHE A LAMAPADA QUE QUER ALTERAR
      bool ex = 0;
      while(!ex){

        cout<<"Digite o nome do ar condicionado que deseja configurar: ";
        cin.ignore();
        getline(cin, ArCondicionado);
      
        for(auto it :comodo.ares_condicionados_){
          if(it.first == ArCondicionado){
            ex = 1;
          }
        }
        if(!ex){cout<<"Esse ar condicionado não existe!\n";}
      }

      int intensidade = 0;
      bool ligado = false;
      string resposta = "";
      int temperatura = 0;
      //setando a intensidade
      cout<< "Digite a intensidade da cortina de 0 a 100: ";
      cin>>intensidade;
      comodo.ares_condicionados_[ArCondicionado].SetIntensidade(intensidade);
        
      cout<< "Digite se o ar esta ligado ou não (sim ou não) ";
      cin>>resposta;
      if(resposta == "SIM" || resposta == "Sim" || resposta == "sim"){
        ligado = true;
      }
      else{ ligado = false; }
      comodo.ares_condicionados_[ArCondicionado].SetLigar(ligado);
      cout<< "Digite a temperatura do Ar Condicionado(de 16 a 32 graus): ";
      cin>>temperatura;
      comodo.ares_condicionados_[ArCondicionado].SetTemperatura(temperatura);
      cout << "ArCondicionado " << ArCondicionado << " configurado!";
      Wait1();
    }

    //ADICIONAR AR CONDIONADO
    if(esc == 3){
      string nome = "";
      cout<< "Digite o nome do novo ar condicionado: ";
      cin.ignore();
      getline(cin, nome);
      comodo.AdicionarDispositivo(3, nome);
      cout << "ArCondicionado " << nome << " salvo!";
      Wait1();
    }

    //REMOVER AR CONDICIONADO
    if(esc == 4){

      cout << "Ares:" << endl;
      comodo.ListarDispositivos(3);

      // USUÁRIO ESCOLHE O AR CONDICIONADO QUE QUER REMOVER
      bool ex = 0;
      string ArCondicionado = "";
      while(!ex){

        cout<<"Digite o nome do ar condicionado que deseja remover: ";
        cin.ignore();
        getline(cin, ArCondicionado);
      
          for(auto it : comodo.ares_condicionados_){
            if(it.first == ArCondicionado){
             ex = 1;
            }
          }
          if(!ex){cout<<"Esse ar condicionado não existe!\n";}
      }
      
      comodo.RemoverDispositivo(2,ArCondicionado);
      cout << "ArCondicionado " << ArCondicionado << " removido!";
      Wait1();
    }


    //CONFIGURAR TODAS OS ARES CONDICIONADOS
    if(esc == 5){
      comodo.ConfigurarTodos(3);
      cout << "Ares Condicionados configurados!";
      Wait1();
    }
  }
}

void MenuTrancas(Comodo& comodo){

  int esc = 0;
  while(esc != 6){

    system("clear");
    Titulo("TRANCAS DE " + comodo.Nome());
    cout<<"  1 - Listar Trancas\n";
    cout<<"  2 - Configurar Trancas\n";
    cout<<"  3 - Adicionar Trancas\n";
    cout<<"  4 - Remover Trancas\n";
    cout<<"  5 - Configurar todas as Trancas\n";
    cout<<"  6 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 6){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 6){cout<<"Escolha invalida!"<<endl;}
    }

    if((esc == 2 || esc == 4 || esc == 5) && comodo.trancas_.size() == 0){
      cout<<"Não há trancas! Escolha inválida!"<<endl;
      esc = 0;
      Wait1();
    }

    // listar as trancas
    if(esc == 1){
      
      cout << "Trancas:" << endl;
      comodo.ListarDispositivos(4); 
      Wait1();
    }
    
    //Configurar uma tranca
    if(esc == 2){

      cout<<"Trancas para configurar: \n";
      comodo.ListarDispositivos(4);
       string tranca = "";

      // USUÁRIO ESCOLHE A TRANCA QUE QUER ALTERAR
      bool ex = 0;
      while(!ex){

        cout<<"Digite o nome da tranca que deseja configurar: ";
        cin.ignore();
        getline(cin, tranca);
      
        for(auto it :comodo.trancas_){
          if(it.first == tranca){
            ex = 1;
          }
        }
        if(!ex){cout<<"Essa tranca não existe!\n";}
      }

      bool trancada = false;
      string resposta ="";
      //abrindo ou fechando
      cout<< "Digite se quer abrir ou fechar a tranca: ";
      cin>>resposta;
      if(resposta =="FECHAR" || resposta == "Fechar" || resposta == "fechar" ){
        trancada = true;
      }
      else { trancada = false; }
      comodo.trancas_[tranca].SetAtiva(trancada);
      cout << "Tranca " << tranca << " configurada!";
      Wait1();
    }

    //ADICIONAR TRANCA
    if(esc == 3){

      string nome = "";
      cout<< "Digite o nome da nova tranca: ";
      cin.ignore();
      getline(cin, nome);
      comodo.AdicionarDispositivo(4, nome);
      cout << "Tranca " << nome << " salva!";
      Wait1();
    }

    //REMOVER TRANCA
    if(esc == 4){

      cout << "Trancas:" << endl;
      comodo.ListarDispositivos(4);
      // USUÁRIO ESCOLHE A TRANCA QUE QUER REMOVER
      bool ex = 0;
      string tranca = "";
      while(!ex){

        cout<<"Digite o nome da tranca que deseja remover: ";
        cin.ignore();
        getline(cin, tranca);
      
        for(auto it : comodo.trancas_){
          if(it.first == tranca){
            ex = 1;
          }
        }
        if(!ex){cout<<"Essa tranca não existe!\n";}
      }

      comodo.RemoverDispositivo(4, tranca);
      cout << "Tranca " << tranca << " removida!";
      Wait1();
    }


    //CONFIGURAR TODAS AS TRANCAS
    if(esc == 5){

      comodo.ConfigurarTodos(4);
      cout << "Trancas configuradas!";
      Wait1();
    }
  }
}

void MenuJanelas(Comodo& comodo){

  int esc = 0;
  while(esc != 6){

    system("clear");
    Titulo("JANELAS DE " + comodo.Nome());
    cout<<"  1 - Listar Janelas\n";
    cout<<"  2 - Configurar Janelas\n";
    cout<<"  3 - Adicionar Janelas\n";
    cout<<"  4 - Remover Janelas\n";
    cout<<"  5 - Configurar todas as Janelas\n";
    cout<<"  6 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 6){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 6){
        cout<<"Escolha invalida!"<<endl;
        Wait1();
      }
    }

    if((esc == 2 || esc == 4 || esc == 5) && comodo.janelas_.size() == 0){
      cout<<"Não há janelas! Escolha inválida!"<<endl;
      esc = 0;
      Wait1();
    }

    // listar as janelas
    if(esc == 1){

      cout << "Janelas:" << endl;
      comodo.ListarDispositivos(5); 
      Wait1();
    }
    
    //Configurar uma janela
    if(esc == 2){

      cout<<"Janelas para configurar: \n";
      comodo.ListarDispositivos(5);
      string janela= "";

      // USUÁRIO ESCOLHE A JANELA QUE QUER ALTERAR
      bool ex = 0;
      while(!ex){

        cout<<"Digite o nome da janela que deseja configurar: ";
        cin.ignore();
        getline(cin, janela);
      
        for(auto it :comodo.janelas_){
          if(it.first == janela){
            ex = 1;
          }
        }
        if(!ex){
          cout<<"Essa janela não existe!\n";
        }
      }

      int intensidade = 0;
      bool trancada = false;
      string resposta ="";

      //abrindo ou fechando
      cout<< "Digite se quer abrir ou fechar a janela: ";
      cin>>resposta;

      if(resposta =="FECHAR" || resposta == "Fechar" || resposta == "fechar" ){
        trancada = true;
      }
      else { trancada = false; }

      comodo.janelas_[janela].SetTranca(trancada);

      cout<< "Digite a intensidade da janela: ";
      cin>>intensidade;
      comodo.janelas_[janela].SetIntensidade(intensidade);
      cout << "Janela " << janela << " configurada!";
      Wait1();
    }

    //ADICIONAR JANELA
    if(esc == 3){

      string nome = "";
      cout<< "Digite o nome da nova janela: ";
      cin.ignore();
      getline(cin, nome);
      comodo.AdicionarDispositivo(5, nome);
      cout << "Janela " << nome << " salva!";
      Wait1();
    }

    //REMOVER JANELA
    if(esc == 4){

      cout << "Janelas:" << endl;
      comodo.ListarDispositivos(5);
      // USUÁRIO ESCOLHE A JANELA QUE QUER REMOVER
      bool ex = 0;
      string janela = "";
      while(!ex){

      cout<<"Digite o nome da janela que deseja remover: ";
      cin.ignore();
        getline(cin, janela);
      
        for(auto it : comodo.janelas_){
          if(it.first == janela){
            ex = 1;
          }
        }
        if(!ex){cout<<"Essa janela não existe!\n";}
      }
      
      comodo.RemoverDispositivo(5, janela);
      cout << "Janela " << janela << " removida!";
      Wait1();
    }


    //CONFIGURAR TODAS AS JANELAS
    if(esc == 5){
      comodo.ConfigurarTodos(5);
      cout << "Janelas configuradas!";
      Wait1();
    }
  }
}

//Menu Modos
void MenuModos(Casa &house){ //tem que criar esse map de modos ainda
  int esc = 0;
  while(esc != 6){

    system("clear");
    Titulo("MENU DE MODOS - "+ house.Nome());
    cout<<"  1 - Adicionar modo\n";
    cout<<"  2 - Ativar modo\n";
    cout<<"  3 - Remover modo\n";
    cout<<"  4 - Configurar modo\n";
    cout<<"  5 - Mudar nome de um modo\n";
    cout<<"  6 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 6){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 6){cout<<"Escolha invalida!"<<endl;}
    }

    if((esc == 2 || esc == 4) && house.modos_.size() == 0){
      cout<<"Não há modos! Escolha inválida!"<<endl;
      esc = 0;
      Wait1();
    }

    // Adicionar o modo 
    if(esc == 1){

      Casa modo;
      string nome;
      modo.comodos_ = house.comodos_;

      cout << "Digite o nome do modo que deseja criar: ";
      cin.ignore();
      getline(cin, nome);
      modo.SetNome(nome);
      house.modos_[nome] = modo;

      cout << "Modo " << nome << " salvo!";
      Wait1();
    }

    // Ativar o modo
    else if(esc == 2){

      string nome_modo;
      cout << "Modos disponíveis:" << endl;
      house.ListarModos();
      cout << "Digite o nome do modo que deseja ativar: ";
      cin.ignore();
      getline(cin, nome_modo);
      house.AtivarModo(nome_modo);
      Wait1();
    }

    // Remover o modo
    else if(esc == 3){

      string nome_modo;
      cout << "Modos disponíveis:" << endl;
      house.ListarModos();

      cout << "Digite o nome do modo que deseja remover: ";
      cin.ignore();
      getline(cin, nome_modo);

      bool existe = false;
      for(auto it : house.modos_){
        if(it.first == nome_modo){
          existe = 1;
        }
      }
      if(existe){
        house.modos_.erase(nome_modo);
        cout << "Modo " << nome_modo << " removido!";
        Wait1();
      }
      else{
        cout << "Este modo não existe!" << endl;
        Wait1();
      }
    }
    
    //Configura o modo
    else if(esc == 4){

      cout << "Modos disponíveis:" << endl;
      house.ListarModos();

      string nome_modo;
      cout << "Digite o nome do modo que deseja configurar: ";
      cin.ignore();
      getline(cin, nome_modo);

      bool existe = false;
      for(auto it : house.modos_){
        if(it.first == nome_modo){
          existe = 1;
        }
      }
      if(existe){
        MenuComodos(house.modos_[nome_modo]);
      }
      else{
        cout << "Este modo não existe!" << endl;
        Wait1();
      }
    }

    // Mudar nome de modo
    else if(esc == 5){
      
      string nome_modo;
      cout << "Digite o nome do modo que deseja configurar: ";
      cin.ignore();
      getline(cin, nome_modo);

      bool existe = false;
      for(auto it : house.modos_){
        if(it.first == nome_modo){
          existe = 1;
        }
      }
      if(existe){

        string novo_nome = "";
        cout<<"Digite o novo nome do modo: ";
        cin>>novo_nome;

        house.modos_[nome_modo].SetNome(novo_nome);
        house.modos_[novo_nome] = move(house.modos_[nome_modo]);
        house.modos_.erase(nome_modo);
        cout << "Modo " << nome_modo << " renomeado!";
        Wait1();
      }
      else{
        cout << "Este modo não existe!" << endl;
        Wait1();
      }
    }
  }
}