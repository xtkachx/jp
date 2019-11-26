#include "pmtreader.hh"
PMTReader::PMTReader(QObject *parent) : QObject(parent)
{
  timeSleep = 5;
  openloop = 0x00; // биты для банковских карт
  closeloop = 0x02; // установить второй бит в 1 для чтения UID MIFARE
  strcpy(amount, "000000000000");
  strcpy(currency, "978");
  strcpy(com, "/dev/ttyACM0");
  strcpy(SN, "123456789012");
  strcpy(software, "simver.01");
  pmtcatstatic_canceltransaction();
  QThread::msleep(500);
  pmtcatstatic_setpaymentoptions(openloop, closeloop);
  QThread::msleep(100);
  pmtcatstatic_downloadparameters();
  QThread::msleep(500);
  slotInit();
}
PMTReader::~PMTReader()
{
  pmtcatstatic_canceltransaction();
}
void PMTReader::setInitInfo(char * strCom, char * strSN, char * strSoftware)
{
  strcpy(com, strCom);
  strcpy(SN, strSN);
  strcpy(software, strSoftware);
}
void PMTReader::slotInit()
{
  QString strRet = "";
  QString strJson = "";
  strJson = QString(pmtcatstatic_init(com, SN, software));
  if (getValueFromJson(strJson, "Result") == "OK"){
      strRet = "OK";
    } else {
      strRet = "ERROR";
    }
  emit signalRetInit(strRet);
}
byte PMTReader::getOpenloop()
{
  return openloop;
}
byte PMTReader::getCloseloop()
{
  return closeloop;
}
void PMTReader::setTimeSleep(usint time)
{
  PMTReader::timeSleep = time;
}
usint PMTReader::getTimeSleep()
{
  return timeSleep;
}
void PMTReader::setOpenloop(int pos, int state)
{
  if (state == 1){
      openloop |= (1 << pos);
    } else {
      openloop &= ~(1 << pos);
    }
}
void PMTReader::setCloseloop(int pos, int state)
{
  if (state == 1){
      closeloop |= (1 << pos);
    } else {
      closeloop &= ~(1 << pos);
    }
}
void PMTReader::setCurrency(int numCurrency)
{
  sprintf(PMTReader::currency, "%d", numCurrency);
}
int PMTReader::getCurrency()
{
  int numCurrency = 978;
  numCurrency = atoi(currency);
  return numCurrency;
}
void PMTReader::slotGetUid()
{
  QString field = "";
  QString value = "";
  char* ret = pmtcatstatic_transaction(amount, currency);
  QString strRetReader = QString(ret);
  qDebug () << strRetReader;
  if (checkJson(strRetReader, "UID")){
      field = "UID";
      value = getValueFromJson(strRetReader, "UID");
    } else {
      field = "error";
      value = getValueFromJson(strRetReader, "Code");
    }
  emit signalSendUid(field, value);
  QThread::msleep(1000);
}

bool PMTReader::checkJson(QString strJson, QString key)
{
  bool state = false;
  QJsonDocument doc = QJsonDocument::fromJson(strJson.toUtf8());
  QJsonObject objJson = doc.object();
  QStringList list = objJson.keys();
  if (list.contains(key)){
      state = true;
    }
  return state;
}
QString PMTReader::getValueFromJson(QString strJson, QString key)
{
  QString valueRet = "";
  QJsonDocument doc = QJsonDocument::fromJson(strJson.toUtf8());
  QJsonObject objJson = doc.object();
  QStringList list = objJson.keys();
  if (list.contains(key)){
      if (objJson.value(key).isString()){
          valueRet = objJson.value(key).toString();
        }
      if (objJson.value(key).isDouble()){
          valueRet = QString::number(objJson.value(key).toInt());
        }
    }
  return valueRet;
}
