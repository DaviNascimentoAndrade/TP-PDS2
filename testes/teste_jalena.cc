#include<iostream>
#include "../include/janela.h"

using namespace std;

int main(){
    Janela teste;
    teste.SetNome("janela1");
    cout<<teste.Nome()<<endl;
    teste.SetIntensidade(30);
    cout<<teste.Intensidade()<<endl;
    teste.SetTranca(0);
    cout<<teste.Tranca()<<endl;
    return 0;
}