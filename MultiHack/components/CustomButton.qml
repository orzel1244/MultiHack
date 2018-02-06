import QtQuick 2.9
import QtQuick.Controls 2.3

Button {
    id: control
    width: 110
    height: 40
    property int minW
    property int minH
    Component.onCompleted: {
        minW = width
        minH = height
    }

    NumberAnimation on width {
        id :wAnimIn
        from: minW
        to: minW+3;
        duration: 75
        running: false
    }
    NumberAnimation on height {
        id :hAnimIn
        from: minH
        to: minH+3;
        duration: 75
        running: false

    }
    NumberAnimation on width {
        id :wAnimOut
        from: minW+3
        to: minW;
        duration: 75
        running: false
    }
    NumberAnimation on height {
        id :hAnimOut
        from: minH+3
        to: minH;
        duration: 75
        running: false
    }
    contentItem: Text {
        id: txt
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#ffffff" : "#bdc3c7"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }
    background: Rectangle {
        id: rect
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        color: control.down ? "#34495e" : "#2c3e50"
        radius: 2
    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            if(txt.color != "#ffffff"){
                txt.color = "#ffffff"
            }
        }
        onExited: {
            if(txt.color != "#bdc3c7"){
                txt.color = "#bdc3c7"
            }
        }
        onPressed: {
            wAnimIn.start()
            hAnimIn.start()
        }

        onClicked: {
            control.clicked();
        }
        onReleased: {
            wAnimOut.start()
            hAnimOut.start()
        }
        onPressAndHold: {
            control.pressAndHold()
        }
    }
}
