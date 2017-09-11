import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.1
import QtQuick.Dialogs 1.1

Item {
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
                           x:m_left
                           y:m_top
                           text: stationName


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
                       }


               }
           }


       }
