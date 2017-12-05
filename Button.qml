import QtQuick 2.5

Rectangle {
    id: button
    property alias text: textItem.text
    //property color color: "white"

    property bool operator: false
    property bool dimmable: false
    property bool dimmed: false

    width: 76
    height: 74
    color: (operator) ? "#E6E6E6" /*light grey*/ : "white"

    border.width: 2
    border.color: (operator) ? "#E6E6E6" /*light grey*/ : "white"

    Text {
        id: textItem
        font.pixelSize: 35
        //wrapMode: Text.WordWrap
        //lineHeight: 0.75
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "black"
        font.weight: (operator) ? 25 : 63
        Behavior on color { ColorAnimation { duration: 120; easing.type: Easing.OutElastic} }
        states: [
            State {
                name: "pressed-number"
                when: mouse.pressed && !operator && !dimmed
                PropertyChanges {
                    explicit: true
                    target: button
                    color: "#BDBDBD"
                    border.color: "#D8D8D8"
                }
            },
            State {
                name: "hovered-number"
                when: mouse.containsMouse && !operator && !dimmed
                PropertyChanges {
                    explicit: true
                    target: button
                    color: "#D8D8D8"
                    border.color: "#F2F2F2"
                }
            },
            State {
                name: "pressed-op"
                when: mouse.pressed && operator && !dimmed
                PropertyChanges {
                    explicit: true
                    target: button
                    color: "#81DAF5"
                    border.color: "#A9E2F3"
                }
            },
            State {
                name: "hovered-op"
                when: mouse.containsMouse && operator && !dimmed
                PropertyChanges {
                    explicit: true
                    target: button
                    color: "#58D3F7"
                    border.color: "#81DAF5"
                }
            }
        ]
    }

    MouseArea {
        id: mouse
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            if (operator) {
                mainWindow.operatorPressed(parent.text)
                button.color
            }
            else
                mainWindow.digitPressed(parent.text)
        }
    }

    function updateDimmed() {
        dimmed = mainWindow.isButtonDisabled(button.text)
    }

    Component.onCompleted: {
        layout.childAt(1,1).buttonPressed.connect(updateDimmed)
        updateDimmed()
    }
}
