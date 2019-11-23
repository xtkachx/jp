#ifndef FILES_HH
#define FILES_HH
#define RFID_ENABLE 0
#define OUT_1 1
#define OUT_2 2
#define CHECK_DOOR 3
#include <QMainWindow>
#include <QFile>
#include <QFileInfo>
#include <QFileSystemWatcher>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>
#include <QThread>
#include <Pathes.h>
class Files : public QMainWindow
{
  Q_OBJECT
public:
  explicit Files(QWidget *parent = nullptr);

  typedef struct structFileConnect{
    QString nameRfidEnable;
    int stateRfidEnable;
    QString nameOut1;
    int stateOut1;
    QString nameOut2;
    int stateOut2;
    QString nameCheckDoor;
    int stateCheckDoor;
  } StructFileConnect_t;

  void writeFileConnect(int, int);
  int readFileConnection(int);
  QStringList readBuyFile();
  void readFileForTextBrowser(QStringList & listText);
  void readFileConnect(StructFileConnect_t *);
  QString GetStateFridge();
  void changeModeToModeFile(QString mode, QString status);
  void changeStatusToModeFile(QString status);
  void changeArrayToModeFile(QString nameArray, QStringList list);
  QString getStatusModeFile();
  QString getModeFromModeFile();
private slots:
  void slotLock();
  void changed();

private:
  QTimer *timerLockTimeOut;
  QTimer *timerLockAfterOpen;

  QFileSystemWatcher *fsWatcher;
  int timeLockTimeOut;
  int timeLockAfterOpen;
  bool stateNFCReader;
  bool stateOpenDoor;
  bool stateProcessRfid;
  bool stateInitNFCReader;
  bool stateEnableRfid;
  bool stateStandby;
signals:
  void signalDoorSensor(bool);
  void signalTextBrowser(QStringList listText);
  void signalEnableNFCReader();
  void signalRunRFIDProcess();
  void signalKillRFIDProcess();
  void signalOpenDoor();
  void signalInitReader();
};

#endif // FILES_HH
