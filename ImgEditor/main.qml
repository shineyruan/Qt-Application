import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

import com.images 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Image Loader")

    ImgLoader {
        id: loader
    }

    FileDialog {
        id: fileDialog
        title: "Select an image..."
        nameFilters: ["Image files (*.png *.jpg)", "All files (*)"]
        selectedNameFilter: "Image files (*.png *.jpg)"
        sidebarVisible: true
        onAccepted: {
            imageURL = fileUrl
            console.log("Chosen image: " + imageURL)
            loader.loadImage(imageURL)
        }
    }

    ColumnLayout {
        id: columnLayout
        x: 0
        y: 0
        anchors.fill: parent

        MenuBar {
            id: menuBar
            Layout.fillWidth: true
            Menu {
                visible: false
                title: qsTr("File")
                Action {
                    text: qsTr("Open...")
                    onTriggered: {
                        fileDialog.open()
                    }
                }
                Action { text: qsTr("Save...") }
                MenuSeparator { }
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
                    opacity: enabled ? 1 : 0.3
                    color: menuBarItem.highlighted ? "#d7d7d7" : "transparent"
                }
            }

            background: Rectangle {
                color: "#eeeeee"
            }
        }


        Image {
            id: img
            asynchronous: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            source: imageURL
            fillMode: Image.PreserveAspectCrop

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    loader.setMousePos(mouseXposPixel, mouseYPosPixel)
                }
                onPositionChanged: {
                    mouseXPos = mouseX
                    mouseYPos = mouseY
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true

            Label {
                text: qsTr("Mouse position: " + mouseXposPixel + ", " + mouseYPosPixel)
            }

            Label {
                text: qsTr("Image size: " + img.sourceSize.width + "x" + img.sourceSize.height)
            }
        }
    }

    property var imageURL: ""
    property var mouseXPos: 0.0
    property var mouseYPos: 0.0
    property var mouseXposPixel: Math.round(mouseXPos * img.sourceSize.width / img.paintedWidth)
    property var mouseYPosPixel: Math.round(mouseYPos * img.sourceSize.height / img.paintedHeight)
}


