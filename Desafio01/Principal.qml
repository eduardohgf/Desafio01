import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

// Tela Inicial com 3 Botões

Rectangle {
    width: 640
    height: 480
    color:"gray"

    // Centraliza os Botões
    RowLayout {
        anchors.centerIn: parent

        Button { // Botão Tela Abrir Arquivo
            id:tarquivo
            text: "Abrir Arquivo"
            onClicked: stackView.push("AbrirArquivo.qml")
        }

        Button{ // Botão Envia Comando
            id:tenviacomando
            text:"Enviar Comando"
            onClicked: stackView.push("TransmiteComando.qml")
        }

        Button { // Botão Sair do APP
            id: bsair
            text: "Sair/Encerrar"
            onClicked: Qt.quit()
        }
    }
}
