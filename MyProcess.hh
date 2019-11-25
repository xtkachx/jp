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
  static int runRFIDReader();
  static int killRFIDReader();
private:

};

#endif // MYPROCESS_HH
