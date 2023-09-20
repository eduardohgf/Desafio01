#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "carregaarquivo.h"
#include "enviacomando.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    CarregaArquivo arquivo;    // Instancia da classe Carrega Arquivo
    EnviaComando comando;      // Instancia da classe Envia Comando
    comando.enviaMensagem("/", "Testando");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    QQmlContext * rootContext = engine.rootContext();           // Instancia a classe Carrega Arquivo no contexto QML, o que permite acessar o método lerArquivo(0
    rootContext->setContextProperty("arquivo", &arquivo);
    rootContext->setContextProperty("comando", &comando);

    return app.exec();
}
