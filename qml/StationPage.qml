import QtQuick 2.7
import QtCharts 2.1

Item {
    id: stationPage

    property string sRFID

    ChartView{
        id: chartView
        anchors.topMargin: 50
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: 1400
        theme: ChartView.ChartThemeDark
        antialiasing: true

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
             testLabel.text = touch1.x - initialX

               axisX1.min = new Date(axisX1.min - (touch1.x - initialX))
               axisX1.max = new Date(axisX1.max - (touch1.x - initialX))
           }
       }

       LogValueAxis{
           id: axisY1
           base: 10
           max: 1e-5
           min: 1e-11
           labelFormat: "%.2e"
       }

       DateTimeAxis{
           id: axisX1
           tickCount: 10
           min: new Date(new Date() - 10000)
           max: new Date()
           format: "MMM dd:hh:mm:ss"


       }

       LineSeries{
           id: mySeries
           name: "Pressure"
           axisX: axisX1
           axisY: axisY1
           useOpenGL: true
            width: 4
            color: "red"
            style: Qt.DotLine

       }

       Timer{
           id: testTimer
           interval: 3000
           repeat: true
           running: true
           onTriggered: {

               axisX1.min = new Date(new Date() - 10000)
               axisX1.max = new Date()
               mySeries.append(toMsecsSinceEpoch(new Date()), 5e-8)

           }

           function toMsecsSinceEpoch(date) {
               var msecs = date.getTime();
               return msecs;
           }
        }
    }

    ControlPanel{
        rFID: sRFID
        id: stationControlPanel
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.topMargin: 50
        anchors.rightMargin: 100


    }
}
