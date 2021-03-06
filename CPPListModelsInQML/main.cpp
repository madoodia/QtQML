/* --------------------- */
/* (C) 2020 madoodia.com */
/* --------------------- */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "checklist.h"
#include "checklistmodel.h"

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  qmlRegisterType<CheckListModel>("madoodia", 1, 0, "MCheckListModel");
  qmlRegisterUncreatableType<CheckList>("madoodia", 1, 0, "CheckList",
                                        QStringLiteral("CheckList should not be used as a QML Type"));

  CheckList checkList;

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty(QStringLiteral("checkList"), &checkList);
  QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
