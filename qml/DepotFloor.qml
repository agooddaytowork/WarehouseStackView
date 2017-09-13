import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.1
import QtQuick.Dialogs 1.1

Item {
           id: mainPage

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
               anchors.topMargin: 100
               anchors.leftMargin: 360

               radius: 10

               Repeater
               {
                   id: warehouseMap

                   width: 1200
                   height: 1000

                   model: myStationModel



                   Rectangle
                   {
                       width: 100
                       height: 100
                       x:m_left
                       y:m_top
                       color: "transparent"

                       MouseArea
                       {
                           id: mouse
                           anchors.fill: parent
                           drag.target: individualStation
                           drag.axis: Drag.XAndYAxis
                           drag.minimumY: 0
                           drag.maximumY: warehouseMap.height - 80
                           drag.minimumX: 100
                           drag.maximumX: warehouseMap.width - 140
                           visible: false
                           onClicked:
                           {
                               mainStackView.push(Qt.resolvedUrl("StationPage.qml"),
                                                  {sGlobalId: GlobalId,
                                                  sRFID: RFID,
                                                  sKTPN: KTPN,
                                                  sStationName: stationName,
                                                  sKTSERIALPN: KTSERIALPN,
                                                  sLPN: LPN,
                                                  sSUPPLIERTESTDATE: SUPPLIERTESTDATE,
                                                  sMFGGUNOFFPRESSURE:GUNOFFPRESSURE,
                                                  sPONumber: PO,
                                                  sDATERECEIVED: ReceviedDate,
                                                  sDATESHIPPED: ShippedDate})
                           }
                       }
                       Label{
                           width: 70
                           height: 20
                           anchors.top: parent.top
                           anchors.left: parent.left
                           text: "Type"
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

                           contentItem: Text
                           {
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
                           {
                               radius:5
                               gradient: Gradient {
                                        GradientStop {
                                            position: 0.0
                                            SequentialAnimation on color {
                                                loops: Animation.Infinite
                                                ColorAnimation { from: "#14148c"; to: "#0E1533"; duration: 5000 }
                                                ColorAnimation { from: "#0E1533"; to: "#14148c"; duration: 5000 }
                                            }
                                        }
                                        GradientStop {
                                            position: 1.0
                                            SequentialAnimation on color {
                                                loops: Animation.Infinite
                                                ColorAnimation { from: "#14aaff"; to: "#437284"; duration: 5000 }
                                                ColorAnimation { from: "#437284"; to: "#14aaff"; duration: 5000 }
                                            }
                                        }
                                    }
                           }

                           onClicked:
                           {

                               mainStackView.push(Qt.resolvedUrl("StationPage.qml"),
                                                  {sGlobalId: GlobalId,
                                                  sRFID: RFID,
                                                  sKTPN: KTPN,
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


       }
