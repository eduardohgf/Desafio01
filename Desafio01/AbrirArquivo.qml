import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.3
import QtQuick.Window 2.3

Rectangle{
    width: 640
    height: 480
    color: "gray"

    ColumnLayout{
        anchors.fill: parent

        Button{ // Botão Voltar
            id:bvoltar
            text:"Voltar"
            onClicked: stackView.push("Principal.qml")
            anchors.top: parent.top
            anchors.left: parent.left
        }

        FileDialog {
            id: fileDialog
            title: "Selecione um arquivo"
            folder: shortcuts.home
            onAccepted: {
                console.log(fileDialog.fileUrl)
                textArea.text = arquivo.lerArquivo(fileDialog.fileUrl)

            }
        }

        // TextArea com ajuste ao texto
        Flickable {
            id: flickable
            width: parent.width
            height: 300
            contentWidth: textArea.implicitWidth
            contentHeight: textArea.implicitHeight
            clip: true
            TextArea {
                id: textArea
                wrapMode: TextArea.Wrap
                readOnly: true
                text:"O conteúdo do arquivo será exibido aqui"

                background: Rectangle {
                    border.color: "white"
                }
            }
            ScrollBar.vertical: ScrollBar {}
            ScrollBar.horizontal: ScrollBar {}
        }

        Button { //Botão Abrir FileDialog
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parents.bottom
            text: "Abrir"
            onClicked: {
                fileDialog.open()
            }
        }


    }
}
