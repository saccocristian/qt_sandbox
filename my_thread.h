#include <QThread>

class my_thread : public QThread {
public:
  explicit my_thread() = default;
  ~my_thread();
};
