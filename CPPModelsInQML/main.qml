import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Text {
      id: hello
      anchors.centerIn: parent
      text: qsTr("hello world")
  }
}
