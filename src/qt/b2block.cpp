#include <QApplication>
#include <QPushButton>

#include "b2blockgui.h"
 
int main(int argc, char **argv)
{
  QApplication app (argc, argv);
  
  B2BlockGUI b2blockGUI;
  b2blockGUI.show();
  return app.exec();
}