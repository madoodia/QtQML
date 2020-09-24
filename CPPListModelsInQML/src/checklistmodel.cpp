/* --------------------- */
/* (C) 2020 madoodia.com */
/* --------------------- */

#include "checklistmodel.h"
#include "checklist.h"

CheckListModel::CheckListModel(QObject *parent)
    : QAbstractListModel(parent),
      m_list(nullptr)
{
}

int CheckListModel::rowCount(const QModelIndex &parent) const
{
  // For list models only the root node (an invalid parent) should return the list's size. For all
  // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
  if (parent.isValid() || !m_list)
    return 0;

  return m_list->items().size();
}

QVariant CheckListModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid() || !m_list)
    return QVariant();

  const CheckItem item = m_list->items().at(index.row());

  switch (role)
  {
  case DoneRole:
    return QVariant(item.done);
  case DescriptionRole:
    return QVariant(item.description);
  }

  return QVariant();
}

bool CheckListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
  if (!m_list)
    return false;

  CheckItem item = m_list->items().at(index.row()); // should not be const

  switch (role)
  {
  case DoneRole:
    item.done = value.toBool();
    break;
  case DescriptionRole:
    item.description = value.toString();
    break;
  }

  if (m_list->setItemAt(index.row(), item))
  {
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

CheckList *CheckListModel::list() const
{
  return m_list;
}

void CheckListModel::setList(CheckList *list)
{
  beginResetModel();

  if (m_list)
    m_list->disconnect(this);

  m_list = list;

  if (m_list)
  {
    connect(m_list, &CheckList::preItemAppended, this, [=]() {
      const int index = m_list->items().size();
      beginInsertRows(QModelIndex(), index, index);
    });
    connect(m_list, &CheckList::postItemAppended, this, [=]() {
      endInsertRows();
    });

    connect(m_list, &CheckList::preItemRemoved, this, [=](int index) {
      beginRemoveRows(QModelIndex(), index, index);
    });
    connect(m_list, &CheckList::postItemRemoved, this, [=]() {
      endRemoveRows();
    });
  }

  endResetModel();
}
