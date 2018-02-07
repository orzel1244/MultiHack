import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "components"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("MultiHack")
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
                CustomButton {
                    width: 160
                    text: "TriggerBot: Disabled"
                    onClicked: {
                        if(triggerbot.isEnabled()){
                            triggerbot.setEnabled(false);
                            text = "TriggerBot: Disabled";
                        } else {
                            triggerbot.setEnabled(true);
                            text = "TriggerBot: Enabled"
                        }
                    }
                }
                CustomSpinBox {
                    width: 190
                    value: 100
                    unit: "%"
                    step: 5
                    from: 5
                    to: 185
                }
                CustomSpinBox {
                    width: 190
                    value: 100
                    unit: "ms"
                    step: 5
                    from: 5
                    to: 185
                }
            }
        }
        Item {
            id: bunnyHop
        }
    }
}
