#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "carregaarquivo.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    CarregaArquivo arquivo;    // Instância da classe Carrega Arquivo

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    QQmlContext * rootContext = engine.rootContext();           // Instância a classe Carrega Arquivo no contexto QML, o que permite acessar o método lerArquivo(0
    rootContext->setContextProperty("arquivo", &arquivo);


    return app.exec();
}
