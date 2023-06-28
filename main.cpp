#include <QApplication>

#include "MyEventHandler.h"
#include "MyWidget.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MyWidget w;
  MyEventHandler h;
  QObject::connect(&w, &MyWidget::propertyChanged, &h, &MyEventHandler::executeConditionally);
  w.show();
  return a.exec();
}
