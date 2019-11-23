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
  int runRFIDReader();
  int killRFIDReader();
public slots:
signals:

public slots:
};

#endif // MYPROCESS_HH
