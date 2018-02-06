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
    Row {
        id: row
        anchors.fill: parent
        CustomButton {
            width: root.height
            height: root.height
            text: "-"
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                if(root.value-root.step >= root.from){
                    root.value-=root.step
                    vText.assign();
                }
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
            Text {
                id: vText
                color: "#ffffff"
                font.pointSize: 15
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: root.value+root.unit
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                function assign(){
                    text = root.value+root.unit
                }
            }
        }

        CustomButton {
            width: root.height
            height: root.height
            text: "+"
            onPressAndHold: {
                console.log("press and hold")
            }

            onClicked: {
                if(root.value+root.step <= root.to){
                    root.value+=root.step
                    vText.assign()
                }
            }
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
