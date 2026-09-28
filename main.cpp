#include "main_window.h"
#include "utils.h"

#include <QApplication>
#include <QTextEdit>

int create_csv();

int main(int argv, char **args) {

  QApplication app(argv, args);
  QCoreApplication::setOrganizationName("CS");
  QCoreApplication::setApplicationName(utils::settings_group);

  main_window main_window;

  return app.exec();
  int ok = create_csv();
  return 0;
}
