import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.VirtualKeyboard 2.1

Item {
    property string mytext

    TextField{
        width: parent.width
        wrapMode: Label.Wrap

        text:mytext

        font.pixelSize: 20
        color: "black"
        background: Rectangle{
            radius: 10
            implicitWidth: 100
            implicitHeight: 30
            border.color: "#333"
            border.width: 1
        }

    }
}
