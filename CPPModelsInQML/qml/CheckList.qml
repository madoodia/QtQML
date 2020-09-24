import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Frame {
  id: mainFrame
  ListView {
    id: myList
    implicitWidth: 250
    implicitHeight: 250
    clip: true

    model: ListModel {
      ListElement {
        done: true
        description: "Hello Madoodia"
      }
      ListElement {
        done: false
        description: "Hello Negar"
      }
    }

    delegate: RowLayout {
      width: parent.width
      CheckBox {
        checked: model.done
        onClicked: model.done = checked
      }

      TextField {
        Layout.fillWidth: true
        text: model.description
        onEditingFinished: model.description = text
      }
    }
  }
}
