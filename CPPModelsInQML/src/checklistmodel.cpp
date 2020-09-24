/* --------------------- */
/* (C) 2020 madoodia.com */
/* --------------------- */

#include "checklistmodel.h"

CheckListModel::CheckListModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant CheckListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  // FIXME: Implement me!
}

bool CheckListModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
  if (value != headerData(section, orientation, role))
  {
    // FIXME: Implement me!
    emit headerDataChanged(orientation, section, section);
    return true;
  }
  return false;
}

QModelIndex CheckListModel::index(int row, int column, const QModelIndex &parent) const
{
  // FIXME: Implement me!
}

QModelIndex CheckListModel::parent(const QModelIndex &index) const
{
  // FIXME: Implement me!
}

int CheckListModel::rowCount(const QModelIndex &parent) const
{
  if (!parent.isValid())
    return 0;

  // FIXME: Implement me!
}

int CheckListModel::columnCount(const QModelIndex &parent) const
{
  if (!parent.isValid())
    return 0;

  // FIXME: Implement me!
}

QVariant CheckListModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  // FIXME: Implement me!
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

  return Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> CheckListModel::roleNames() const
{
  QHash<int, QByteArray> names;
  names[DoneRole] = "done";
  names[DescriptionRole] = "description";
  return names;
}