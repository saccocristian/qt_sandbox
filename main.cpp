#include "main_window.h"
#include "utils.h"

#include <QApplication>
#include <QTextEdit>

int main(int argv, char **args) {

  QApplication app(argv, args);
  QCoreApplication::setOrganizationName(utils::organization_name);
  QCoreApplication::setApplicationName(utils::application_name);

  main_window main_window;

  return app.exec();
}
