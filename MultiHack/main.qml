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
}
