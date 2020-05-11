import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.0

Window {
    visible: true
    width: 640
    height: 480
    color: "#ffffff"
    title: qsTr("Hello World")


    ColumnLayout {
        x: 109
        y: 141

        TextInput {
            id: myTextInput
            text: "Hello World!"  // a basic greeting
            Layout.preferredHeight: 74
            Layout.preferredWidth: 423
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.capitalization: Font.MixedCase
            font.pointSize: 28
        }

        Text {
            id: showText
            color: "#122fba"
            text: qsTr(myTextInput.text)
            Layout.preferredHeight: 117
            Layout.preferredWidth: 423
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 32
        }
    }
    Rectangle {
        id: background
        x: 0
        y: 0
        color: "#48cbe2"
        Layout.preferredHeight: 480
        Layout.preferredWidth: 640
        border.width: 5

        gradient: Gradient {
            GradientStop { position: 0.0; color: "yellow" }
            GradientStop { position: 1.0; color: "green" }
        }
    }
}
