import QtQuick 2.12
import TestProject1 1.0
import QtQuick.Studio.Components 1.0
import QtQuick.Layouts 1.11
import QtQuick.Timeline 1.0
import QtQuick.Controls 2.15

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height
    color: "#191919"

    Frame {
        id: frame
        width: 310
        height: 310
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ArcItem {
        id: arc
        width: 300
        height: 300
        visible: true
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        antialiasing: true
        strokeColor: "#f9f9f9"
        capStyle: 32
        end: -135
        begin: -135
        strokeWidth: 25
        fillColor: "#00000000"
    }

    Timeline {
        id: timeline
        currentFrame: dial.value
        endFrame: 1000
        startFrame: 0
        enabled: true

        KeyframeGroup {
            target: arc
            property: "begin"
            Keyframe {
                value: -135
                frame: 1000
            }
        }

        KeyframeGroup {
            target: arc
            property: "end"
            Keyframe {
                value: 135
                frame: 1000
            }

            Keyframe {
                value: -135
                frame: 0
            }
        }
    }

    Dial {
        id: dial
        width: 300
        height: 300
        opacity: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        stepSize: 1
        to: 1000
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.6600000262260437}D{i:3}
}
##^##*/

