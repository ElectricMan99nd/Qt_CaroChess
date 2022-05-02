import QtQuick 2.0
import QtQuick.Controls 2.2

Rectangle {
    anchors.fill: parent

    GridView {
        id: myGrid
        anchors.fill: myRec1
        anchors.margins: 10
        cellWidth: 20
        cellHeight: 20
        model: 400

        clip: true
        delegate: Button {
            id: playButton
            width: 20
            height: 20
            onClicked:{
                if(playButton.text === ""){
                    playButton.text = myCaro.caroXO();
                    myCaro.caroToaDo(index);
                    myText.text = myCaro.playerCheckWin();
                }
            }
        }

    }

    Column {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 20
        spacing: 50

        Button {
            id: resetButton
            width: 150
            height: 100
            onClicked: mainLoader.source = "Home.qml"
            Text {
                text: "Home"
                anchors.centerIn: parent
                font.pixelSize: 25
                font.bold: true
                color: "red"
            }
        }

        Button {
            width: 150
            height: 100
            id: undoButton
            Text {
                text: "Undo"
                anchors.centerIn: parent
                font.pixelSize: 25
                font.bold: true
                color: "red"
            }
        }
    }




    Rectangle {
        id: myRec1
        width: 420
        height: 420
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.verticalCenter: parent.verticalCenter
        color: "yellow"
        opacity: 0.3
        border.width: 10
        border.color: "green"
    }

    Rectangle {
        anchors.fill: parent
        color: "blue"
        opacity: 0.1
    }

    Text {
        id: myText
        anchors.centerIn: myRec1
        font.pixelSize: 40
        font.bold: true
        color: "red"
    }

    Text {
        text: "Caro Chess was make by Tung & Duy (3/5/2022)"
        font.pixelSize: 10
        anchors.horizontalCenter: myRec1.horizontalCenter
        anchors.top: myRec1.bottom
        anchors.topMargin: 10
    }
}

