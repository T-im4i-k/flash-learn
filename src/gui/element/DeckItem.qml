import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import gui.widget

Rectangle {
    id: root

    property int deckId
    property string description
    property string title

    color: area.containsMouse ? Qt.lighter("lightgray", 1.03) : "lightgray"
    height: 80
    width: parent.width
    z: 3

    RowLayout {
        anchors.fill: parent
        anchors.margins: 10

        ColumnLayout {
            Layout.fillWidth: true
            spacing: 5

            Text {
                font.bold: true
                text: title
            }
            Text {
                elide: Text.ElideRight
                text: description
                wrapMode: Text.Wrap
            }
            RowLayout {
                Layout.alignment: Qt.AlignBottom | Qt.AlignLeft
                spacing: 10

                Button {
                    text: "Preview"
                    z: 1
                }
                Button {
                    text: "Practice"
                    z: 1
                }
            }
        }
        ColumnLayout {
            Layout.alignment: Qt.AlignRight
            Layout.maximumWidth: 40
            Layout.minimumWidth: 40
            Layout.preferredWidth: 40

            MoreButton {
                height: 30
                width: 40
                z: 1
            }
        }
    }
    MouseArea {
        id: area

        acceptedButtons: Qt.NoButton
        anchors.fill: parent
        hoverEnabled: true
        z: 2
    }
}
