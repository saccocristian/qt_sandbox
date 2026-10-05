#include "main_window.h"

#include <QSettings>

class main_window::main_window_impl {
public:
  QSettings settings;
};

main_window::main_window(QWidget *parent) : QMainWindow(parent) {

  ui = std::make_unique<Ui::main_window>();
  ui->setupUi(this);
  impl = std::make_unique<main_window::main_window_impl>();

  this->show();
}

main_window::~main_window() {}
