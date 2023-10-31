#ifndef ARCONDICIONADO_H_
#define ARCONDICIONADO_H_

#include<iostream>
#include <string>

using namespace std;

class ArCondicionado {

    public:

// cria um novo arcondicionado sem nome
ArCondicionado();

// coloca um nome para o ar condicionado
void SetNome(string nome);

// retorna o nome do ar condicionado
string Nome();

// muda o modo do ar condicionado
//PRECONDIÇÃO: Deve ser cool, heat, dry ou fan
void SetModo(string modo);

// retorna o modo do ar condicionado
string Modo();

// liga ou desliga o ar condicionado(0 desligado)
void SetLigar(bool li);

// retorna status da tranca da janela
bool Ligado();

// configura temperatura do ar-condicionado.
//PRECONDIÇÃO:a temperatura deve ter valor entre 16 e 30
void SetTemperatura(int temp); 
        
//retorna temperatura do ar condicionado
int Temperatura ();


    private:
    int temperatura_;
    bool ligado_;
    string modo_;
    string nome_;
};

#endif ARCONDICIONADO_H_
