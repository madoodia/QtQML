/* --------------------- */
/* (C) 2020 madoodia.com */
/* --------------------- */

#include "checklistmodel.h"

CheckListModel::CheckListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int CheckListModel::rowCount(const QModelIndex &parent) const
{
  if (!parent.isValid())
    return 0;

  return 100;
}

QVariant CheckListModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  switch (role)
  {
  case DoneRole:
    return QVariant(false);
  case DescriptionRole:
    return QVariant(QStringLiteral("Test Description"));
  }

  return QVariant();
}

bool CheckListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
  if (data(index, role) != value)
  {
    // FIXME: Implement me!
    emit dataChanged(index, index, QVector<int>() << role);
    return true;
  }

  return false;
}

Qt::ItemFlags CheckListModel::flags(const QModelIndex &index) const
{
  if (!index.isValid())
    return Qt::NoItemFlags;

  return Qt::ItemIsEditable;
}

QHash<int, QByteArray> CheckListModel::roleNames() const
{
  QHash<int, QByteArray> roles;
  roles[DoneRole] = "done";
  roles[DescriptionRole] = "description";
  return roles;
}