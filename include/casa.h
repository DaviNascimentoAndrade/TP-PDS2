#ifndef CASA_H_
#define CASA_H_

#include<iostream>
#include<map>
#include "comodo.h"
#include "lampada.h"
#include "ar_condicionado.h"
#include "tranca.h"
#include "janela.h"
#include "cortina.h"
#include<string>

using namespace std;

class Casa {

public:

// cria uma novo casasem nome
Casa();

// coloca um nome para a casa
void SetNome(string nm);

// retorna o nome da casa
string Nome();
        
//Lista todos os cômodos da casa;
void ListarComodos(); 
        
//Aplica as conficurações de um modo salvo;
void AtivarModo (string nm);  
        
//Lista os modos da casa;
void ListarModos(); 
        
//Adiciona um cômodo para que o usuário possa edita-lo;
void AdicionarComodo(string nm); 
       
//Apaga um cômodo e todos os dispositivos nele; 
void RemoverComodo(string nm);


private:
map<string, Comodo> comodos_;
map<string, Casa> modos_;
string nome_;

};

#endif // CASA_H_
