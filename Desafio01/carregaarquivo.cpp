#include "carregaarquivo.h"

CarregaArquivo::CarregaArquivo()
{

}

//Função Ler Arquivo
QString CarregaArquivo::lerArquivo(const QUrl& fileUrl)
{
    QString path = fileUrl.toString();                      // Converte o QUrl em uma QString
    path.replace("file://","");                             // Retirada do file://
    QFile file(path);                                       // Criação de um novo QFile
    file.open(QIODevice::ReadOnly | QIODevice::Text);       // Abre o Arquivo
    allText = file.readAll();                               // Lê o Arquivo
    return allText;                                         // Retorna o conteúdo do arquivo como uma QString
}
