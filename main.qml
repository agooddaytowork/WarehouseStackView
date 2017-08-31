import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.1
import QtQuick.Dialogs 1.1

ApplicationWindow {
    id: stationPage
    visible: true
    width: 1920
    height: 1080
    title: qsTr("Station Page")

//    Rectangle {
//        color: "#212126"
//        anchors.fill: parent
//    }

    ToolBar{
        id:theToolBar
        width: parent.width
        height: 50
//        opacity: mainStackView.depth > 1 ? 1 : 0
        Rectangle {
            color: "#A2A2A2"
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
                opacity: mainStackView.depth > 1 ? 1 : 0
                anchors.verticalCenter: parent.verticalCenter
                antialiasing: true
                height: 60
                radius: 4
                color: backmouse.pressed ? "#222" : "transparent"
                Behavior on opacity { NumberAnimation{} }
                Image {
                    anchors.verticalCenter: parent.verticalCenter
                    source: "images/navigation_previous_item.png"
                }
                MouseArea {
                    id: backmouse
                    anchors.fill: parent
                    anchors.margins: -10
                    onClicked: mainStackView.pop()
                }
            }
        }
    }

    StackView{
        id: mainStackView
        anchors.fill: parent

        focus:true
        initialItem: Item {
            id: mainPage

            Rectangle
            {
                id:depotFloor
                width: 1200
                height: 1000
                color: "#A2A2A2"
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.topMargin: 100
                anchors.leftMargin: 360

                Repeater
                {
                    id: warehouseMap

                    width: 1200
                    height: 1000

                    model: myStationModel

                    Button
                    {
                        id: individualStation
                        height: 60
                        width: 60
                        text: stationName
                        x:m_left
                        y:m_top
                        onClicked:
                        {
                            mainStackView.push(Qt.resolvedUrl("qml/StationPage.qml"),{sRFID: RFID})
                        }
                    }
                }
            }


        }
    }
}

