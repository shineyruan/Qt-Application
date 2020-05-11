import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import io.qt.examples.backend 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BackEnd {
        id:backend
    }

    ColumnLayout {
        x: 60
        y: 179


        TextField {
            id: inputText
            x: 0
            y: 0
            text: backend.userName
            Layout.preferredHeight: 48
            Layout.preferredWidth: 520
            font.pointSize: 16
            horizontalAlignment: Text.AlignLeft
            placeholderText: qsTr("User name")
            font.weight: Font.Normal
        }

        Text {
            id: showText
            x: 0
            y: 56
            text: backend.userName
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 32
        }

        Button {
            id: setCurrButton
            text: qsTr("Set User Name")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            onClicked: {
                backend.userName = inputText.text
                showText.text = backend.userName
            }
        }

        Button {
            id: showPrevButton
            text: qsTr("Show Previous User Name")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            onClicked: showText.text = backend.prevUserName
        }

    }
}
