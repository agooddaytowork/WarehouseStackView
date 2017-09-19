import QtQuick 2.7
import QtCharts 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtQuick.VirtualKeyboard 2.1

Item {
    id: stationPage

    property int    sGlobalId
    property string sStationName
    property string sEgunType
    property string sRFID
    property string sKTPN
    property string sKTSERIALPN
    property string sLPN
    property string sSUPPLIERTESTDATE
    property string sMFGGUNOFFPRESSURE
    property string sPONumber
    property string sDATERECEIVED
    property string sDATESHIPPED
    property bool   sHVON
    property bool sProtectON
    property bool sValveON



    ChartView{
        id: chartView
        anchors.topMargin: 50
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: 1200
        theme: ChartView.ChartThemeBlueNcs
        animationOptions:  ChartView.SeriesAnimations
        antialiasing: true
        property  int initialX
        property int  initialY
        property double currentScale


        function toMsecsSinceEpoch(date) {
            var msecs = date.getTime();
            return msecs;
        }
        PinchArea{
            width: parent.width
            height: parent.height

            onPinchStarted: {
                chartView.currentScale = pinch.scale
                chartView.initialX = pinch.center.x
            }

            onPinchUpdated: {
                chartView.scrollLeft(pinch.center.x - pinch.previousCenter.x)
                chartView.scrollUp(pinch.center.y - pinch.previousCenter.y)

                if(Math.abs(pinch.center.x - chartView.initialX) >= 100)
                {
                    LocalDb.updateDataToGraph(pressureSerie, axisX1.min, axisX1.max, sRFID)

                    chartView.initialX = pinch.center.x
                }
                console.log("currentScale: " + chartView.currentScale)
                if(Math.abs(pinch.scale - chartView.currentScale) >= 0.3)
                {
                    console.log("Enter scale function")
                    chartView.currentScale = pinch.scale

                    if (pinch.scale < 1)
                    {

                        if(Math.abs(chartView.toMsecsSinceEpoch(axisX1.min) - chartView.toMsecsSinceEpoch(axisX1.max)) <(24*60*60*1000))
                        {
                            axisX1.min = new Date(axisX1.min - 1000000*(1/pinch.scale))
                            axisX1.max = new Date(axisX1.max + 1000000*(1/pinch.scale))
                        }
                        else
                        {
                            axisX1.min = new Date(axisX1.max - (24*60*60*1000))
                        }
                    }
                    else
                    {
                        if(Math.abs(chartView.toMsecsSinceEpoch(axisX1.min) - chartView.toMsecsSinceEpoch(axisX1.max)) > (20*60*1000))
                        {
                            axisX1.min = new Date(axisX1.min + 1000000*pinch.scale)
                            axisX1.max = new Date(axisX1.max - 1000000*pinch.scale)
                        }
                        else
                        {
                            axisX1.min = new Date(axisX1.max - (20*60*1000))
                        }

                    }

                    LocalDb.updateDataToGraph(pressureSerie, axisX1.min, axisX1.max, sRFID)

                }
                console.log("pinch scale: " + pinch.scale)

            }

            onPinchFinished:
            {
                LocalDb.updateDataToGraph(pressureSerie, axisX1.min, axisX1.max, sRFID)
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
                chartView.currentMaxX = chartView.toMsecsSinceEpoch(axisX1.max)
                chartView.currentMinX = chartView.toMsecsSinceEpoch(axisX1.min)

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
        width: 400
        color: "transparent"
        visible: false



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

                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"RFID: " + sRFID
                font.pixelSize: 20
            }

            Label{

                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"KTPN: " + sKTPN
                font.pixelSize: 20
            }
            Label{

                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"KT Serial PN: " + sKTSERIALPN
                font.pixelSize: 20
            }
            Label{

                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"LPN: "+ sLPN
                font.pixelSize: 20
            }
            Label{

                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"Supplier Test Date: " + sSUPPLIERTESTDATE
                font.pixelSize: 20
            }
            Label{

                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"MFG Gun off GV Closed: "+ sMFGGUNOFFPRESSURE
                font.pixelSize: 20
            }
            Label{

                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"PO: " + sPONumber
                font.pixelSize: 20
            }
            Label{

                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"Date Received: " + sDATERECEIVED
                font.pixelSize: 20
            }
            Label{

                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignLeft
                text:"Date Shipped: " + sDATESHIPPED
                font.pixelSize: 20
            }


            Switch{
                id: hvONSwitch
                text:"HV ON"
                checked: sHVON

            }
            Switch{
                id: protectOnSwitch
                text:"Protect ON"
                checked: sProtectON

            }


            Switch
            {
                id: valveONSwitch
                text: "Valve ON"
                checked: sValveON

            }

            Button
            {
                id: shipButton
                text: "Ship"
                Layout.fillWidth: true

            }

        }

    }


    Flickable{
        id: flickable

        anchors.fill: parent
        anchors.topMargin: 50
        anchors.bottomMargin: keyboardRect.visible ? keyboardRect.height : 100
        anchors.leftMargin: 1400
        visible: true
        flickableDirection: Flickable.VerticalFlick

        Rectangle{
            anchors.fill: parent
            color: "grey"
        }

        ColumnLayout{
            id: column
            width: parent.width
            height: parent.height
            spacing: 10


            Label{
                width: parent.width
                wrapMode: Label.Wrap
                verticalAlignment: Qt.AlignVCenter
                text:"E-source Information"
                font.pixelSize: 30
            }

            FrusTextField{
                id: rfid
                width: parent.width
                labelText: "RFID: "
                myText: sRFID

                onTextfieldchanged:
                {
                    if(activeFocus)
                    {
                        keyboardRect.visible = activeFocus
                        var posWithinFlickable = mapToItem(column, 0, height / 2);
                        flickable.contentY = posWithinFlickable.y - flickable.height / 2;
                    }
                }

            }

            FrusTextField{
                id: ktpn

                labelText: "KT PN: "
                myText: sKTPN

                onTextfieldchanged: {
                    if(activeFocus)
                    {
                        keyboardRect.visible = activeFocus
                        var posWithinFlickable = mapToItem(column, 0, height / 2);
                        flickable.contentY = posWithinFlickable.y - flickable.height / 2;
                    }

                }
            }
            FrusTextField{
                id: ktserialpn

                labelText: "KT Serial PN: "
                myText: sKTSERIALPN

                onTextfieldchanged: {
                    if(activeFocus)
                    {
                        keyboardRect.visible = activeFocus
                        var posWithinFlickable = mapToItem(column, 0, height / 2);
                        flickable.contentY = posWithinFlickable.y - flickable.height / 2;
                    }

                }
            }
            FrusTextField{
                id: lpn

                labelText: "LPN: "
                myText: sLPN

                onTextfieldchanged: {
                    if(activeFocus)
                    {
                        keyboardRect.visible = activeFocus
                        var posWithinFlickable = mapToItem(column, 0, height / 2);
                        flickable.contentY = posWithinFlickable.y - flickable.height / 2;
                    }

                }
            }
            FrusTextField{
                id: supplierTestDate

                labelText: "Supplier Test Date: "
                myText: sSUPPLIERTESTDATE

                onTextfieldchanged: {
                    if(activeFocus)
                    {
                        keyboardRect.visible = activeFocus
                        var posWithinFlickable = mapToItem(column, 0, height / 2);
                        flickable.contentY = posWithinFlickable.y - flickable.height / 2;
                    }

                }
            }
            FrusTextField{
                id: mfgPressureoff

                labelText:"MFG Gun off GV Closed: "
                myText: sMFGGUNOFFPRESSURE

                onTextfieldchanged: {
                    if(activeFocus)
                    {
                        keyboardRect.visible = activeFocus
                        var posWithinFlickable = mapToItem(column, 0, height / 2);
                        flickable.contentY = posWithinFlickable.y - flickable.height / 2;
                    }

                }
            }
            FrusTextField{
                id: purchaseOrder

                labelText: "PO: "
                myText:sPONumber

                onTextfieldchanged: {
                    if(activeFocus)
                    {
                        keyboardRect.visible = activeFocus
                        var posWithinFlickable = mapToItem(column, 0, height / 2);
                        flickable.contentY = posWithinFlickable.y - flickable.height / 2;
                    }

                }
            }
            FrusTextField{
                id: dateReceive

                labelText: "Date Received: "
                myText:sDATERECEIVED
                onTextfieldchanged: {
                    if(activeFocus)
                    {
                        keyboardRect.visible = activeFocus
                        var posWithinFlickable = mapToItem(column, 0, height / 2);
                        flickable.contentY = posWithinFlickable.y - flickable.height / 2;
                    }

                }
            }
            FrusTextField{
                id: dateShipped

                labelText: "Date Shipped: "
                myText: sDATESHIPPED

                onTextfieldchanged: {

                    if(activeFocus)
                    {

                        keyboardRect.visible = activeFocus;
                        var posWithinFlickable = mapToItem(column, 0, height / 2);
                        flickable.contentY = posWithinFlickable.y - flickable.height / 2;
                    }

                }
            }

            Button
            {
                id: updateDatebutton
                text: "Update"
                background: Rectangle{
                    radius: 10
                    implicitWidth: 300
                    implicitHeight: 30
                    border.color: "#333"
                    border.width: 1
                }

                onClicked: {

                    LocalDb.updateStationFruInfo(sGlobalId, ktpn.myText, ktserialpn.myText, lpn.myText, mfgPressureoff.myText, purchaseOrder.myText, supplierTestDate.myText, dateReceive.myText, dateShipped.myText)

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
        y: Qt.inputMethod.visible ? (parent.height - inputPanel.height + 100 ) : parent.height
        anchors.left: parent.left
        anchors.right: parent.right
        scale: 0.7

    }
}
