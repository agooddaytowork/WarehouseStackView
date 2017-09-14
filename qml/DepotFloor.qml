import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.1
import QtQuick.Dialogs 1.1

Item {
    id: mainPage

    property bool  depotEditEnable: false
    Rectangle
    {
        width: 300
        height: 86
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: 0
        anchors.rightMargin: 0

        Image {
            id: logo
            scale: 0.5
            source: "../images/Kla-logo-purplepng.png"
            anchors.fill: parent
            fillMode: Image.Stretch
        }
    }

    Rectangle
    {
        id:depotFloor
        width: 1200
        height: 800
        color: "#cecece"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 200
        anchors.leftMargin: (1920-(depotFloor.width))/2

        radius: 10

        Repeater
        {
            id: warehouseMap

            width: 1200
            height: 800

            model: myStationModel

            Rectangle
            {
                id: myDragcell
                width: 100
                height: 100
                x:m_left
                y:m_top
                color: "transparent"
                property bool currentStation: false
                property int counter: 0
                property int previousX
                property int previousY

                state: "EgunGood"

                states:[
                    State{
                        name:"EgunNotFound"

                        PropertyChanges {
                            target: stationStatus
                            gradient: egunNotFoundGradient
                        }
                        PropertyChanges {
                            target: individualStationTextContent
                            color: "white"
                        }
                    },
                    State{
                        name:"EgunGood"
                        PropertyChanges {
                            target: stationStatus
                            gradient: egunGoodGradient
                        }
                        PropertyChanges {
                            target: individualStationTextContent
                            color: "white"
                        }

                    },
                    State{
                        name:"EgunWarning"
                        PropertyChanges {
                            target: stationStatus
                            gradient: egunWarningGradient
                        }
                        PropertyChanges {
                            target: individualStationTextContent
                            color: "white"
                        }
                    },
                    State{
                        name:"EgunAlert"
                        PropertyChanges {
                            target: stationStatus
                            gradient: egunAlertGradient
                        }
                        PropertyChanges {
                            target: individualStationTextContent
                            color: "white"
                        }
                    }

                ]

                MouseArea
                {
                    id: mouse
                    anchors.fill: parent
                    drag.target: myDragcell
                    drag.axis: Drag.XAndYAxis
                    drag.minimumY: 0
                    drag.maximumY: warehouseMap.height - 100
                    drag.minimumX: 0
                    drag.maximumX: warehouseMap.width - 100
                    visible: depotEditEnable
                    z: 2 // higher z


                    onMouseXChanged:
                    {
                        myDragcell.currentStation = true

                        for(var i=0; i < warehouseMap.count; i++)
                        {
                            if(!(warehouseMap.itemAt(i).currentStation))
                            {
                                var outerw = warehouseMap.itemAt(i).width +20;
                                var outerh = warehouseMap.itemAt(i).height + 20;

                                var outerx = warehouseMap.itemAt(i).x - 10
                                var outery = warehouseMap.itemAt(i).y - 10

                                var width = 0.5* (myDragcell.width + outerw)
                                var height = 0.5* (myDragcell.height + outerh)

                                var dx = (myDragcell.x +50) - (outerx + 60)
                                var dy = (myDragcell.y + 50) - (outery + 60)
                                if(Math.abs(dx) <= width && Math.abs(dy) <= height)
                                {

                                    var wy = width * dy;
                                    var hx = height * dx;

                                    if(wy >= hx)
                                    {
                                        if( wy >= -hx)
                                        {
                                            //snap inter bottom
                                            myDragcell.y = warehouseMap.itemAt(i).y + myDragcell.height
                                            console.log("collision with the outer box bottom")

                                            if(Math.abs(myDragcell.x - warehouseMap.itemAt(i).x) <= 10)
                                            {
                                                myDragcell.x = warehouseMap.itemAt(i).x
                                            }


                                        }
                                        else
                                        {
                                            // snap inter left
                                            myDragcell.x = warehouseMap.itemAt(i).x - myDragcell.width
                                            console.log("collision with the outer box left")
                                            if(Math.abs(myDragcell.y - warehouseMap.itemAt(i).y) <= 10)
                                            {
                                                myDragcell.y = warehouseMap.itemAt(i).y
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(wy >= -hx)
                                        {
                                            // snap inter right
                                            myDragcell.x = warehouseMap.itemAt(i).x + myDragcell.width
                                            console.log("collision with the outer box right")
                                            if(Math.abs(myDragcell.y - warehouseMap.itemAt(i).y) <= 10)
                                            {
                                                myDragcell.y = warehouseMap.itemAt(i).y
                                            }
                                        }
                                        else
                                        {
                                            // snap inter top
                                            myDragcell.y = warehouseMap.itemAt(i).y - myDragcell.height
                                            console.log("collision with the outer box top")

                                            if(Math.abs(myDragcell.x - warehouseMap.itemAt(i).x) <= 10)
                                            {
                                                myDragcell.x = warehouseMap.itemAt(i).x
                                            }
                                        }
                                    }
                                    //                                                                                                 myDragcell.state="InterBoundary"
                                }
                            }
                        }
                        myDragcell.currentStation = false
                    }
                }

                Label{
                    width: 70
                    height: 20
                    z:1
                    anchors.top: parent.top
                    anchors.left: parent.left
                    text: egunType
                    font.pixelSize: 12
                    font.bold: true
                    color: "black"
                    verticalAlignment:  Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    background: Rectangle
                    {
                        color: "transparent"
                    }

                }

                Button
                {
                    id: individualStation
                    height: 65
                    width: 70
                    text: stationName
                    z:1
                    contentItem: Text
                    {
                        id: individualStationTextContent
                        text: individualStation.text
                        font.pixelSize: 20
                        font.bold: true

                        color: "white"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter

                    }



                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 20
                    background: Rectangle
                    {   id:stationStatus
                        radius:5
                    }

                    onClicked:
                    {

                        mainStackView.push(Qt.resolvedUrl("StationPage.qml"),
                                           {sGlobalId: GlobalId,
                                               sRFID: RFID,
                                               sKTPN: KTPN,
                                               sEgunType: egunType,
                                               sStationName: stationName,
                                               sKTSERIALPN: KTSERIALPN,
                                               sLPN: LPN,
                                               sSUPPLIERTESTDATE: SUPPLIERTESTDATE,
                                               sMFGGUNOFFPRESSURE:GUNOFFPRESSURE,
                                               sPONumber: PO,
                                               sDATERECEIVED: ReceviedDate,
                                               sDATESHIPPED: ShippedDate})
                    }

                    onDoubleClicked:
                    {

                    }
                }
            }
        }
    }

    Gradient {
        id: egunNotFoundGradient
        GradientStop {
            position: 0.0
            SequentialAnimation on color {
                loops: Animation.Infinite
                ColorAnimation { from: "#14148c"; to: "#0E1533"; duration: 5000 }
                ColorAnimation { from: "#0E1533"; to: "#14148c"; duration: 5000 }
            }
        }
        GradientStop {
            position: 2.0
            SequentialAnimation on color {
                loops: Animation.Infinite
                ColorAnimation { from: "#14aaff"; to: "#437284"; duration: 5000 }
                ColorAnimation { from: "#437284"; to: "#14aaff"; duration: 5000 }
            }
        }
    }


    Gradient {
        id: egunGoodGradient
        GradientStop {
            position: 1.0
            SequentialAnimation on color {
                loops: Animation.Infinite
                ColorAnimation { from: "#4ba84c"; to: "#16dd18"; duration: 5000 }
                ColorAnimation { from: "#16dd18"; to: "#4ba84c"; duration: 5000 }

            }
        }

        GradientStop {
            position: 0.0
            SequentialAnimation on color {
                loops: Animation.Infinite
                ColorAnimation { from: "#62a060"; to: "#2ea32a"; duration: 5000 }
                ColorAnimation { from: "#2ea32a"; to: "#62a060"; duration: 5000 }

            }
        }
    }
    Gradient {
        id: egunAlertGradient
        GradientStop {
            position: 0.0
            SequentialAnimation on color {
                loops: Animation.Infinite
                ColorAnimation { from: "#fc8364"; to: "#f74e22"; duration: 5000 }
                ColorAnimation { from: "#f74e22"; to: "#fc8364"; duration: 5000 }

            }
        }

    }

    Gradient {
        id: egunWarningGradient
        GradientStop {
            position: 0.0
            SequentialAnimation on color {
                loops: Animation.Infinite
                ColorAnimation { from: "#f7e874"; to: "#ffe414"; duration: 5000 }
                ColorAnimation { from: "#ffe414"; to: "#f7e874"; duration: 5000 }

            }
        }

    }

}
