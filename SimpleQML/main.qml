import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    color: "#ffffff"
    title: qsTr("Hello World")

    Text {
        id: element
        x: 109
        y: 182
        width: 423
        height: 117
        text: qsTr("Hello, World!")
        fontSizeMode: Text.Fit
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 32
    }
}
