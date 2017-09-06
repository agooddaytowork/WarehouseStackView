import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.1
import QtQuick.VirtualKeyboard 2.1


Item {

    Rectangle
    {
        anchors.fill: parent

        Image {
            id: background
            anchors.fill: parent
            source: "../images/background.jpg"
            fillMode: Image.Stretch
        }


            TextField
            {
                id: passwordField
                width: 250
                height: 40
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                echoMode: TextInput.Password
                horizontalAlignment: TextInput.AlignHCenter
                inputMethodHints:  Qt.ImhDigitsOnly
                background: Rectangle
                {

                    radius: 10
                    border.color: "#051c42"
                    border.width: 3
                }
            }


        Rectangle
        {
            width: 300
            height: 86
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.bottomMargin: 100
            anchors.rightMargin: 200

            Image {
                id: logo
                source: "../images/Kla-logo-purplepng.png"
                anchors.fill: parent
                fillMode: Image.Stretch
            }

        }

    }
    InputPanel {
            id: inputPanel
            y: Qt.inputMethod.visible ? (parent.height - inputPanel.height +100 ) : parent.height
            anchors.left: parent.left
            anchors.right: parent.right
            scale: 0.7

        }


}
