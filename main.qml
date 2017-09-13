import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.1
import QtQuick.Dialogs 1.1
import "qml"
ApplicationWindow {
    id: stationPage
    visible: true
    width: 1920
    height: 1080
    title: qsTr("Station Page")

    ToolBar{
        id:theToolBar
        width: parent.width
        height: 50
        opacity: mainStackView.depth > 1 ? 1 : 0
        Rectangle {
            color: "#0884C4"
            anchors.fill: parent
        }

        RowLayout
        {
            anchors.fill: parent
            Rectangle {
                id: backButton
                width: opacity ? 60 : 0
                anchors.left: parent.left
                anchors.leftMargin: 20
                opacity: mainStackView.depth > 2 ? 1 : 0
                anchors.verticalCenter: parent.verticalCenter
                antialiasing: true
                height: 60
                radius: 4
                color: backmouse.pressed ? "#222" : "transparent"
                Behavior on opacity { NumberAnimation{} }
                Image {
                    anchors.verticalCenter: parent.verticalCenter
                    source: "images/navigation_previous_item.png"
                    scale: 0.6
                }
                MouseArea {
                    id: backmouse
                    anchors.fill: parent
                    anchors.margins: -10
                    onClicked: mainStackView.pop()
                }
            }

//            Button
//            {
//                id:settingButton
//                anchors.top: parent.top
//                anchors.right: parent.right
//                anchors.rightMargin: 20
//                text: "Edit"
//                opacity: mainStackView.depth == 2 ? 1 : 0
//                Image {
//                    anchors.verticalCenter: parent.verticalCenter
//                    source: "images/navigation_previous_item.png"
//                }

//                onClicked:
//                {

//                    mainStackView.push(Qt.resolvedUrl("qml/FruManagePage.qml"))

//                }
//            }
        }
    }

    StackView{
        id: mainStackView
        anchors.fill: parent

        focus:true
        initialItem: LogInPage
        {
            id: mainPage
        }

    }
}

