import QtQuick 2.9
import QtQuick.Controls 2.3

TabButton {
    id: tab
    text: qsTr("Trigger Bot")
    contentItem: Text {
            text: tab.text
            font: tab.font
            opacity: enabled ? 1.0 : 0.3
            color: "#ffffff"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }
    background: Rectangle {
            implicitWidth: 200
            implicitHeight: 40
            color: tab.checked ? "#34495e" : "#2c3e50"
//            color: tab.down ? "#34495e" : "#2c3e50"
        }
}
