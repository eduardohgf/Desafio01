# Desafio01

1. Criar um software baseado em Qt com interface gráfica usando QML.

- Requisitos

a) Tela Inicial - deve conter 03 botões - "Abrir Arquivo" - "Enviar Comando" - "Sair/Encerrar"

a.0) O usuário deve ser capaz de voltar para a tela principal que exibe os três botões

a.1) O botão "Sair/Encerrar" encerra o software


b) Abrir Arquivo - escolher um arquivo e exibir o conteúdo.

b.0) O software deve ir para uma nova tela em que o elemento principal é um exibidor de texto (TextArea)

b.1) Nesta nova tela além do espaço para exibir o texto, o software deve exibir um botão que ao ser clicado exiba um diálogo de seleção/escolha de arquivo (componente QML FileDialog)

b.2) Ao selecionar o arquivo, o software ler o arquivo e exibir o conteúdo em um componente QML (TextArea)

b.3) Software não deve permitir que o texto seja editado

b.4) A leitura do conteúdo do arquivo, deve ser feito através de uma classe C++ que utilizará QFile

b.5) Essa classe C++ deverá ser instanciada dentro da nova tela do componente QML, para fazer a leitura do arquivo e retornar o conteúdo

b.6) É essencial a integração entre C++ e QML para a execução dessa atividade


c) Enviar Comando - enviar um texto para uma outra aplicação na mesma máquina (Inter Process Communication) [Pode ser implementado em DBUS ou ZeroMQ]

c.0) O software deve ir para uma nova tela em que haja três elementos:

c.0.0) Entrada de texto: nome do tópico a ser transmitido

c.0.1) Entrada de texto: texto a ser enviado

c.0.2) Botão: Enviar

c.1) O usuário deve preencher o nome do tópico que pretende publicar no campo de texto indicado por "Tópico"

c.2) O usuário deve preencher o conteúdo a ser publica no campo de texto indicado por "Conteúdo"

c.3) Ao clicar no botão Enviar o conteúdo deve ser publicado no tópico digitado

c.4) O software de recepção deve receber o conteúdo publicado

 
d) Lista de Arquivos / Estrutura do Projeto

d.0) Segue abaixo os arquivos esperados, é preciso deixar claro que é apenas uma sugestão, podendo o resultado final ter mais classes ou menos classes a depender da arquitetura de implementação.

d.1) A estrutura de arquivos abaixo não precisa ser seguida rigorosamente.
 
- envia.pro - caso usar qmake

- CMakeLists.txt - caso usar cmake

- main.cpp - arquivo principal cpp

- main.qml - arquivo principal qml - Recomenda-se o uso do componente StackView para a alternância entre as diversas telas da aplicação

- Principal.qml (menu principal com 03 botões)

- AbreArquivo.qml (tela com exibidor de texto e botão para escolha do arquivo)

- TransmiteComando.qml (tela com entrada de texto, exibidor de texto e botão para enviar)

- CarregaArquivo.h/CarregaArquivo.cpp (classe c++ responsavel por ler o arquivo)

- EnviaComando.h/EnviaComando.cpp (classe c++ responsavel por fazer IPC - Inter Process Communication - pode-se usar zeromq ou dbus)
