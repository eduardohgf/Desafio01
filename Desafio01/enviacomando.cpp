#include "enviacomando.h"
#include <QDebug>
#include <QDBusMessage>
#include <QDBusConnection>


EnviaComando::EnviaComando()
{
    // Conecta-se ao D-Bus
    QDBusConnection::sessionBus().registerService("org.example.chat");
    QDBusConnection::sessionBus().registerObject("/", this);
    if(QDBusConnection::sessionBus().isConnected()){
        qDebug() << "Está Conectado";
    }

}

    //Envia Comando
void EnviaComando::enviaMensagem(QString topico, QString conteudo)
{
    QDBusMessage msg = QDBusMessage::createSignal(topico, "org.example.chat", "message") ;
    msg << conteudo;
    QDBusConnection::sessionBus().send(msg);
}


