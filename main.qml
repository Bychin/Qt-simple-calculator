import QtQuick 2.9
import QtQuick.Controls 2.2
import "calculator.js" as CalcEngine

ApplicationWindow {
    id: mainWindow
    visible: true
    opacity: 0.98
    width: (rb1.checked) ? 380 : 684
    height: 450
    maximumHeight: height
    //maximumWidth: (rb1.checked) ? 380 : 684
    minimumHeight: height
    //minimumWidth: (rb1.checked) ? 380 : 684
    title: (rb1.checked) ? qsTr("Calculator (simple)") : qsTr("Calculator (engineering)")
    color: "#E6E6E6"

    //onWidthChanged: controller.reload()
    //onHeightChanged: controller.reload()

    function operatorPressed(operator) {
        CalcEngine.operatorPressed(operator)
        layout.childAt(1,1).buttonPressed()
    }
    function digitPressed(digit) {
        CalcEngine.digitPressed(digit)
        layout.childAt(1,1).buttonPressed()
    }
    function isButtonDisabled(op) {
        return CalcEngine.disabled(op)
    }

    Display {
        id: display
        width: mainWindow.width
        height: 80 //?? // need to setup display's sizes

        /*MouseArea {
            property real startX: 0
            property real oldP: 0
            property bool rewind: false

            height: 50
            anchors {
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }

            onPositionChanged: {
                var reverse = startX > window.width / 2
                var mx = mapToItem(window, mouse.x,0).x
                var p = Math.abs((mx - startX) / (window.width - display.width))
                if (p < oldP)
                    rewind = reverse ? false : true
                else
                    rewind = reverse ? true : false
                controller.progress = reverse ? 1 - p : p
                oldP = p
            }
            /*onPressed: startX = mapToItem(window, mouse.x,0).x
            onReleased: {
                if (rewind)
                    controller.completeToBeginning()
                else
                    controller.completeToEnd()
            }
        }*/
    }

    Item {
        Keys.onPressed: {
            if (event.key === Qt.Key_0)
                digitPressed("0")
            else if (event.key === Qt.Key_1)
                digitPressed("1")
            else if (event.key === Qt.Key_2)
                digitPressed("2")
            else if (event.key === Qt.Key_3)
                digitPressed("3")
            else if (event.key === Qt.Key_4)
                digitPressed("4")
            else if (event.key === Qt.Key_5)
                digitPressed("5")
            else if (event.key === Qt.Key_6)
                digitPressed("6")
            else if (event.key === Qt.Key_7)
                digitPressed("7")
            else if (event.key === Qt.Key_8)
                digitPressed("8")
            else if (event.key === Qt.Key_9)
                digitPressed("9")
            else if (event.key === Qt.Key_Plus)
                operatorPressed("+")
            else if (event.key === Qt.Key_Minus)
                operatorPressed("−")
            else if (event.key === Qt.Key_Asterisk)
                operatorPressed("×")
            else if (event.key === Qt.Key_Slash)
                operatorPressed("÷")
            else if (event.key === Qt.Key_Enter || event.key === Qt.Key_Return)
                operatorPressed("=")
            else if (event.key === Qt.Key_Comma || event.key === Qt.Key_Period)
                digitPressed(".")
            else if (event.key === Qt.Key_Backspace)
                operatorPressed("backspace")
            else if (event.key === Qt.Key_Delete)
                operatorPressed("C")
        }

        id: pad
        focus: true
        width: mainWindow.width
        height: mainWindow.height - display.height
        anchors.top: display.bottom

        StackLayout {
            id: layout
            width: parent.width
            anchors.bottom: parent.bottom
            anchors.verticalCenter: parent.verticalCenter
            currentIndex: (rb1.checked) ? 0 : 1
        }
    }

    RadioButton {
        id: rb1
        checked: true
        text: qsTr("Simple")
        anchors.top: display.bottom
    }
    RadioButton {
        id: rb2
        text: qsTr("Engineering")
        anchors.top: rb1.bottom
    }

    /*AnimationController {
        id: controller
        animation: ParallelAnimation {
            id: anim
            NumberAnimation { target: display; property: "x"; duration: 400; from: -16; to: window.width - display.width; easing.type: Easing.InOutQuad }
            NumberAnimation { target: pad; property: "x"; duration: 400; from: window.width - pad.width; to: 0; easing.type: Easing.InOutQuad }
            SequentialAnimation {
                NumberAnimation { target: pad; property: "scale"; duration: 200; from: 1; to: 0.97; easing.type: Easing.InOutQuad }
                NumberAnimation { target: pad; property: "scale"; duration: 200; from: 0.97; to: 1; easing.type: Easing.InOutQuad }
            }
        }
    }*/


}
