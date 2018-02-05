import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("MultiHack")
    Button {
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
}
