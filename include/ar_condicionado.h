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

    // seta a intensidade
    void SetIntensidade(int in);

    // retorna a intensidade
    int Intensidade();

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
    int intensidade_;
    string nome_;
};

#endif // ARCONDICIONADO_H_
