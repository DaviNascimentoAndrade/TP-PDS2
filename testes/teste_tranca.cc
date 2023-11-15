#include <iostream>

#include "../include/tranca.h"

//Pra testar a tranca

using namespace std;

int main(){
    Tranca breno;
    breno.SetNome("breno");
    cout << breno.Nome() << endl;
    breno.SetAtiva(true);
    cout << breno.Ativa() << endl;

}
