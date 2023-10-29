#ifndef COMODO_H_
#define COMODO_H

#include <map>
#include <string>
#include "Casa.h"
#include "Lampada.h"
#include "ArCondicionado.h"
#include "Tranca.h"
#include "Janela.h"
#include "Cortina.h"

class Comodo{
public:

//Cria um comodo vazio
Comodo();

//Adiciona um dispositivo da classe Lampada
void AdicionarLampada(string nome, string cor, int intensidade);

//Adiciona um dispositivo da classe Cortina
void AdicionarCortina(string nome,int intensidade);

//Adiciona um dispositivo da classe Arcondicionado
void AdicionarArcondicionado(string nome, int temperatura, string modo,bool ligado);

//Adiciona um dispositivo da classe  Tranca
void AdicionarTranca(string nome, bool ativa);

//Adiciona um dispositivo da classe Janela
void AdicionarJanela(string nome, int intensidade, bool trancada);

//Lista todos os dispositivos de um tipo, sendo Lampda,Cortina,Arcondicionado,Tranca e Janela, 1,2,3,4 e 5 respectivamente
void ListarDispositivos(int tipo);

//Remove um dispositivo, de um tipo, do comodo, sendo Lampda,Cortina,Arcondicionado,Tranca e Janela, 1,2,3,4 e 5 respectivamente
void RemoverDispositivo(int tipo, string nome);

//Configura todos os dispositivos de um mesmo tipo no comodo, sendo Lampda,Cortina,Arcondicionado,Tranca e Janela, 1,2,3,4 e 5 respectivamente
void ConfigurarTodos(int tipo);

//Configura o nome do comodo;
void SetNome(string nome);

//Retorna o nome do Comodo
string Nome();





private:
map<string,Lampada> lampadas;
map<string,Cortina> cortinas;
map<string,ArCondicionado> ares_condicionados;
map<string,Tranca> trancas;
map<string, Janela> janelas;
string nome;

};


#endif COMODO_H_