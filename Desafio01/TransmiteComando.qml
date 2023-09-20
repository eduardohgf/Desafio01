import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.3

Rectangle {
    id:tenvia
    width: 640
    height: 480
    color: "gray"
    Button{ // Botão Voltar
        id:bvoltar
        text:"Voltar"
        anchors.top: parent.top
        anchors.left: parent.left
        onClicked: stackView.push("Principal.qml")
    }
    Column{
        id:coluna
        anchors.centerIn: parent
        spacing: 5
        Rectangle{
            id:menu
            width: 250
            height: 150
            color:"darkgray"
            radius: 4
            anchors.centerIn: parent

            ColumnLayout{
                id:boxtext
                anchors.fill: parent
                Text{
                    id:topic
                    text:" Tópico:"
                }
                Rectangle {
                    id:areati
                    width: boxtext.width
                    height: topic.height +3
                    TextInput{
                        id:topico
                        anchors.fill: parent
                        text:'/'
                    }
                }
                Text{
                    id:conteudo
                    text:" Conteúdo:"
                }
                Rectangle {
                    id:areacont
                    width: boxtext.width
                    height: conteudo.height +3
                    TextInput{
                        id:textcontent
                        anchors.fill: parent
                    }
                }
                Button { //Botão EnviarComando
                    id:benvia
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    text: "Enviar"
                    onClicked: {
                        comando.enviaMensagem(topico.text, textcontent.text);
                    }
                }
            }
        }
    }
}
