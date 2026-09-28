#include "my_thread.h"
#include <QDebug>

my_thread::~my_thread() { qDebug() << "~my_thread()"; }
