#ifndef MYEVENTHANDLER_H
#define MYEVENTHANDLER_H

#include <QObject>
#include <string>

#include "MyStruct.h"

class MyEventHandler : public QObject {
  Q_OBJECT
 public:
  explicit MyEventHandler(QObject *parent = nullptr);

 public slots:
#ifdef ENABLE_BUG
  void executeConditionally(QString const &s,
                            std::function<std::string const &(MyStruct const &)> callback);
#else
  void executeConditionally(QString const &s,
                            std::function<std::string const &(MyStruct &)> callback);
#endif

 private:
  MyStruct s_;
};

#endif  // MYEVENTHANDLER_H
