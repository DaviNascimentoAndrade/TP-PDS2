#ifndef ARCONDICIONADO_H_
#define ARCONDICIONADO_H_

#include<iostream>

using namespace std;

class ArCondicionado {

    public:

        // cria um novo arcondicionado sem nome
        ArCondicionado();

        // coloca um nome para o ar condicionado
        void SetNome(string nm);

        // retorna o nome do ar condicionado
        string Nome();

        // muda intensidade do ar condicionado
        void SetIntensidade(int in);

        // retorna intensidade do ar condicionado
        int Intensidade();

        // liga ou desliga o ar condicionado(0 desligado)
        void SetLigar(bool li);

        // retorna status da tranca da janela
        bool Ligado();

        // configura temperatura do ar-condicionado.Precondição:a temperatura deve ter valor entre 16 e 30
        void SetTemperatura(int temp); 
        
        
        //retorna temperatura do ar condiciona
        int Temperatura ();


    private:
        int temperatura;
        bool ligado;
        int intensidade;
        string nome;
};

#endif ARCONDICIONADO_H_
