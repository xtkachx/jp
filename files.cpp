#include "files.hh"
#include "FridgeState.h"
#define RFID_ENABLE 0
#define OUT_1 1
#define OUT_2 2
#define CHECK_DOOR 3
Files::Files(QWidget *parent) : QMainWindow(parent)
{
  timeLockTimeOut = 10000;
  timeLockAfterOpen = 1000;
  stateNFCReader = false;
  stateOpenDoor = false;
  stateProcessRfid = false;
  stateInitNFCReader = false;
  stateEnableRfid = false;
  stateStandby = false;
  timerLockTimeOut = new QTimer();
  timerLockAfterOpen = new QTimer();
  connect(timerLockTimeOut, &QTimer::timeout, this, &Files::slotLock);
  connect(timerLockAfterOpen, &QTimer::timeout, this, &Files::slotLock);

  fsWatcher = new QFileSystemWatcher(this);
  fsWatcher->addPath(NameFiles::pathFileConnect);
  fsWatcher->addPath(NameFiles::pathFileProduct);
  fsWatcher->addPath(NameFiles::pathFileBuyProduct);
  fsWatcher->addPath(NameFiles::pathFileModes);
}
void Files::changed(){
  QFileInfo checkFileConnect(NameFiles::pathFileConnect);//sadfsadf
  QFileInfo checkFileProduct(NameFiles::pathFileProduct);
  QFileInfo checkFileBuyProduct(NameFiles::pathFileBuyProduct);
  QFileInfo checkFileModes(NameFiles::pathFileModes);
  while(!checkFileConnect.exists() | !checkFileProduct.exists() | !checkFileBuyProduct.exists()  | !checkFileModes.exists())
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

  if ((getModeFromModeFile() == Fridge::modeInitialization) && (getStatusModeFile() == Fridge::statusStandby) ){
      if (stateStandby == false){
          stateStandby = true;
          writeFileConnect(RFID_ENABLE, 0);
        }
      stateNFCReader = false;
      stateOpenDoor = false;
      stateProcessRfid = false;
      if (stateInitNFCReader == false){
          stateInitNFCReader = true;
          emit signalInitReader();
        }
      slotLock();
      if (stateProcessRfid == true){
          emit signalKillRFIDProcess();
          stateProcessRfid = false;
        }
    } else {
      stateStandby = false;
      if (stateProcessRfid == false){
          emit signalRunRFIDProcess();
          stateProcessRfid = true;
          QThread::msleep(200);
          writeFileConnect(RFID_ENABLE, 1);
        }
    }
  if (stateEnableRfid == false){
      if ((getModeFromModeFile() == Fridge::modeSale) &&
          (getModeFromModeFile() == Fridge::modeFilling) &&
          (getModeFromModeFile() == Fridge::modeService)){
          stateEnableRfid = true;
          writeFileConnect(RFID_ENABLE, 1);
        }
    }
  if (getStatusModeFile() == Fridge::statusReopenDoor){
      stateOpenDoor = false;
      changeStatusToModeFile(Fridge::statusBuyerCanOpenTheDoor);
    }
  if (getStatusModeFile() == Fridge::statusBuyerCanOpenTheDoor){
      if (stateOpenDoor == false){
          writeFileConnect(OUT_1, 1);
          stateOpenDoor = true;
        }
      if (readFileConnection(CHECK_DOOR) > 0){
          changeStatusToModeFile(Fridge::statusDoorIsOpen);
        }
    }
  if (getStatusModeFile() == Fridge::statusButtonGoToShopPressed){
      if (stateNFCReader == false){
          emit signalEnableNFCReader();
          stateNFCReader = true;
        }
    }
  if (getStatusModeFile() == Fridge::statusDoorIsOpen){
      timerLockAfterOpen->start(timeLockAfterOpen);
      stateInitNFCReader = false;
      if (readFileConnection(CHECK_DOOR) == 0){
          changeStatusToModeFile(Fridge::statusDoorIsClose);
        }
    }
}
void Files::slotLock(){ //слот для закрытия замка по таймеру
  timerLockTimeOut->stop();
  timerLockAfterOpen->stop();
  writeFileConnect(1,0);
}
void Files::writeFileConnect(int position, int state){
  QFile fileConnect(NameFiles::pathFileConnect);
  QString strBuf="";
  QStringList listString;
  if (fileConnect.open(QFile::ReadOnly)) {
      if (fileConnect.exists())
        {
          while(!fileConnect.atEnd()) {
              listString.append(fileConnect.readLine());
            }
          fileConnect.close();
          strBuf = listString.at(position);
          QRegExp rx("(\\ |\\,|\\.|\\:|\\t|\\n)");
          QStringList listBuf = strBuf.split(rx,  QString :: SkipEmptyParts);
          listBuf[1] = QString::number(state);
          listString[position].clear();
          listString[position].append(listBuf.at(0) + " " + listBuf.at(1) + "\n");
        }
    }
  if (fileConnect.open(QFile::WriteOnly)) {
      if (fileConnect.exists()) {
          for (QString str: listString){
              fileConnect.write(str.toUtf8());
            }
          fileConnect.close();
        }
    }
  if ((position == 1) && (state == 1)){
      timerLockTimeOut->start(timeLockTimeOut);
    }
  if ((position == 1) && (state == 0)){
      timerLockTimeOut->stop();
    }
}
int Files::readFileConnection(int position)
{
  QFile fileConnect(NameFiles::pathFileConnect);
  QString strConnect="";
  QStringList listString;
  if (fileConnect.open(QFile::ReadOnly)) {
      if (fileConnect.exists()){
          while(!fileConnect.atEnd()){
              //              strConnect += fileConnect.readLine();
              listString.append(fileConnect.readLine());
            }
          fileConnect.close();
          QRegExp rx("(\\ |\\,|\\.|\\:|\\t|\\n)");
          QStringList bufList = listString[position].split(rx, QString :: SkipEmptyParts);
          return bufList.at(1).toInt();
        }
    }
  return 0;
}

