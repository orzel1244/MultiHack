import QtQuick 2.9
import QtQuick.Controls 2.3

Item {
    id: root
    width: 120
    height: 40
    signal accepted
    property string text: "Binded: "+keyName
    property string keyName
    property bool isListening: false
    property color fontColor1: "#bdc3c7"
    property color fontColor2: "#ffffff"
    function askForKey(){
        if(!root.isListening){
            txt.text = "Press Key"
        }
        root.isListening = true
        root.focus = true
    }
    Timer {
        id: focusTimer
        interval: 500; running: root.focus; repeat: true
        onTriggered: {
            if(txt.color == root.fontColor1){
                txt.color = root.fontColor2
            }else{
                txt.color = root.fontColor1
            }
        }
    }

    Keys.onPressed: {
        if(root.isListening){
            switch(event.key){
            case 16777251:
                root.keyName="ALT";
                break;
                // root.keyName="RMB";
            default:
                root.keyName=event.text.toUpperCase();
                break;
            }
            console.log(event.key);
            txt.text = "Binded: "+root.keyName
            root.isListening = false
            root.focus = false
            txt.color = root.fontColor1
            root.accepted()
        }
    }
    FontLoader {
        id: roboto
        source: "../assets/fonts/Roboto-Light.ttf"
    }

    Rectangle {
        id: rectangle
        color: "#2c3e50"
        anchors.fill: parent
        Text {
            id: txt
            width: 100
            font.family: roboto.name
            height: 34
            color: root.fontColor1
            text: root.text
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 11
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            if(!root.focus){
                txt.color = root.fontColor2
            }
        }
        onExited: {
            if(!root.focus){
                txt.color = root.fontColor1
            }
        }
        onClicked: {
            root.askForKey()
        }
    }
}
