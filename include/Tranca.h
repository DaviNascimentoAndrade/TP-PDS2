#ifndef TRANCA_H_
#define TRANCA_H_

#include<iostream>

using namespace std;

class Tranca {

  public:

// Cria uma traca sem nome
Tranca();

        // Muda o nome da tranca
        void SetNome(string name);

// Retorna o nome da tranca
string Nome();

// Muda estado de ativação da tranca
void SetAtiva(bool ativo);

// Retorna estado de ativação da tranca
bool Ativa();
    
private:

string nome;
bool ativa;

};

#endif TRANCA_H_
