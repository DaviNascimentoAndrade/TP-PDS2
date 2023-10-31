#ifndef CORTINA_H_
#define CORTINA_H_

#include <string> 

using namespace std;
class Cortina {
public:
// Construtor da classe Cortina
Cortina(); // Construtor

// Configura a quantidade que a cortina está fechada ou aberta.
// @param novaIntensidade: A nova intensidade da cortina (0-100).
void SetIntensidade(int novaIntensidade);

// Retorna o status de iluminação da cortina.
int Intensidade();

// Retorna o nome da cortina.
string Nome(); 

// Coloca um nome na cortina.
void SetNome(string novoNome);

private:
int intensidade_cortina_;
string nome_; 
};

#endif
