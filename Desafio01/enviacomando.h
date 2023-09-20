#ifndef ENVIACOMANDO_H
#define ENVIACOMANDO_H

#include <QString>
#include <QObject>
#include <QStringList>
#include <QDBusConnection>
#include <QtDBus/QDBusMessage>
#include <QDebug>

class EnviaComando: public QObject
{
    Q_OBJECT

public:
    EnviaComando();

public slots:
    void enviaMensagem(QString topico, QString conteudo); //Método envia comando

private:

};
#endif // ENVIACOMANDO_H
