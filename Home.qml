import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.12

Item {
    anchors.fill: parent


    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: myText.bottom
        anchors.topMargin: 50
        spacing: 50

        Button {
            id: onePlayerButton
            width: 250
            height: 100
            onClicked: { mainLoader.source = "Play.qml"; myCaro.clearData()}
            Text {
                text: "1 Player"
                anchors.centerIn: parent
                font.pixelSize: 25
                font.bold: true
                color: "red"
            }
        }

        Button {
            width: 250
            height: 100
            id: twoPlayerButton
            onClicked: { mainLoader.source = "Play.qml"; myCaro.clearData()}
            Text {
                text: "2 Player"
                anchors.centerIn: parent
                font.pixelSize: 25
                font.bold: true
                color: "red"
            }
        }
    }




    Rectangle{
        anchors.fill: parent
        color: "blue"
        opacity: 0.1
    }

    Text {
        id: myText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 50
        text: "Caro Chess"
        font.pixelSize: 30
        font.bold: true
        color: "Blue"
    }
}
