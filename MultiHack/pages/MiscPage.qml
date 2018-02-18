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
        GridLayout{
            columns: 2
            columnSpacing: 25
            CustomCheckBox {
                id: noFlashCheck
                text: qsTr("No Flash")
                onClicked: {
                    if(checked){
                        silentNoFlash.checked = !checked
                        misc.setSilentNoFlash(silentNoFlash.checked)
                    }
                    misc.setNoFlash(checked)
                }
            }
            CustomCheckBox {
                id: silentNoFlash
                text: qsTr("Silent No Flash")
                onClicked: {
                    if(checked){
                        noFlashCheck.checked = !checked
                        misc.setNoFlash(noFlashCheck.checked)
                    }
                    misc.setSilentNoFlash(checked)
                }
            }
            CustomCheckBox {
                text: qsTr("Radar")
                onClicked: {
                    misc.setRadar(checked)
                }
            }
        }
    }
}
