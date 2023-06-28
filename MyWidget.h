#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QLineEdit>
#include <QString>
#include <QWidget>

#include "MyStruct.h"

class MyWidget : public QWidget {
  Q_OBJECT
 public:
  MyWidget();
 signals:
#ifdef ENABLE_BUG
  void propertyChanged(QString const& newValue, std::function<std::string const&(MyStruct const&)>);
#else
  void propertyChanged(QString const& newValue, std::function<std::string const&(MyStruct &)>);
#endif

 private:
  QLineEdit* lineEdit_;
};

#endif  // MYWIDGET_H
