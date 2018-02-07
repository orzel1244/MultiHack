import QtQuick 2.9
import QtQuick.Controls 2.3
import "../components"

Item {
    id: root
    implicitHeight: 40
    property int value: 100
    property string unit: "%"
    property int step: 5
    property int from: 5
    property int to: 185
    FontLoader {
        id: roboto
        source: "../assets/fonts/Roboto-Light.ttf"
    }

    function change(type){
        if(type === "+"){
            if(root.value+root.step <= root.to){
                root.value+=root.step
                textRow.assign()
            }
        }
        if(type === "-"){
            if(root.value-root.step >= root.from){
                root.value-=root.step
                textRow.assign();
            }
        }
        root.valueChanged(root.value)
    }

    Row {
        id: row
        anchors.fill: parent
        CustomButton {
            width: root.height
            height: root.height
            text: "-"
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                change("-");
            }
            Timer {
                id: decreaseTimer
                interval: 80; running: false; repeat: true
                onTriggered: change("-")
            }
            onPressAndHold: {
                decreaseTimer.start()
            }
            onReleased: {
                decreaseTimer.stop()
                decreaseTimer.running = false
            }
            onCanceled: {
                decreaseTimer.stop()
                decreaseTimer.running = false
            }
        }
        Rectangle {
            id: rectangle
            width: root.width-(root.height*2)-border.width
            height: root.height-border.width
            anchors.verticalCenter: parent.verticalCenter
            color: "#34495e"
            border.width: 2
            border.color: "#2c3e50"
            Row {
                id: textRow
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                function assign(){
                    vText.text = root.value
                    vTextUnit.text = root.unit
                }
                spacing: 3
                Text {
                    id: vText
                    color: "#ffffff"
                    font.pointSize: 15
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    text: root.value
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: roboto.name
                }
                Text {
                    id: vTextUnit
                    color: "#ffffff"
                    font.pointSize: 12
                    height: 15
                    anchors.bottom: vText.bottom
                    anchors.bottomMargin: 4
                    text: root.unit
                    verticalAlignment: Text.AlignVCenter
                    font.family: roboto.name
                }
            }
        }

        CustomButton {
            width: root.height
            height: root.height
            text: "+"
            onClicked: {
                change("+");
            }
            Timer {
                id: increaseTimer
                interval: 80; running: false; repeat: true
                onTriggered: change("+")
            }
            onPressAndHold: {
                increaseTimer.start()
            }
            onReleased: {
                increaseTimer.stop()
            }
            onCanceled: {
                increaseTimer.stop()
            }
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
