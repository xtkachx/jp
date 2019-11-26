#include "MyProcess.hh"
QProcess *MyProcess::process = new QProcess();
MyProcess::MyProcess(QObject *parent) : QObject(parent)
{

}
void MyProcess::runRFIDReader()
{
  QString file = QFileInfo("../").absolutePath() + "/rfidReader/rfidReader";
  qDebug () << "Путь: " << file << "!";
  process->start(file);
  process->waitForStarted();
  qDebug() << "Process start!";
}
void MyProcess::killRFIDReader()
{
  system("pkill rfidReader");
  qDebug() << "Process close!";
}
QProcess::ProcessState MyProcess::checkProcess()
{
  return process->state();
}
