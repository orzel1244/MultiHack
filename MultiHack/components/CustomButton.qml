import QtQuick 2.9
import QtQuick.Controls 2.3

Button {
    id: control
    width: 110
    height: 40
    contentItem: Text {
            text: control.text
            font: control.font
            opacity: enabled ? 1.0 : 0.3
            color: control.down ? "#ffffff" : "#bdc3c7"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }
    background: Rectangle {
            implicitWidth: 100
            implicitHeight: 40
            opacity: enabled ? 1 : 0.3
            color: control.down ? "#34495e" : "#2c3e50"
            border.width: 2
            border.color: control.down ? "#2c3e50" : "transparent"
            radius: 2
        }
}
