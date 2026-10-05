#include "ui_main_window.h"

#include <QMainWindow>
#include <QWidget>

#include <memory>

namespace Ui {
class main_window;
}

class main_window : public QMainWindow {
  Q_OBJECT
public:
  explicit main_window(QWidget *parent = nullptr);
  ~main_window();

  // private slots:
  //   void start_timer(int timer_value);
  //   void add_item();
  //   void change_label();
  //   void update_progressBar();

signals:
  void cleanup();

private:
  class main_window_impl;
  std::unique_ptr<main_window_impl> impl;
  std::unique_ptr<Ui::main_window> ui;
  // void load_items();
};
