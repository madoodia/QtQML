/* --------------------- */
/* (C) 2020 madoodia.com */
/* --------------------- */

#include "checklist.h"

CheckList::CheckList(QObject *parent)
    : QObject(parent)
{
  m_items.append({true, QStringLiteral("Hello Madoodia")});
  m_items.append({false, QStringLiteral("Hello Negar")});
}

QVector<CheckItem> CheckList::items() const
{
  return m_items;
}

bool CheckList::setItemAt(int index, const CheckItem &item)
{
  if (index < 0 || index >= m_items.size())
    return false;

  const CheckItem &oldItem = m_items.at(index);

  if (item.done == oldItem.done && item.description == oldItem.description)
    return false;

  m_items[index] = item;

  return true;
}

void CheckList::appendItem()
{
  emit preItemAppended();

  CheckItem item;
  item.done = false;
  m_items.append(item);

  emit postItemAppended();
}

void CheckList::removeCompletedItem()
{
  for (int i = 0; i < m_items.size();)
  {
    if (m_items.at(i).done)
    {
      emit preItemRemoved(i);
      m_items.removeAt(i);
      emit postItemRemoved();
    }
    else
    {
      ++i;
    }
  }
}