QStringList Files::readBuyFile()
{
  QFile filebuyProduct(NameFiles::pathFileProduct);
  QStringList listBuyProducts;
  QString bufStr="";
  QRegExp rx("(\\ |\\,|\\.|\\:|\\t|\\n)");
  if (filebuyProduct.open(QFile::ReadOnly)) {
      if (filebuyProduct.exists()){
          while(!filebuyProduct.atEnd()){
              QStringList bufList;
              bufStr = filebuyProduct.readLine();
              bufList = bufStr.split(rx, QString :: SkipEmptyParts);
              listBuyProducts.push_back(bufList.at(1));
            }
          filebuyProduct.close();
        }
    }
  return listBuyProducts;
}
void Files::readFileConnect(StructFileConnect_t *structConnect)
{
  QStringList listTextConnect;
  QFile fileConnect(NameFiles::pathFileConnect);
  if (fileConnect.open(QFile::ReadOnly)) {
      if (fileConnect.exists()){
          QString strConnect="";
          while(!fileConnect.atEnd()){
              strConnect += fileConnect.readLine();
            }
          QRegExp rx("(\\ |\\,|\\.|\\:|\\t|\\n)");
          listTextConnect = strConnect.split(rx,  QString :: SkipEmptyParts);
          fileConnect.close();
          if (listTextConnect.size() == 8){
              structConnect->nameRfidEnable = listTextConnect[0];
              structConnect->stateRfidEnable = listTextConnect[1].toInt();
              structConnect->nameOut1 = listTextConnect[2];
              structConnect->stateOut1 = listTextConnect[3].toInt();
              structConnect->nameOut2 = listTextConnect[4];
              structConnect->stateOut2 = listTextConnect[5].toInt();
              structConnect->nameCheckDoor = listTextConnect[6];
              structConnect->stateCheckDoor = listTextConnect[7].toInt();
            }
        }
    }
}
QString Files::GetStateFridge()
{
  QString statusError = "";
  structFileConnect aStructFileConnect = {"", 0, "", 0, "", 0, "", 0};
  readFileConnect(&aStructFileConnect);
  if ((aStructFileConnect.stateRfidEnable == 0) &&
      (aStructFileConnect.stateOut1 == 0) &&
      (aStructFileConnect.stateCheckDoor == 0))
    {
      statusError = "waiting";
    }
  if ((aStructFileConnect.stateRfidEnable == 0) &&
      (aStructFileConnect.stateCheckDoor == 1))
    {
      statusError = "breaking_the_door";
    }
  return statusError;
}
void Files::changeModeToModeFile(QString mode, QString status)
{
  QFile fileModes(NameFiles::pathFileModes);
  if (!fileModes.open(QIODevice::ReadOnly)){
      return;
    }
  QJsonObject objMain/* = QJsonDocument::fromJson(fileModes.readAll()).object()*/;
  fileModes.close();

  objMain.insert("mode", mode);
  objMain.insert("status", status);
  //  qDebug() << "\nJSON:\n"
  //           << qPrintable(QJsonDocument(objMain).toJson(QJsonDocument::Indented));

  fileModes.open(QFile::WriteOnly);
  fileModes.write(QJsonDocument(objMain).toJson());
  fileModes.close();
}
void Files::changeStatusToModeFile(QString status)
{
  QFile fileModes(NameFiles::pathFileModes);
  if (!fileModes.open(QIODevice::ReadOnly)){
      return;
    }
  QJsonObject objMain = QJsonDocument::fromJson(fileModes.readAll()).object();
  fileModes.close();
  objMain.insert("status", status);
  fileModes.open(QFile::WriteOnly);
  fileModes.write(QJsonDocument(objMain).toJson());
  fileModes.close();
}
void Files::changeArrayToModeFile(QString name, QStringList list)
{
  QFile fileModes(NameFiles::pathFileModes);
  if (!fileModes.open(QIODevice::ReadOnly)){
      return;
    }
  QJsonObject objMain = QJsonDocument::fromJson(fileModes.readAll()).object();
  fileModes.close();
  QJsonArray array = QJsonArray::fromStringList(list);
  objMain.insert(name, array);
  fileModes.open(QFile::WriteOnly);
  fileModes.write(QJsonDocument(objMain).toJson());
  fileModes.close();
}
QString Files::getStatusModeFile(){
  QFile fileModes(NameFiles::pathFileModes);
  if (!fileModes.open(QIODevice::ReadOnly)){
      return "";
    }
  QJsonObject objMain = QJsonDocument::fromJson(fileModes.readAll()).object();
  fileModes.close();
  QString status;
  status = objMain.value("status").toString();
  return status;
}
QString Files::getModeFromModeFile()
{
  QFile fileModes(NameFiles::pathFileModes);
  if (!fileModes.open(QIODevice::ReadOnly)){
      return "";
    }
  QJsonObject objMain = QJsonDocument::fromJson(fileModes.readAll()).object();
  fileModes.close();
  QString mode;
  mode = objMain.value("mode").toString();
  return mode;
}
