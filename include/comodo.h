#ifndef COMODO_H_
#define COMODO_H

#include <map>
#include <string>
#include "lampada.h"
#include "ar_condicionado.h"
#include "tranca.h"
#include "janela.h"
#include "cortina.h"

class Comodo{
public:

//Cria um comodo vazio
Comodo();

//Adiciona um novo dispositivo de algum tipo
void AdicionarDispositivo(int tipo, string nome);

//Lista todos os dispositivos de um tipo, sendo Lampada,Cortina,Arcondicionado,Tranca e Janela, 1,2,3,4 e 5 respectivamente
void ListarDispositivos(int tipo);

//Remove um dispositivo, de um tipo, do comodo, sendo Lampada,Cortina,Arcondicionado,Tranca e Janela, 1,2,3,4 e 5 respectivamente
//Precondição: o dispositivo deve existir para que ele possa ser removido
void RemoverDispositivo(int tipo, string nome);

//Configura todos os dispositivos de um mesmo tipo no comodo, sendo Lampada,Cortina,Arcondicionado,Tranca e Janela, 1,2,3,4 e 5 respectivamente
void ConfigurarTodos(int tipo);

//Configura o nome do comodo;
void SetNome(string nome);

//Retorna o nome do Comodo
string Nome();





private:
map<string,Lampada> lampadas_;
map<string,Cortina> cortinas_;
map<string,ArCondicionado> ares_condicionados_;
map<string,Tranca> trancas_;
map<string, Janela> janelas_;
string nome_;

};


#endif // COMODO_H_
