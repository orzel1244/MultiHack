import QtQuick 2.9
import QtQuick.Controls 2.3

TabButton {
    id: tab
    text: qsTr("Trigger Bot")
    property bool showInjector: false
    contentItem: Row {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 8
        Item{width: 1; height: 3;}
        Rectangle {
            visible: tab.showInjector
            width: 10
            height: width
            color: "#2ecc71"
            radius: 1000
            anchors.verticalCenter: parent.verticalCenter
        }
        Text {
            text: tab.text
            anchors.verticalCenter: parent.verticalCenter
            font: tab.font
            opacity: enabled ? 1.0 : 0.3
            color: "#ffffff"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }
    }
    background: Rectangle {
        id: rectangle
        implicitWidth: 200
        implicitHeight: 40
        color: tab.checked ? "#34495e" : "#2c3e50"
        //            color: tab.down ? "#34495e" : "#2c3e50"
    }
}
