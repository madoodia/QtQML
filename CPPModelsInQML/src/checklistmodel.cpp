#include "checklistmodel.h"

CheckListModel::CheckListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int CheckListModel::rowCount(const QModelIndex &parent) const
{
  // For list models only the root node (an invalid parent) should return the list's size. For all
  // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
  if (parent.isValid())
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

  return Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> CheckListModel::roleNames() const
{
  QHash<int, QByteArray> roles;
  roles[DoneRole] = "done";
  roles[DescriptionRole] = "description";
  return roles;
}
