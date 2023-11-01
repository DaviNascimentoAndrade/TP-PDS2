#ifndef JANELA_H_
#define JANELA_H_

#include<iostream>

using namespace std;

class Janela {

public:

// cria uma janela sem nome
Janela();

// muda o nome da janela
void SetNome(string nm);

// retorna o nome da janela
string Nome();

// muda intensidade da abertura da janela
void SetIntensidade(int in);

// retorna intensidade da janela
int Intensidade();

// muda a tranca da janela (0 aberto)
void SetTranca(bool tr);

// retorna status da tranca da janela
bool Tranca();

private:

string nome_;
int intensidade_;
bool tranca_;
};

#endif
