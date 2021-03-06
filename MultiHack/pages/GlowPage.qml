import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
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
        CustomCheckBox {
            checked: false
            text: "Glow Team"
            onClicked: {
                glow.setGlowTeam(checked)
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
            if(glow.isEnabled()){
                glow.setEnabled(false);
                text = "Disabled";
                glowTab.showInjector = false
            } else {
                glow.setEnabled(true);
                text = "Enabled"
                glowTab.showInjector = true
            }
        }
    }
}
