#ifndef MYPROCESS_HH
#define MYPROCESS_HH

#include <QObject>
#include <QThread>
#include <QProcess>
#include <QDir>
#include <QDebug>

class MyProcess : public QObject
{
  Q_OBJECT
public:
  explicit MyProcess(QObject *parent = nullptr);
  static void runRFIDReader();
  static void killRFIDReader();
  static QProcess::ProcessState checkProcess();
private:
  static QProcess *process;

};

#endif // MYPROCESS_HH
