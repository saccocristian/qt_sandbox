#include "main_window.h"
#include "Worker.h"
#include "my_thread.h"
#include "utils.h"

#include <QDebug>
#include <QPointer>
#include <QSettings>

class main_window::main_window_impl {
public:
  QPointer<my_thread> thread;
  QPointer<Worker> worker;
  QSettings settings;
};

main_window::main_window(QWidget *parent) : QMainWindow(parent) {

  ui = std::make_unique<Ui::main_window>();
  ui->setupUi(this);
  impl = std::make_unique<main_window::main_window_impl>();

  // load items from registry to todolist
  load_items();

  connect(ui->todo_btn, &QPushButton::clicked, this, &main_window::add_item);

  // thread connections: start
  connect(ui->timer_slider, &QSlider::valueChanged, this,
          &main_window::change_label);
  connect(ui->timer_btn, &QPushButton::clicked, this,
          [this]() { start_timer(ui->timer_slider->value()); });

  connect(this, &main_window::cleanup, impl->thread, &my_thread::quit);
  // thread connections: end

  this->show();
}

main_window::~main_window() {
  // Distruttore termina e lancia segnale per terminare ogni processo
  if (impl->thread && impl->thread->isRunning()) {
    // non lancio il cleanup se non sta già runnando il thread
    emit cleanup();
  }
}

void main_window::start_timer(int timer_value) {

  if (impl->thread && impl->thread->isRunning()) {
    return;
  }
  ui->timer_btn->setEnabled(false);
  impl->thread = new my_thread();
  impl->worker = new Worker();
  connect(impl->thread, &my_thread::started, impl->worker,
          [this, timer_value]() { impl->worker->do_work(timer_value); });
  connect(impl->worker, &Worker::finished, impl->thread, &my_thread::quit);
  connect(impl->worker, &Worker::finished, impl->worker, &Worker::deleteLater);
  connect(impl->thread, &my_thread::finished, impl->thread,
          &my_thread::deleteLater);
  connect(impl->worker, &Worker::progress, this,
          &main_window::update_progressBar);
  impl->worker->moveToThread(impl->thread);
  impl->thread->start();
}

void main_window::change_label() {
  ui->timer_label->setText(QString::number(ui->timer_slider->value()));
}

void main_window::update_progressBar() {
  ui->timer_progressBar->setValue(impl->worker->get_time());
}

void main_window::add_item() {
  impl->settings.setValue(ui->todo_lineEdit->text(), ui->todo_lineEdit->text());
  ui->todo_listWidget->addItem(ui->todo_lineEdit->text());
  ui->todo_lineEdit->setText("");
}

void main_window::load_items() {
  ui->todo_listWidget->clear();
  QStringList list = impl->settings.allKeys();
  for (auto str : list) {
    ui->todo_listWidget->addItem(str);
  }
}
