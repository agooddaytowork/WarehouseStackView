import QtQuick 2.7
import QtCharts 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Item {
    id: stationPage

    property int    sGlobalId
    property string sRFID
    property string sKTPN
    property string sKTSERIALPN
    property string sLPN
    property string sSUPPLIERTESTDATE
    property string sMFGGUNOFFPRESSURE
    property string sPONumber
    property string sDATERECEIVED
    property string sDATESHIPPED


    ChartView{
        id: chartView
        anchors.topMargin: 50
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: 1200
        theme: ChartView.ChartThemeDark
        antialiasing: true
        property  int initialX
       MultiPointTouchArea
       {
           anchors.fill: parent
           minimumTouchPoints: 1
           maximumTouchPoints: 2
           mouseEnabled: true
           touchPoints: [
               TouchPoint { id: touch1 },
               TouchPoint { id: touch2 }
           ]

    //               onReleased: {
    //                    testLabel.text = touch1.x
    //               }

           onPressed: {
               initialX = touch1.x
           }

           onGestureStarted:
           {
//             testLabel.text = touch1.x - initialX

               axisX1.min = new Date(axisX1.min - (touch1.x - initialX))
               axisX1.max = new Date(axisX1.max - (touch1.x - initialX))
           }
       }

       LogValueAxis{
           id: axisY1
           base: 10
           max: 1e-7
           min: 1e-12
           labelFormat: "%.2e"

       }

       DateTimeAxis{
           id: axisX1
           tickCount: 6
           min: new Date(new Date() - 100000)
           max: new Date()
           format: "MMM\dd hh:mm"

       }

       LineSeries{
           id: pressureSerie
           name: "Pressure"
           axisX: axisX1
           axisY: axisY1
           useOpenGL: true
            width: 4
            color: "red"
            style: Qt.DotLine

       }

        Timer
        {
            id:loadGraphFirstTime
            interval:0
            repeat: false
            running:true
            onTriggered:
            {
                LocalDb.initializeDataToGraph(pressureSerie,axisX1, sRFID)
            }
        }
    }

    Rectangle{
        id: stationControlPanel
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.topMargin: 50
        anchors.rightMargin: 100
        width: 300

        ColumnLayout {
        anchors.fill: parent
            spacing: 8
            Layout.fillHeight: true

            Label{
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignVCenter
                text:"E-source Information"
                font.pixelSize: 30

            }
            Label{
                id: rfid
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"RFID: " + sRFID
                font.pixelSize: 20
            }

            Label{
                id: ktpn
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"KTPN: " + sKTPN
                font.pixelSize: 20
            }
            Label{
                id: ktserialpn
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"KT Serial PN: " + sKTSERIALPN
                font.pixelSize: 20
            }
            Label{
                id: lpn
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"LPN: "+ sLPN
                font.pixelSize: 20
            }
            Label{
                id: supplierTestDate
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"Supplier Test Date: " + sSUPPLIERTESTDATE
                font.pixelSize: 20
            }
            Label{
                id: mfgPressureoff
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"MFG Gun off GV Closed: "+ sMFGGUNOFFPRESSURE
                font.pixelSize: 20
            }
            Label{
                id: purchaseOrder
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"PO: " + sPONumber
                font.pixelSize: 20
            }
            Label{
                id: dateReceive
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"Date Received: " + sDATERECEIVED
                font.pixelSize: 20
            }
            Label{
                id: dateShipped
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"Date Shipped: " + sDATESHIPPED
                font.pixelSize: 20
            }


                Switch{
                    id: hvONSwitch
                    text:"HV ON"
                    checked: false

                }
                Switch{
                    id: protectOnSwitch
                    text:"Protect ON"
                    checked: false

                }


                Switch
                {
                    id: valveONSwitch
                    text: "Valve ON"
                    checked: false

                }

                Button
                {
                    id: shipButton
                    text: "Ship"
                    Layout.fillWidth: true
                }


        }

    }

}
