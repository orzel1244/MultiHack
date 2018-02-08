import QtQuick 2.0
import "../components"

Item {
    id: bunnyHop
    anchors.fill: parent
    FontLoader {
        id: roboto
        source: "../assets/fonts/Roboto-Light.ttf"
    }
    Text {
        color: "#ffffff"
        text: "Coming Soon"
        font.family: roboto.name
        font.pointSize: 21
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        y: parent.height/2+(60)
    }
}
