import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Image Loader")

    ColumnLayout {
        x: 0
        y: 0
        anchors.fill: parent

        MenuBar {
            Menu {
                visible: false
                title: qsTr("File")
                Action { text: qsTr("Open...") }
                Action { text: qsTr("Save...") }
                MenuSeparator {}
                Action {
                    text: qsTr("Exit")
                    onTriggered: Qt.quit()
                }

                delegate: MenuItem {
                    id: menuItem_File
                    implicitHeight: 30
                }
            }
            Menu {
                title: qsTr("Help")
                Action { text: qsTr("Help...") }

                delegate: MenuItem {
                    id: menuItem_Help
                    implicitHeight: 30
                }
            }

            delegate: MenuBarItem {
                id: menuBarItem

                contentItem: Text {
                    id: contentItem
                    text: menuBarItem.text
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                background: Rectangle {
                    implicitHeight: 15
                    implicitWidth: 40
                    opacity: enabled ? 1: 0.3
                    color: menuBarItem.highlighted ? "#d7d7d7" : "transparent"
                }
            }

            background: Rectangle {
                color: "#eeeeee"
            }
        }

        Image {
            id: image
            asynchronous: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            source: "qrc:/images/sample.png"
            fillMode: Image.PreserveAspectFit
        }
    }
}


