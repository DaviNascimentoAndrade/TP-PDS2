#ifndef Casa_H_
#define Casa_H_

#include<iostream>
#include<map>
#include<string>

using namespace std;

class Casa {

    public:

        // cria uma novo casasem nome
        Casa();

        // coloca um nome para a casa
        void SetNome(string nm);

        // retorna o nome da casa
        string Nome();
        
        //Lista todos os cômodos da casa;
        void ListarComodos(); 
        
        //Enquanto essa função estiver ativa, o usuário pode configurar todos os dispositivos da casa normalmente e todas as configurações feitas serão salvas em um modo;
        void ConfigurarModo(string nm); 
        
        //Aplica as conficurações de um modo salvo;
        void AtivarModo (string nm);  
        
        //Lista os modos da casa;
        void ListarModos(); 
        
        //Adiciona um cômodo para que o usuário possa edita-lo;
        void AdicionarComodo(string nm); 
       
       //Apaga um cômodo e todos os dispositivos nele; 
        void RemoverComodo(string nm);


    private:
        class Comodo;
        map<string, Comodo> comodos;
        map<string, Casa> modos;
        string nome;

};

#endif Casa_H_