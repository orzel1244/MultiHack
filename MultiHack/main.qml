import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("MultiHack")
    Button {
        text: "turn on"
        onClicked: {
            if(triggerbot.isEnabled()){
                triggerbot.setEnabled(false);
            } else {
                triggerbot.setEnabled(true);
            }
        }
    }
}
