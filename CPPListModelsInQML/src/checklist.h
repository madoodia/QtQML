/* --------------------- */
/* (C) 2020 madoodia.com */
/* --------------------- */

#ifndef CHECKLIST_H
#define CHECKLIST_H

#include <QObject>
#include <QVector>

struct CheckItem
{
  bool done;
  QString description;
};

class CheckList : public QObject
{
  Q_OBJECT

public:
  explicit CheckList(QObject *parent = nullptr);

  QVector<CheckItem> items() const;

  bool setItemAt(int index, const CheckItem &item);

signals:
  void
  preItemAppended();
  void postItemAppended();

  void preItemRemoved(int index);
  void postItemRemoved();

public slots:
  void appendItem();
  void removeCompletedItem();

private:
  QVector<CheckItem> m_items;
};

#endif // CHECKLIST_H
