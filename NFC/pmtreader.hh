#ifndef PMTTHREAD_HH
#define PMTTHREAD_HH
#define APP_VERSION	"0.0.1"
#define TRUE            (1)	/* Logical true */
#define FALSE		(0)	/* Logical false */
#define usint 		unsigned int
#define byte 		unsigned char
#define BUFSIZE         2048
#define SOH		0x01
#define BLP		0x09
#define ADR		0x00
#define ACK		0x5E
#include <QMainWindow>
#include <QThread>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>
#include <QObject>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

extern "C"{
char* pmtcatstatic_transaction(char* amount, char* currency);
char* pmtcatstatic_init(char* port, char* vmserial, char* vmversion);
char* pmtcatstatic_setcomm(char* authip, int authport, char* tmsip, int tmsport);
char* pmtcatstatic_downloadparameters(void);
char* pmtcatstatic_setpaymentoptions(unsigned char openloop, unsigned char closedloop);
char* pmtcatstatic_reversal();
char* pmtcatstatic_canceltransaction();
}

class PMTReader : public QObject
{
  Q_OBJECT
public:
  explicit PMTReader(QObject *parent = nullptr);
  ~PMTReader();

  byte getOpenloop();
  void setOpenloop(int, int);
  byte getCloseloop();
  void setCloseloop(int, int);
  void setTimeSleep(usint);
  usint getTimeSleep();
  void setInitInfo(char *, char *, char *);
  void setCurrency(int);
  int getCurrency();
  void setOptions();
public slots:
  void slotInit();
  void slotGetUid();
private:
  char amount[20];
  char currency[3];
  usint timeSleep;
  byte openloop; // биты для банковских карт
  byte closeloop; // установить второй бит в 1 для чтения UID MIFARE
  char com[20];
  char SN[20];
  char software[20];
  bool checkJson(QString strJson, QString key);
  QString getValueFromJson(QString strJson, QString key);
signals:
  void signalRetInit(QString);
  void signalSendUid(QString, QString);
};

#endif // PMTTHREAD_HH
