import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3



RowLayout
{
    id: stupidRow
    signal textfieldchanged(bool activeFocus)
    property string myText
    property string labelText

    Layout.fillWidth: true
            spacing: 2
            Label
            {
                id: myLabel
                text: labelText
                color: "black"
                font.pixelSize: 20
            }

            TextField{
                id: thisTextfield
                font.pixelSize: 20
                color: "black"
                text: myText
                Layout.fillWidth: true
                Layout.rightMargin: 30
                height: 40
                background: Rectangle{
                    radius: 10

                    border.color: "#333"
                    border.width: 1
                }

                onTextChanged:
                {
                    myText = thisTextfield.text
                }

                onActiveFocusChanged:
                {
                    textfieldchanged(activeFocus)
                }
            }
}

