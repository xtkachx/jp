#ifndef FILES_HH
#define FILES_HH
#define RFID_ENABLE 0
#define OUT_1 1
#define OUT_2 2
#define CHECK_DOOR 3
#include <QObject>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileSystemWatcher>
#include <QTime>
#include <QDate>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>
#include <QThread>
#include <Pathes.h>
#include <FridgeState.h>
typedef struct structProduct{
  QString marker;
  QString EPC;
} StructProduct_t;
class Files : public QObject
{
  Q_OBJECT
public:
  explicit Files(QObject *parent = nullptr);

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
  QVector <StructProduct_t> productVect;
  void addTagFromJson(StructProduct_t &product, QString field, QString value);
  static void writeFileConnect(int, int);
  static int readFileConnect(int);
  static QStringList readBuyFile();
  static void readFileForTextBrowser(QStringList & listText);
  static void readFileConnectToStruct(StructFileConnect_t *);
  static QString GetStateFridge();
  static void changeModeToModeFile(QString mode, QString status);
  static void changeStatusToModeFile(QString status);
  static void changeArrayToModeFile(QString nameArray, QStringList list);
  static QString getStatusModeFile();
  static QString getModeFromModeFile();

private slots:
  void slotLock();
  void changed();
  void changedUpdateFolder(const QString & dirName);

private:
  QFileSystemWatcher *fsWatcher;
  static QTimer *timerLockTimeOut;
  static QTimer *timerLockAfterOpen;
  static int timeLockTimeOut;
  static int timeLockAfterOpen;


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
