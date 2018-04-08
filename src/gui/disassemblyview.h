#pragma once
#include <QTreeView>
#include <QHeaderView>
#include <QAbstractItemModel>
#include "parser/SCXTypes.h"

class DisassemblyView : public QTreeView {
  Q_OBJECT
 public:
  explicit DisassemblyView(QWidget *parent = 0);
  ~DisassemblyView(){};

  void setModel(QAbstractItemModel *model) override;

  void goToAddress(SCXOffset address);

 public slots:
  void onCommentKeyPress();

 private slots:
  void onModelReset();
  void adjustHeader(int oldCount, int newCount);

  void onProjectOpened();
  void onProjectClosed();
  void onFileSwitched(int previousId);
};