# TP-PDS2
Trabalho prático da disciplina PDS2, sistema de automação residencial 


Alunos:
Arthur Caetano de Oliveira - 2023039309;
Breno Pereira Miranda - 2023038930;
Davi Nascimento Andrade da Silva - 2023038817;
Lucas Abreu Velloso - 2023038795;
Lucas Monteiro Henriques- 2023038868;

O Manual de estilo ultilizado no projeto pode ser acessado pelo link: https://google.github.io/styleguide/cppguide.html#C++_Version

1. Apresentação do Problema:

Nos últimos anos, principalmente durante a pandemia do Covid-19, houve o surgimento e crescimento explosivo da
indústria 4.0. Além disso, houve grande desenvolvimento e popularização das tecnologias da informação, que tomaram
papéis importantes em todas as áreas de consumo, auxiliando as pessoas a resolverem diversos problemas e a
melhorarem a qualidade de vida. Uma das novas aplicações que surgiu nesse crescimento foi a automação
residencial, atra- vés de soluções de engenharia de controle e automação, que permite controlar diversos
aspectos de uma casa de forma automática, como iluminação, temperatura, segurança, etc.

A falta de automação residencial pode gerer diversas problematicas como falta de conectividade e personalização ,
conforto e segurnaça comprometido,além de ineficiencia energetica e consequentimente mais gastos financeiros.

Tendo em vista a relevância do tópico apresentado e a proximidade com nossa área de estudo no curso, decidimos 
realizar esse trabalho com o objetivo de desenvolver um sistema de automação residencial, que visa controlar
e automatizar vários aspectos de uma casa comum, como controlar ativação de luzes, abertura de cortinas,
ar condicionado,criação de modos que empregam o conjunto dessas funcionalidades etc.


2. Visão Geral da Solução:

Nossa solução visa que o usuário consiga controlar , de forma rapida ,facil e totalmente remota, sua casa.
O programa ira conseguir controlar,por meio de um menu no terminar, cada objeto separadamente ou de maneira geral tanto
no cômodo quanto na casa,todas as entidades do programa possuem classes de objetos que são organizadas segundo a
lógica de programação orientada a objeto. 


3. Estrutura do Projeto:
   
O projeto será separado em classes, 7 no total, cada classe irá possuir um arquivo .h (encontrados presente na pasta "include") 
e um .cc (encontrados na pasta "src"),além de uma main que possui o código referente ao display do menu("encontrado na pasta src).

No própio github é possível analisar a presença de pasta "testes" no qual mostra  testes minimalista sobre as funcionalidades 
presentes nas classe ar_condicionado, cortina ,trancajanela,lampada. Além do uso de um makefile utilizado para compilar 
o código de maneira mais eficiente e rápida.

Todos os arquivos necessários e que serão ultilizados ficara disponível no link: https://github.com/DaviNascimentoAndrade/TP-PDS2



4. Instruções de Instalação:
   
O usuário precisará de:
•	Ambiente de edição 
•	Compilador(compatível com o sistema operacional do usuário) 


5. Instruções de Uso:
   
O usuário, através de um menu disponibilizado no terminal, terá a oportunidade de interagir com o sistema, empregando números 
e palavras para realizar diversas transações.

O usuário terá a capacidade de personalizar individualmente cada dispositivo, podendo alterar seu status por meio das funcionalidades específicas disponibilizadas para cada aparelho, bem como modificar seu nome. Além disso, será possível modificar o status de um grupo de dispositivos similares. Essas funcionalidades são facilmente acessíveis por meio de escolhas simples, utilizando tanto números quanto palavras.

Além de criar modos pré-determinados pelo úsuario sobre a casa também utilizado palavras e números. 


6. Principais Dificuldades:
   
Entre as dificuldades apresentadas no Tp-2 ,a integração das classes, as descrições dos cartões CRCs, 
o controle de versão por meio das funcionalidades do GitHub e Git, o tratamento de exceções, 
e a concepção de um design abrangente na main que incorpore todas as funcionalidades do projeto representam 
desafios significativos para os colaboradores envolvidos.
