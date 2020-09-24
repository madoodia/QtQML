/* --------------------- */
/* (C) 2020 madoodia.com */
/* --------------------- */

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "./qml" as UI

Window {
  width: 400
  height: 600
  visible: true
  title: qsTr("Hello World")

  UI.MCheckList {
    anchors.centerIn: parent
  }
}
