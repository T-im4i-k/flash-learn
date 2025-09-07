import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import gui.widget

Rectangle {
    id: root
    width: parent.width
    height: 80
    color: area.containsMouse ? Qt.lighter("lightgray", 1.03) : "lightgray"

    z: 3

    property int deckId
    property string title
    property string description

    RowLayout {
        anchors.fill: parent
        anchors.margins: 10

        ColumnLayout {
            Layout.fillWidth: true
            spacing: 5

            Text {
                text: title
                font.bold: true
            }

            Text {
                text: description
                wrapMode: Text.Wrap
                elide: Text.ElideRight
            }

            RowLayout {
                Layout.alignment: Qt.AlignBottom | Qt.AlignLeft
                spacing: 10

                Button { text: "Preview"; z: 1 }
                Button { text: "Practice"; z: 1 }
            }
        }

        ColumnLayout {
            Layout.preferredWidth: 40
            Layout.maximumWidth: 40
            Layout.minimumWidth: 40
            Layout.alignment: Qt.AlignRight

            MoreButton {
                width: 40
                height: 30
                z: 1
            }
        }
    }

    MouseArea {
        id: area

        z: 2

        acceptedButtons: Qt.NoButton
        anchors.fill: parent
        hoverEnabled: true
    }
}
