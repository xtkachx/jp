#include "MyProcess.hh"

MyProcess::MyProcess(QObject *parent) : QObject(parent)
{

}
int MyProcess::runRFIDReader()
{
  QProcess *process = new QProcess(this);
  QString file = QDir::homePath() + "/rfidReader/rfidReader";
  process->start(file);
  process->waitForStarted();
  qDebug() << "Process start!";
  return 0;
}
int MyProcess::killRFIDReader()
{
  int ret = system("pkill rfidReader");
  qDebug() << "Process close!";
  return ret;
}
