#ifndef ADDONFRIDGE_HH
#define ADDONFRIDGE_HH
#include <QObject>
#include <QThread>
#include "files.hh"
#include "server.hh"
#include "FridgeState.h"
#include "MyProcess.hh"
#include "NFC/pmtreader.hh"
class AddonFridge : public QObject
{
  Q_OBJECT
public:
  explicit AddonFridge(QObject *parent = nullptr);

public slots:
  void slotRecieveUid(QString field, QString value);
  void slotReadUID();
  void slotRunRFIDProcess();
  void slotKillRFIDProcess();
  void slotInitReader();
  void slotRecieveStatusUID(QString);

  void slotFakeTransmitUID();
signals:
  void signalInitReader();
  void signalGetUid();
private:
  static QTimer *timerRequest;
  static int timeRequest;
  Files files;
  Server server;
  PMTReader pmtreader;
  MyProcess myprocess;
  QThread thread1;

};
#endif // ADDONFRIDGE_HH
