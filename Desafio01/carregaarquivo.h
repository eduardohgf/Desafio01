#ifndef CARREGAARQUIVO_H
#define CARREGAARQUIVO_H

#include <QObject>
#include <QDebug>
#include <QQuickView>
#include <QString>
#include <QFile>

class CarregaArquivo : public QObject
{
    Q_OBJECT
public:
    CarregaArquivo();

private:
    QString allText;

public slots:
    QString lerArquivo(const QUrl& fileUrl);  //Método de Leitura do Arquivo
};

#endif // CARREGAARQUIVO_H
