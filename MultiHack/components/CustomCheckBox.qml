import QtQuick 2.6
import QtQuick.Controls 2.1

CheckBox {
    id: control
    text: qsTr("CheckBox")
    checked: false
    FontLoader {
        id: roboto
        source: "../assets/fonts/Roboto-Light.ttf"
    }

    contentItem: Text {
        color: "#ffffff"
        text: control.text
        font.family: roboto.name
        font.pointSize: 10
        opacity: enabled ? 1.0 : 0.3
        verticalAlignment: Text.AlignVCenter
        leftPadding: control.indicator.width + control.spacing
    }
}
