import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtQuick.VirtualKeyboard 2.1
Item {
    id: stationSettingsPage

    property int    sGlobalId
//    property string sStationName
//    property string sEgunType
//    property double sthresholdDownP
//    property double sthresholdUpP
//    property double sthresholdDownI
//    property double sthresholdUpI
//    property int sPumpType
//    property int sPumpAddr
//    property int sPumpCh
//    property int sSDCSAddr
//    property int sSDCSCh

    Rectangle
    {
        width: 400

        anchors.top: parent.top
        anchors.topMargin: 60
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        border.color: "black"
        border.width: 1
        color: "#cecece"

        ListView
        {
            id: stationList
            focus: true
            currentIndex: -1
            model:myStationModel
            anchors.fill: parent
            clip: true

            delegate: ItemDelegate
            {
                width: parent.width
                text: "Station: " + stationName
                font.pixelSize: 20

                highlighted: ListView.isCurrentItem
                onClicked: {
                    stationList.currentIndex = index
                    sGlobalId = GlobalId
                    stationname.myText = stationName
                }
            }
            ScrollIndicator.vertical: ScrollIndicator{}
        }
    }
    Rectangle
    {
        width: 1520
        anchors.top: parent.top
        anchors.topMargin: 60
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        border.color: "black"
        border.width: 1

        Flickable
        {
            id: stationSettingsFlickable
            anchors.fill: parent
            flickableDirection:  Flickable.VerticalFlick
            clip: true

            ColumnLayout
            {
                id: column
                width: parent.width
                height: parent.height
                spacing: 5

                Label{
                    width: parent.width
                    wrapMode: Label.Wrap
                    verticalAlignment: Qt.AlignVCenter
                    text:"Station ID: " + sGlobalId
                    font.pixelSize: 25
                }

                FrusTextField{
                    id: stationname
                    width: parent.width
                    labelText: "Station Name: "



                    onTextfieldchanged:
                    {
                        if(activeFocus)
                        {
                            keyboardRect.visible = activeFocus
                            var posWithinFlickable = mapToItem(column, 0, height / 2);
                            stationSettingsFlickable.contentY = posWithinFlickable.y - stationSettingsFlickable.height / 2;
                        }
                    }
                }

                Row
                {
                    Label
                    {
                        text: "Egun Type: "
                        font.pixelSize: 20
                    }

                    ComboBox{
                        id: egunTypeCombobox
                        currentIndex: 0
                        font.pixelSize: 20
                        width: 300
                        model: ListModel
                        {
                            ListElement{text:"CIP"; }
                            ListElement{text:"AMRAY"}
                            ListElement{text:"FEI"}
                            ListElement{text:"ES800 HV1"}
                            ListElement{text:"ES800 HV2"}
                            ListElement{text:"LOGAN"}
                        }
                    }
                }



            }


        }
    }


    Rectangle {
        id: keyboardRect
        width: parent.width
        height: parent.height * 0.4
        anchors.bottom: parent.bottom
        color: "transparent"
        visible: false
    }

    InputPanel {
        id: inputPanel
        y: Qt.inputMethod.visible ? (parent.height - inputPanel.height +100 ) : parent.height
        anchors.left: parent.left
        anchors.right: parent.right
        scale: 0.7
    }



}
