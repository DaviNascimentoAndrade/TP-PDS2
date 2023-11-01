#include "include/lampada.h"
#include <iostream>

using namespace std;

int main(){
    string nome = "joaozinho";
    string cor = "Vermelho";
    Lampada teste;
    teste.SetIntensidade(85);
    teste.SetCor(cor);
    teste.ListarCores();
    teste.SetNome(nome);
    cout << teste.Nome() <<endl;
    cout << teste.Intensidade() << endl;
    cout << teste.Cor() << endl;

}
