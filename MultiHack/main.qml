import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "components"

ApplicationWindow {
    id: window
    visible: true
    width: 430
    height: 250
    title: qsTr("MultiHack")
    minimumWidth: 420
    minimumHeight: 250
    FontLoader {
        id: roboto
        source: "./assets/fonts/Roboto-Light.ttf"
    }
    header: TabBar {
        id: bar
        width: parent.width
        background: Rectangle { color: "#2c3e50"; width: parent.width; height: parent.height;}
        CustomTabButton {
            text: "Trigger Bot"
            width: 130
        }
        CustomTabButton {
            text: "Bunny hop"
            width: 100
        }
    }
    Rectangle {
        anchors.fill: parent
        color: "#34495e"
    }
    StackLayout {
        width: parent.width
        currentIndex: bar.currentIndex
        Item {
            id: triggerBot
            anchors.fill: parent
            Column {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width-15
                height: parent.height-15
                spacing: 8
                Item{width: 1; height: 3;}
                Row {
                    spacing: window.width-col1.width-col2.width-12
                    Column {
                        id: col1
                        spacing: 4
                        Text {
                            width: parent.width
                            color: "#ffffff"
                            text: "Delay before fire"
                            font.pointSize: 13
                            verticalAlignment: Text.AlignVCenter
                            font.family: roboto.name
                            horizontalAlignment: Text.AlignHCenter
                        }
                        CustomSpinBox {
                            width: 190
                            value: 100
                            unit: "ms"
                            step: 5
                            from: 5
                            to: 185
                            onValueChanged: triggerbot.setBeforeDelay(value)
                        }
                    }
                    Column {
                        id: col2
                        spacing: 4
                        Text {
                            width: parent.width
                            color: "#ffffff"
                            text: "Delay after fire"
                            font.pointSize: 13
                            verticalAlignment: Text.AlignVCenter
                            font.family: roboto.name
                            horizontalAlignment: Text.AlignHCenter
                        }
                        CustomSpinBox {
                            width: 190
                            value: 100
                            unit: "ms"
                            step: 5
                            from: 5
                            to: 185
                            onValueChanged: triggerbot.setAfterDelay(value)
                        }
                    }
                }
            }
            CustomButton {
                width: 160
                text: "Disabled"
                anchors.right: parent.right
                anchors.rightMargin: 8
                y: window.height-(height*2)-8
                onClicked: {
                    if(triggerbot.isEnabled()){
                        triggerbot.setEnabled(false);
                        text = "Disabled";
                    } else {
                        triggerbot.setEnabled(true);
                        text = "Enabled"
                    }
                }
            }
        }
        Item {
            id: bunnyHop
        }
    }
}
