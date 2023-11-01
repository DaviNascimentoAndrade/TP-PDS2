#include<iostream>
#include<string>
#include "cortina.h"

using namespace std;

int main() {
    int x;
     string y;

    cin>>x;
    cin>>y;
    Cortina cortina;
    cortina.SetIntensidade(x);  // Define a intensidade da cortina
    cortina.SetNome(y); //  Muda o nome do dispositivo.

    // Imprime a intensidade usando cout
    cout <<"A intensidade da cortina é = "<<  cortina.Intensidade() << endl;
    cout <<"O nome da cortina é:"<<  cortina.Nome()<<endl;

    return 0;
}
