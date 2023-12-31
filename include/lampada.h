#ifndef LAMPADA_H_
#define LAMPADA_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Lampada{
public:

// Cria uma lâmpada sem nome com intensidade 0;
Lampada();

//Configura a intensidade da lâmpada;
//PRECONDIÇÃO: A intensidade deve ser de 0 a 100;
void SetIntensidade(int i);

//Retorna intensidade da lâmpada;
int Intensidade ();

//PRECONDIÇÃO: Devem ser inseridas somente cores válidas, como amarelo,vermelho, azul,branco,laranja,verde ou roxo
//Seta a cor da lãmpada
void SetCor(string c);

//Retorna a cor atual da lâmpada;
string Cor();

//Lista as cores que a lâmpada pode mostrar;
void ListarCores();

//Muda o nome do dispositivo;
void SetNome(string name);

//Retorna o nome do dispositivo.
string Nome();


private:
string nome_;
string cor_;
int intensidade_;
vector<string> cores_ ={"Amarelo", "Vermelho","Azul","Verde","Roxo","Branco","Laranja","amarelo"
,"vermelho","azul","verde","roxo","branco","laranja"};
};
#endif // LAMPADA_H_
