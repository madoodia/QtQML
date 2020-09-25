import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import madoodia 1.0




ColumnLayout {

  MCheckListModel {
    id: mod
    list: checkList
  }
  Frame {
    Layout.fillWidth: true

    ListView {
      id: listView
      implicitWidth: 250
      implicitHeight: 250
      clip: true
      spacing: 5

      model: mod
      
      // model: ListModel {
      //   ListElement {
      //     done: true
      //     description: "Hello Madoodia"
      //   }
      //   ListElement {
      //     done: false
      //     description: "Hello Negar"
      //   }
      // }

      delegate: RowLayout {
        width: listView.width
        
        MCheckBox {
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

  ComboBox {
    id: comboView
    Layout.fillWidth: true
    clip: true
    width: parent.width

    model: mod

    delegate: RowLayout {
      width: listView.width
      
      MCheckBox {
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
  RowLayout {
    Button {
      text: qsTr("Add New Item")
      onClicked: checkList.appendItem()
      Layout.fillWidth: true
    }
    Button {
      text: qsTr("Remove Completed Item")
      onClicked: checkList.removeCompletedItem()
      Layout.fillWidth: true
    }
  }
}
