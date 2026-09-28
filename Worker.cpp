#include "Worker.h"

#include <QDebug>
#include <QThread>
#include <QTimer>

Worker::Worker(QObject *parent) : QObject(parent) {}

void Worker::do_work(int timer_value) {
  // function to execute specific code
  qDebug() << " ---- do_work ----";
  qDebug() << "timer_value: " << timer_value;
  int t = 0;
  while (t <= (timer_value * 60)) {
    QThread::msleep(1000);
    m_time = (t * 100) / (timer_value * 60);
    emit progress();
    t += 1;
  }
  emit finished();
}

int Worker::get_time() { return m_time; }
