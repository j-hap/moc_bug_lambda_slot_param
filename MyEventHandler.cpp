#include "MyEventHandler.h"

#include <iostream>

MyEventHandler::MyEventHandler(QObject *parent) : QObject{parent} {}

#ifdef ENABLE_BUG
void MyEventHandler::executeConditionally(
    QString const &s, std::function<std::string const &(MyStruct const &)> callback) {
  std::cout << "Event\n";
  if (s.length() > 3) {
    callback(s_);
  }
}
#else
void MyEventHandler::executeConditionally(QString const &s,
                                          std::function<std::string const &(MyStruct &)> callback) {
  if (s.length() > 3) {
    callback(s_);
  }
}
#endif
