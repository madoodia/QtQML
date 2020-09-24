/* --------------------- */
/* (C) 2020 madoodia.com */
/* --------------------- */

#ifndef CHECKLISTMODEL_H
#define CHECKLISTMODEL_H

#include <QAbstractItemModel>

class CheckListModel : public QAbstractItemModel
{
  Q_OBJECT

public:
  explicit CheckListModel(QObject *parent = nullptr);

  enum
  {
    DoneRole = Qt::UserRole,
    DescriptionRole
  };

  // Header:
  QVariant
  headerData(int section,
             Qt::Orientation orientation,
             int role = Qt::DisplayRole) const override;

  bool setHeaderData(int section,
                     Qt::Orientation orientation,
                     const QVariant &value,
                     int role = Qt::EditRole) override;

  // Basic functionality:
  QModelIndex index(int row,
                    int column,
                    const QModelIndex &parent = QModelIndex()) const override;
  QModelIndex parent(const QModelIndex &index) const override;

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

  // Editable:
  bool setData(const QModelIndex &index,
               const QVariant &value,
               int role = Qt::EditRole) override;

  Qt::ItemFlags flags(const QModelIndex &index) const override;

  QHash<int, QByteArray> roleNames() const override;

private:
};

#endif // CHECKLISTMODEL_H
