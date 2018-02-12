import QtQuick 2.0
import "../components"

Item {
    id: bunnyHop
    anchors.fill: parent
    FontLoader {
        id: roboto
        source: "../assets/fonts/Roboto-Light.ttf"
    }
    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width-15
        height: parent.height-15
        spacing: 8
        Item{width: 1; height: 3;}
        KeyPicker {
            keyName: "SPACE"
            onAccepted: {
                var a = keyTranslator.getCode(keyName);
                if(a === 404){
                    askForKey()
                } else {
                    bunnyhop.setBindKey(keyTranslator.getCode(keyName))
                }
            }
        }
    }

    CustomButton {
        width: 120
        text: "Disabled"
        anchors.right: parent.right
        anchors.rightMargin: 8
        y: window.height-(height*2)-8
        onClicked: {
            if(bunnyhop.isEnabled()){
                bunnyhop.setEnabled(false);
                text = "Disabled";
                bunnyHopTab.showInjector = false
            } else {
                bunnyhop.setEnabled(true);
                text = "Enabled"
                bunnyHopTab.showInjector = true
            }
        }
    }
}
