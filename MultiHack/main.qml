import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "components"
import "pages"

ApplicationWindow {
    id: window
    visible: true
    width: 460
    height: 250
    title: qsTr("MultiHack")
    minimumWidth: 420
    minimumHeight: 250
    FontLoader {
        id: roboto
        source: "./assets/fonts/Roboto-Light.ttf"
    }
    header: TabBar {
        id: bar
        width: parent.width
        background: Rectangle { color: "#2c3e50"; width: parent.width; height: parent.height;}
        CustomTabButton {
            id: triggerBotTab
            text: "Trigger Bot"
            width: 140
        }
        CustomTabButton {
            id: bunnyHopTab
            text: "Bunny hop"
            width: 130
        }
        CustomTabButton {
            id: glowTab
            text: "Glow"
            width: 85
        }
        CustomTabButton {
            id: miscTab
            text: "Misc"
            width: 60
        }

    }
    Rectangle {
        anchors.fill: parent
        color: "#34495e"
    }
    StackLayout {
        width: parent.width
        currentIndex: bar.currentIndex
        TriggerBotPage { }
        BunnyHopPage { }
        GlowPage { }
        MiscPage { }
    }

    Rectangle {
        id: rect
        enabled: true
        color: "#34495e"
        visible: !anti.isAuthorized()
        anchors.fill: parent
        function check(){
            if(anti.auth(tf.text)){
                rect.enabled = false
                rect.visible = false
            } else {
                tf.text = ""
            }
        }

        Column {
            id: column
            width: parent.width-80
            height: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 16
            Item {width: 1; height: 3;}
            Text {
                width: 370
                color: "#f9f9f9"
                text: "This is anti noob protection, you can't access the cheat unless you know password. \nContact Maciej Rosiak"
                font.family: roboto.name
                wrapMode: Text.WordWrap
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 12
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 6
                TextField {
                    id: tf
                    focus: true
                    echoMode: TextInput.Password
                    placeholderText: "Enter Password"
                    Keys.onReturnPressed: {
                        rect.check()
                    }
                }
                CustomButton {
                    text: "Ok"
                    onClicked: {
                        rect.check()
                    }
                }
            }
        }
    }
}
