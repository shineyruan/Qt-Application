import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    color: "#ffffff"
    title: qsTr("Hello World")


    ColumnLayout {
        x: 109
        y: 158

        Text {
            id: showText
            color: "#122fba"
            text: qsTr("Waiting for click...")
            Layout.preferredHeight: 117
            Layout.preferredWidth: 423
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 32
        }

        Button {
            id: echoButton
            text: "echo \"Hello World\""
            Layout.preferredHeight: 40
            Layout.preferredWidth: 423

            onClicked: {
                showText.text = "Hello World!"
            }

        }

        Button {
            id: clearButton
            text: "clear"
            Layout.fillWidth: true

            onClicked: {
                showText.text = "Waiting for click..."
            }
        }
    }
}
