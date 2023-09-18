import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5


// Cria a janela do aplicativo e seta o Principal.qml como tela inicial

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Desafio 01")
    color:"gray"

    StackView {
        id: stackView
        width: ApplicationWindow.width
        height: ApplicationWindow.height

        initialItem: Qt.resolvedUrl("qrc:/Principal.qml")
    }
}
