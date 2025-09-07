import QtQuick
import QtQuick.Controls

Rectangle {
    id: root

    property color baseColor: "#847E89"

    signal clicked

    color: if (area.pressed)
        return Qt.darker(baseColor, 1.1)
    else if (area.containsMouse)
        return Qt.lighter(baseColor, 1.05)
    else
        return baseColor
    radius: 30

    Text {
        anchors.centerIn: parent
        color: "#C2D3CD"
        text: "+"

        font {
            bold: true
            pixelSize: 35
        }
    }
    MouseArea {
        id: area

        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            root.clicked();
        }
    }
}
