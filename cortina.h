#ifndef CORTINA_H
#define CORTINA_H

#include <string> // Você precisa incluir a biblioteca <string> para usar strings.

using namespace std;
class Cortina {
public:
    // Construtor da classe Cortina
    Cortina(); // Este deve ser um construtor, portanto não precisa do tipo "void".

    // Configura a quantidade que a cortina está fechada ou aberta.
    // @param novaIntensidade: A nova intensidade da cortina (0-100).
    void SetIntensidade(int novaIntensidade);

    // Retorna o status de iluminação da cortina.
    int Intensidade();

    // Retorna o nome da cortina.
    std::string Nome(); // Use std::string para o tipo de dados string.

    // Muda o nome do dispositivo.
    void SetNome(std::string novoNome);

private:
    int intensidade_cortina;
    std::string nome; 
};

#endif