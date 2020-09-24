#ifndef CHECKLISTMODEL_H
#define CHECKLISTMODEL_H

#include <QAbstractListModel>

class CheckListModel : public QAbstractListModel
{
  Q_OBJECT

public:
  explicit CheckListModel(QObject *parent = nullptr);

  enum Roles
  {
    DoneRole = Qt::UserRole,
    DescriptionRole
  };

  // Basic functionality:
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  // Editable:
  bool setData(const QModelIndex &index, const QVariant &value,
               int role = Qt::EditRole) override;

  Qt::ItemFlags flags(const QModelIndex &index) const override;

  QHash<int, QByteArray> roleNames() const override;

private:
};

#endif // CHECKLISTMODEL_H