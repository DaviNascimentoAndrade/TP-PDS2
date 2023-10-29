#ifndef LAMPADA_H_
#define LAMPADA_H_

#include <string>
#include <vector>
using namespace std;

class Lampada{
public:
    
    // Cria uma lâmpada sem nome com intensidade 0;
     Lampada();

    //Configura a intensidade da lâmpada;
    //PRECONDIÇÃO: A intensidade deve ser de 0 a 100;
    void SetIntensidade(int x);

    //Retorna intensidade da lâmpada;
    int Intensidade ();

    //PRECONDIÇÃO: Devem ser inseridas somente cores válidas, como amarelo,vermelho, azul,branco,laranja,verde ou roxo
    //Seta a cor da lãmpada
    void SetCor(int);

    //Retorna a cor atual da lâmpada;
    string Cor();

    //Lista as cores que a lâmpada pode mostrar;
    void ListarCores();

    //Muda o nome do dispositivo;
    void SetNome(string);

    //Retorna o nome do dispositivo.
    string Nome();


private:
string nome, modo;
int cor;
vector <string> cores;
};
#endif
