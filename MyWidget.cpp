#include "MyWidget.h"

#include <iostream>

#include "MyStruct.h"

MyWidget::MyWidget() {
  lineEdit_ = new QLineEdit(this);
#ifdef ENABLE_BUG
  connect(lineEdit_, &QLineEdit::textChanged, this, [this](QString const &s) {
    emit propertyChanged(s, [](MyStruct const &s) -> std::string const & { return s.prop1; });
  });
#else
  connect(lineEdit_, &QLineEdit::textChanged, this, [this](QString const &s) {
    emit propertyChanged(s, [](MyStruct &s) -> std::string const & { return s.prop1; });
  });
#endif
}
