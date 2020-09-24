import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import madoodia 1.0

ColumnLayout {
  Frame {
    Layout.fillWidth: true

    ListView {
      id: listView
      implicitWidth: 250
      implicitHeight: 250
      clip: true
      spacing: 5
      anchors.fill: parent

      model: MCheckListModel {
        list: checkList
      }
      
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