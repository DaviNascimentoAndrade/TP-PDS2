/*
Menu principal: (feito)
  Comodos
  Modos
  Desligar

  Comodos: (feito)
    Adicionar cômodo() (a fazer)
    Remover cômodo()
    Acessar cômodo
    Voltar

    Comodo específico:
      Acessar dispositivos()
      Mudar nome()
      Voltar

      Dispositivos:
        Lampadas
        ares_condionados
        cortinas
        janelas
        trancas

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
        cout<<"Comodos disponiveis: \n";
        house.ListarComodos();
        string comodo = "";

        // USUÁRIO ESCOLHE O CÔMODO QUE QUER CONFIGURAR
        bool ex = 0;
        while(!ex){

        cout<<"Digite o nome do comodo que deseja acessar: ";
        cin>>comodo;
      
          for(auto it : house.comodos_){
            if(it.first == comodo){
             ex = 1;
            }
          }
          if(!ex){cout<<"Escolha invalida!\n";}
        }
      
        MenuComodo(house, comodo);
      }
    }

    // ADICIONAR COMODO
    else if(esc == 2){
    string comodo = "";
    cout <<"Digite o nome do cômodo que deseja adicionar: ";
    cin>>comodo;
    house.AdicionarComodo(comodo);
    house.comodos_[comodo].SetNome(comodo);
    }

    // REMOVER COMODO
    else if(esc == 3){
    if(house.comodos_.size() < 1){
        cout<<"Nao existem comodos para serem removidos"<<endl;
        system("pause");
      }else{
        // LISTAR COMODOS DISPONÍVEIS PARA REMOVER
        cout<<"Comodos para remoção: \n";
        house.ListarComodos();
        string comodo = "";

        // USUÁRIO ESCOLHE O CÔMODO QUE QUER REMOVER
        bool ex = 0;
        while(!ex){

        cout<<"Digite o nome do comodo que deseja remover: ";
        cin>>comodo;
      
          for(auto it : house.comodos_){
            if(it.first == comodo){
             ex = 1;
            }
          }
          if(!ex){cout<<"Esse cômodo não existe!\n";}
        }
      
        house.RemoverComodo(comodo);
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
      cin>>novo_nome;
      //basicamente cria um novo valor para o map, substitui oq tinha no antigo
      //para o novo e apaga o velho
      house.comodos_[comodo].SetNome(novo_nome);
      house.comodos_[novo_nome] = move(house.comodos_[comodo]);
      house.comodos_.erase(comodo);
      comodo = novo_nome;
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
      if(esc < 1 || esc > 6){cout<<"Escolha invalida!"<<endl;}
    }

    // listar as lampadas
    if(esc == 1){
      bool ex = 0;
      while(!ex){
       comodo.ListarDispositivos(1); 
       cout<< " Digite 1 para voltar: ";
       cin>> ex;
      }
      
    }
    
    //Configurar uma lâmpada
    if(esc == 2){
       cout<<"Lâmpadas para configurar: \n";
      comodo.ListarDispositivos(1);
       string lampada = "";

        // USUÁRIO ESCOLHE A LAMAPADA QUE QUER ALTERAR
        bool ex = 0;
        while(!ex){

        cout<<"Digite o nome da lãmpadas que deseja configurar: ";
        cin>>lampada;
      
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

    }

    //ADICIONAR LAMPADA
    if(esc == 3){
      string nome = "";
      cout<< "Digite o nome da nova lâmpada: ";
      cin>> nome;
      comodo.AdicionarDispositivo(1, nome);
    }

    //REMOVER LAMPADA
    if(esc == 4){
      comodo.ListarDispositivos(1);
     // USUÁRIO ESCOLHE A LAMPADA QUE QUER REMOVER
        bool ex = 0;
        string lampada = "";
        while(!ex){

        cout<<"Digite o nome da lâmpada que deseja remover: ";
        cin>>lampada;
      
          for(auto it : comodo.lampadas_){
            if(it.first == lampada){
             ex = 1;
            }
          }
          if(!ex){cout<<"Essa lâmpada não existe!\n";}
        }
      
        comodo.RemoverDispositivo(1,lampada);
    }


    //CONFIGURAR TODAS AS LAMPADAS
    if(esc == 5){
        comodo.ConfigurarTodos(1);
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

    // listar as cortinas
    if(esc == 1){
      bool ex = 0;
      while(!ex){
       comodo.ListarDispositivos(2); 
       cout<< " Digite 1 para voltar: ";
       cin>> ex;
      }
      
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
        cin>>cortina;
      
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

    }

    //ADICIONAR CORTINA
    if(esc == 3){
      string nome = "";
      cout<< "Digite o nome da nova cortina: ";
      cin>> nome;
      comodo.AdicionarDispositivo(2, nome);
    }

    //REMOVER CORTINA
    if(esc == 4){
      comodo.ListarDispositivos(2);
     // USUÁRIO ESCOLHE A CORTINA QUE QUER REMOVER
        bool ex = 0;
        string cortina = "";
        while(!ex){

        cout<<"Digite o nome da cortina que deseja remover: ";
        cin>>cortina;
      
          for(auto it : comodo.cortinas_){
            if(it.first == cortina){
             ex = 1;
            }
          }
          if(!ex){cout<<"Essa cortina não existe!\n";}
        }
      
        comodo.RemoverDispositivo(2, cortina);
    }


    //CONFIGURAR TODAS AS CORTINAS
    if(esc == 5){
        comodo.ConfigurarTodos(2);
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

    // listar a ar condicionado
    if(esc == 1){
      bool ex = 0;
      while(!ex){
       comodo.ListarDispositivos(3); 
       cout<< " Digite 1 para voltar: ";
       cin>> ex;
      }
      
    }
    
    //Configurar um ar condicionado
    if(esc == 2){
       cout<<"Lâmpadas para configurar: \n";
      comodo.ListarDispositivos(3);
       string ArCondicionado = "";

        // USUÁRIO ESCOLHE A LAMAPADA QUE QUER ALTERAR
        bool ex = 0;
        while(!ex){

        cout<<"Digite o nome do ar condicionado que deseja configurar: ";
        cin>>ArCondicionado;
      
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
        comodo.ares_condicionados_[ArCondicionado].SetLigar(ligado);

        cout<< "Digite a temperatura do Ar Condicionado(de 16 a 30 graus): ";
        cin>>temperatura;
        comodo.ares_condicionados_[ArCondicionado].SetTemperatura(temperatura);

    }

    //ADICIONAR AR CONDIONADO
    if(esc == 3){
      string nome = "";
      cout<< "Digite o nome do novo ar condicionado: ";
      cin>> nome;
      comodo.AdicionarDispositivo(3, nome);
    }

    //REMOVER AR CONDICIONADO
    if(esc == 4){
      comodo.ListarDispositivos(3);
     // USUÁRIO ESCOLHE O AR CONDICIONADO QUE QUER REMOVER
        bool ex = 0;
        string ArCondicionado = "";
        while(!ex){

        cout<<"Digite o nome do ar condicionado que deseja remover: ";
        cin>>ArCondicionado;
      
          for(auto it : comodo.ares_condicionados_){
            if(it.first == ArCondicionado){
             ex = 1;
            }
          }
          if(!ex){cout<<"Esse ar condicionado não existe!\n";}
        }
      
        comodo.RemoverDispositivo(2,ArCondicionado);
    }


    //CONFIGURAR TODAS OS ARES CONDICIONADOS
    if(esc == 5){
        comodo.ConfigurarTodos(3);
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

    // listar as cortinas
    if(esc == 1){
      bool ex = 0;
      while(!ex){
       comodo.ListarDispositivos(4); 
       cout<< " Digite 1 para voltar: ";
       cin>> ex;
      }
      
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
        cin>>tranca;
      
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
        comodo.trancas_[tranca].SetAtiva(trancada);

    }

    //ADICIONAR TRANCA
    if(esc == 3){
      string nome = "";
      cout<< "Digite o nome da nova tranca: ";
      cin>> nome;
      comodo.AdicionarDispositivo(4, nome);
    }

    //REMOVER TRANCA
    if(esc == 4){
      comodo.ListarDispositivos(4);
     // USUÁRIO ESCOLHE A TRANCA QUE QUER REMOVER
        bool ex = 0;
        string tranca = "";
        while(!ex){

        cout<<"Digite o nome da tranca que deseja remover: ";
        cin>>tranca;
      
          for(auto it : comodo.trancas_){
            if(it.first == tranca){
             ex = 1;
            }
          }
          if(!ex){cout<<"Essa tranca não existe!\n";}
        }
      
        comodo.RemoverDispositivo(4, tranca);
    }


    //CONFIGURAR TODAS AS TRANCAS
    if(esc == 5){
        comodo.ConfigurarTodos(4);
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
      if(esc < 1 || esc > 6){cout<<"Escolha invalida!"<<endl;}
    }

    // listar as janelas
    if(esc == 1){
      bool ex = 0;
      while(!ex){
       comodo.ListarDispositivos(5); 
       cout<< " Digite 1 para voltar: ";
       cin>> ex;
      }
      
    }
    
    //Configurar uma janela
    if(esc == 2){
       cout<<"Trancas para configurar: \n";
      comodo.ListarDispositivos(5);
       string janela= "";

        // USUÁRIO ESCOLHE A JANELA QUE QUER ALTERAR
        bool ex = 0;
        while(!ex){

        cout<<"Digite o nome da janela que deseja configurar: ";
        cin>>janela;
      
          for(auto it :comodo.janelas_){
            if(it.first == janela){
             ex = 1;
            }
          }
          if(!ex){cout<<"Essa janela não existe!\n";}
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
        comodo.janelas_[janela].SetTranca(trancada);

        cout<< "Digite a intensidade da janela: ";
        cin>>intensidade;
        comodo.janelas_[janela].SetIntensidade(intensidade);

    }

    //ADICIONAR JANELA
    if(esc == 3){
      string nome = "";
      cout<< "Digite o nome da nova janela: ";
      cin>> nome;
      comodo.AdicionarDispositivo(5, nome);
    }

    //REMOVER JANELA
    if(esc == 4){
      comodo.ListarDispositivos(5);
     // USUÁRIO ESCOLHE A JANELA QUE QUER REMOVER
        bool ex = 0;
        string janela = "";
        while(!ex){

        cout<<"Digite o nome da janela que deseja remover: ";
        cin>>janela;
      
          for(auto it : comodo.janelas_){
            if(it.first == janela){
             ex = 1;
            }
          }
          if(!ex){cout<<"Essa janela não existe!\n";}
        }
      
        comodo.RemoverDispositivo(5, janela);
    }


    //CONFIGURAR TODAS AS JANELAS
    if(esc == 5){
        comodo.ConfigurarTodos(5);
  }
}
}

//Menu Modos
void MenuModos(Casa &house){ //tem que criar esse map de modos ainda
  int esc = 0;
  while(esc != 6){

    system("clear");
    Titulo("MENU DE MODOS -"+ house.Nome());
    cout<<"  1 - Adicionar modo\n";
    cout<<"  2 - Ativar modo\n";
    cout<<"  3 - Remover modo\n";
    cout<<"  4 - Configurar modo\n";
    cout<<"  5 - Listar modos\n";
    cout<<"  6 - Voltar\n";

    esc = 0;
    while(esc < 1 || esc > 6){
      cout<<"Digite sua escolha: ";
      cin>>esc;
      if(esc < 1 || esc > 6){cout<<"Escolha invalida!"<<endl;}
    }

    // Adicionar o modo 
    if(esc == 1){
    string nome_modo="";
    AdicionarModo(house,nome_modo);
    }

    // Ativar o modo
    else if(esc == 2){
    string nome_modo="";
    house.AtivarModo(nome_modo);
    }

    // Remover o modo
    else if(esc == 3){
    string nome_modo="";
    RemoverModo(house,nome_modo);
    }
    
    //Configura o modo
    else if(esc == 4){

    }
    //Listar modos
    else if(esc == 5){
      house.ListarModos();
    }
  }
}