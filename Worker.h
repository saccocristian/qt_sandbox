#pragma once
#include <QObject>

class Worker : public QObject {
  Q_OBJECT

public:
  explicit Worker(QObject *parent = nullptr);
  int get_time();

signals:
  void finished();
  void progress();

public slots:
  void do_work(int timer_value);

private:
  int m_time;
};
