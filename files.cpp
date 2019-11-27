#include "files.hh"
#include "FridgeState.h"
#define RFID_ENABLE 0
#define OUT_1 1
#define OUT_2 2
#define CHECK_DOOR 3
int Files::timeLockTimeOut = 10000;
int Files::timeLockAfterOpen = 1000;
QTimer *Files::timerLockTimeOut = new QTimer;
QTimer *Files::timerLockAfterOpen = new QTimer;
QString Files::field = "";
QString Files::value = "";
QVector <StructProduct_t> Files::productVect = {};
QString Files::markerEmptyList = "EmptyFileBuyProduct";

Files::Files(QObject *parent) : QObject(parent)
{
  stateNFCReader = false;
  stateEnableRfid = false;
  stateStandby = false;
  connect(timerLockTimeOut, &QTimer::timeout, this, &Files::slotLock);
  connect(timerLockAfterOpen, &QTimer::timeout, this, &Files::slotLock);

  fsWatcher = new QFileSystemWatcher(this);
  fsWatcher->addPath(PathesFiles::pathFileConnect);
  fsWatcher->addPath(PathesFiles::pathFileProductTxt);
  fsWatcher->addPath(PathesFiles::pathFileBuyProduct);
  fsWatcher->addPath(PathesFiles::pathFileModes);
  connect(fsWatcher, &QFileSystemWatcher::fileChanged, this, &Files::changed);
  fsWatcher->addPath("../FolderDataUpdate/");
  connect(fsWatcher, &QFileSystemWatcher::directoryChanged, this, &Files::changedUpdateFolder);

}
void Files::changed(const QString fileName){
  qDebug () << "Files::changed";
  QFileInfo checkFileConnect(PathesFiles::pathFileConnect);
  QFileInfo checkFileProductTxt(PathesFiles::pathFileProductTxt);
  QFileInfo checkFileBuyProduct(PathesFiles::pathFileBuyProduct);
  QFileInfo checkFileModes(PathesFiles::pathFileModes);
  while(!checkFileConnect.exists() |
        !checkFileProductTxt.exists() |
        !checkFileBuyProduct.exists()  |
        !checkFileModes.exists())
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  fsWatcher->addPath(PathesFiles::pathFileConnect);
  fsWatcher->addPath(PathesFiles::pathFileProductTxt);
  fsWatcher->addPath(PathesFiles::pathFileBuyProduct);
  fsWatcher->addPath(PathesFiles::pathFileModes);
  if (fileName == PathesFiles::pathFileProductTxt){
      rewriteBuyFile();
    }
  if (fileName == PathesFiles::pathFileModes){
      if ((getModeFromModeFile() == Fridge::modeInitialization) && (getStatusModeFile() == Fridge::statusStandby)){
          //ициализация
          if (stateStandby == false){
              stateStandby = true;
              stateNFCReader = false;
              stateEnableRfid = false;
              writeFileConnect(RFID_ENABLE, 0);
              writeFileConnect(OUT_1, 0);
              emit signalInitReader();
              emit signalRunRFIDProcess();
              QThread::msleep(500);
            }
        } else {
          stateStandby = false;
          if (stateEnableRfid == false){
              stateEnableRfid = true;
              writeFileConnect(RFID_ENABLE, 1);
            }
        }
//      if (getStatusModeFile() == Fridge::statusReopenDoor){
//          writeFileConnect(OUT_1, 1);
//          changeStatusToModeFile(Fridge::statusBuyerCanOpenTheDoor);
//        }
      if (getStatusModeFile() == Fridge::statusButtonGoToShopPressed){
          if (stateNFCReader == false){
              emit signalEnableNFCReader();
              stateNFCReader = true;
            }
        }
    }
  if (fileName == PathesFiles::pathFileConnect){
      if (getStatusModeFile() == Fridge::statusBuyerCanOpenTheDoor){
          if (readFileConnect(CHECK_DOOR) > 0){
              timerLockAfterOpen->start(timeLockAfterOpen);
              changeStatusToModeFile(Fridge::statusDoorIsOpen);
            }
        }
      if ((getStatusModeFile() == Fridge::statusDoorIsOpen) || (getStatusModeFile() == Fridge::errorDoorIsNotClosed)){
          if (readFileConnect(CHECK_DOOR) == 0){
              changeStatusToModeFile(Fridge::statusDoorIsClose);
              emit signalKillRFIDProcess();
            }
        }
    }
}
void Files::slotLock(){ //слот для закрытия замка по таймеру таймаута или через N секунд после открытия двери
  timerLockTimeOut->stop();
  timerLockAfterOpen->stop();
  writeFileConnect(1,0);
}
void Files::writeFileConnect(int position, int state){
  QFile fileConnect(PathesFiles::pathFileConnect);
  QString strBuf="";
  QStringList listString;
  if (fileConnect.open(QFile::ReadOnly | QIODevice::Text)) {
      if (fileConnect.exists())
        {
          while(!fileConnect.atEnd()) {
              listString.append(fileConnect.readLine());
            }
          fileConnect.close();
          if (!(listString.size() > 0)){
              return;
            }
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
int Files::readFileConnect(int position)
{
  QFile fileConnect(PathesFiles::pathFileConnect);
  QString strConnect="";
  QStringList listString;
  if (fileConnect.open(QFile::ReadOnly | QIODevice::Text)) {
      if (fileConnect.exists()){
          while(!fileConnect.atEnd()){
              listString.append(fileConnect.readLine());
            }
          fileConnect.close();
          if (listString.size() == 0){
              return -1;
            }
          QRegExp rx("(\\ |\\,|\\.|\\:|\\t|\\n)");
          QStringList bufList = listString[position].split(rx, QString :: SkipEmptyParts);
          return bufList.at(1).toInt();
        }
    }
  return 0;
}
QStringList Files::readBuyFile()
{
  QStringList listBuyProducts = {};
  QString bufStr="";
  QRegExp rx("(\\ |\\,|\\.|\\:|\\t|\\n)");
  QFile filebuyProduct(PathesFiles::pathFileProductTxt);
  if (filebuyProduct.open(QFile::ReadOnly | QIODevice::Text)) {
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
void Files::readFileConnectToStruct(StructFileConnect_t *structConnect)
{
  QStringList listTextConnect;
  QFile fileConnect(PathesFiles::pathFileConnect);
  if (fileConnect.open(QFile::ReadOnly | QIODevice::Text)) {
      if (fileConnect.exists()){
          QString strConnect="";
          while(!fileConnect.atEnd()){
              strConnect += fileConnect.readLine();
            }
          QRegExp rx("(\\ |\\,|\\.|\\:|\\t|\\n)");
          listTextConnect = strConnect.split(rx,  QString :: SkipEmptyParts);
          fileConnect.close();
          if (!(listTextConnect.size() > 0)){
              return;
            }
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
  readFileConnectToStruct(&aStructFileConnect);
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
  QFile fileModes(PathesFiles::pathFileModes);
  if (fileModes.open(QIODevice::ReadOnly | QIODevice::Text)){
      if (fileModes.exists()){
          QJsonObject objMain;
          fileModes.close();
          objMain.insert("mode", mode);
          objMain.insert("status", status);
          fileModes.open(QFile::WriteOnly);
          fileModes.write(QJsonDocument(objMain).toJson());
          fileModes.close();
        }
    }
}
void Files::changeStatusToModeFile(QString status)
{
  QFile fileModes(PathesFiles::pathFileModes);
  if (fileModes.open(QIODevice::ReadOnly | QIODevice::Text)){
      if (fileModes.exists()){
          QJsonObject objMain = QJsonDocument::fromJson(fileModes.readAll()).object();
          fileModes.close();
          objMain.insert("status", status);
          fileModes.open(QFile::WriteOnly);
          fileModes.write(QJsonDocument(objMain).toJson());
          fileModes.close();
        }
    }
}
void Files::changeArrayToModeFile(QString name, QStringList list)
{
  QFile fileModes(PathesFiles::pathFileModes);
  if (fileModes.open(QIODevice::ReadOnly | QIODevice::Text)){
      if (fileModes.exists()){
          QJsonObject objMain = QJsonDocument::fromJson(fileModes.readAll()).object();
          fileModes.close();
          QJsonArray array = QJsonArray::fromStringList(list);
          objMain.insert(name, array);
          fileModes.open(QFile::WriteOnly);
          fileModes.write(QJsonDocument(objMain).toJson());
          fileModes.close();
        }
    }
}
QString Files::getStatusModeFile(){
  QFile fileModes(PathesFiles::pathFileModes);
  if (fileModes.open(QIODevice::ReadOnly | QIODevice::Text)){
      if (fileModes.exists()){
          QJsonObject objMain = QJsonDocument::fromJson(fileModes.readAll()).object();
          fileModes.close();
          QString status;
          status = objMain.value("status").toString();
          return status;
        }
    }
  return "";
}
QString Files::getModeFromModeFile()
{
  QFile fileModes(PathesFiles::pathFileModes);
  if (fileModes.open(QIODevice::ReadOnly | QIODevice::Text)){
      if (fileModes.exists()){
          QJsonObject objMain = QJsonDocument::fromJson(fileModes.readAll()).object();
          fileModes.close();
          QString mode;
          mode = objMain.value("mode").toString();
          return mode;
        }
    }
  return "";
}
void Files::changedUpdateFolder(const QString &dirName)
{
  qDebug () << QDateTime::currentDateTime().time() << "ChangedD Directory!";
  QDir dir = dirName;
  dir.setFilter(QDir::Files | QDir::NoSymLinks);
  QFileInfoList listFiles = dir.entryInfoList();
  foreach (QFileInfo fileInfo, listFiles){
      qDebug() << "File info:" << fileInfo.fileName();
      if (!(QString::compare(fileInfo.fileName(), "FileProduct.json"))){
          readJsonProduct("../FolderDataUpdate/FileProduct.json");
          writeVectorTagsToTxt();
        }
      if (!(QString::compare(fileInfo.fileName(), "FileDescription.json"))){
          QFile::remove("../FolderData/Files/FileDescription.json");
          QFile::copy("../FolderDataUpdate/FileDescription.json", "../FolderData/Files/FileDescription.json");
        }
    }
}
void Files::writeVectorTagsToTxt()
{
  QFile fileProductVector("../FolderData/Files/FileProduct.txt");
  QString strProductVector="";
  if (fileProductVector.open(QFile::WriteOnly)) {
      if (fileProductVector.exists()) {
          fileProductVector.write("");
          for (int i = 0; i < Files::productVect.size(); i++)
            {
              strProductVector += "1 ";
              strProductVector += Files::productVect.at(i).TID + " ";
              strProductVector += Files::productVect.at(i).marker;
              if (i != (Files::productVect.size() - 1)){
                  strProductVector += "\n";
                }
            }
          fileProductVector.write(strProductVector.toUtf8());
          fileProductVector.close();
        }
    }
}
void Files::readJsonProduct(QString const &fileProd)
{
  Files::productVect.clear();
  StructProduct_t product;
  QFile file(fileProd);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
      if (file.exists()){
          QString strJson = file.readAll();
          file.close();
          if (strJson != ""){
              QJsonDocument doc = QJsonDocument::fromJson(strJson.toUtf8());
              QJsonObject objJson = doc.object();
              QStringList list = objJson.keys();
              for(QString strKey : list){
                  QJsonArray arrayProduct = objJson.value(strKey).toArray();
                  foreach (const QJsonValue & value, arrayProduct){
                      QJsonObject obj = value.toObject();
                      for (const QString &strField : obj.keys()) {
                          QString value = obj.value(strField).toString();
                          addTagFromJson(product, strField, value);
                        }
                      productVect.push_back(product);
                    }
                }
            }
        }
    }
}
void Files::addTagFromJson(StructProduct_t &product, QString field, QString value)
{
  if (field == "TID")
    product.TID = value;
  else if (field == "marker")
    product.marker = value;
}
void Files::updateListProduct()
{
  readJsonProduct(PathesFiles::pathUpdateFileProductJson);
  writeVectorTagsToTxt();
}
void Files::rewriteFileProductTxt() // удалить строки с "0" в начале
{
  QStringList listFileProductTxt;
  QStringList listBuf;
  QFile fileProduct(PathesFiles::pathFileProductTxt);
  if (fileProduct.open(QIODevice::ReadOnly | QIODevice::Text)){
      if (fileProduct.exists()){
          while(!fileProduct.atEnd()) {
              listFileProductTxt.append(fileProduct.readLine()); //получили список всех продуктов
            }
          fileProduct.close();
        }
    }
  if (listFileProductTxt.size() == 0){
      return;
    }
  for (QString bufStr : listFileProductTxt) {
      if (bufStr.at(0) == "1"){
          listBuf.append(bufStr); //получили список оставшихся продуктов
        }
    }
  if (listBuf.size() != 0){
      fileProduct.open(QFile::WriteOnly);
      for (QString bufStr : listBuf) {
          fileProduct.write(bufStr.toUtf8());
        }
      fileProduct.close();
    } else {
      return;
    }
}


//  FILE *file;
//  //printf ("Открытие файла: ");
//  file = fopen("../FolderData/Files/FileProduct.txt", "w+");
//  if (file == NULL){
//      printf ("Ошибка перезаписи файла продуктов\n");
//      return;
//    }
//  for (int i = 0; i < nProduct; i++){
//      if (listProduct[i].state == 1){
//          fprintf(file, "%d ", listProduct[i].state);
//          for (int k = 0; k < (int)sizeof(listProduct->TIDnumber); k++){
//              fprintf(file, "%2.2x", listProduct[i].TIDnumber[k]);
//            }
//          fprintf(file, " %-17s\n",  listProduct[i].marker);
//        }
//    }
//  fclose(file);
//void Files::rewriteListProductTxt;
//{

//}
void Files::rewriteBuyFile()
{
  QStringList listFileProduct;
  QStringList listFileBuyProduct;
  QFile fileProduct(PathesFiles::pathFileProductTxt);
  QFile fileBuyProduct(PathesFiles::pathFileBuyProduct);
  if (fileProduct.open(QFile::ReadOnly | QIODevice::Text)) {
      if (fileProduct.exists()){
          while(!fileProduct.atEnd()) {
              listFileProduct.append(fileProduct.readLine());
            }
          fileProduct.close();
          if (listFileProduct.size() == 0){
              return;
            }
          for (QString bufStr : listFileProduct) { //если нашли строку с нулем в начале()тег отсутствует - заносим в список купленных
              if (bufStr.at(0) == "0"){
                  listFileBuyProduct.append(bufStr);
                }
            }
          if (listFileBuyProduct.size() == 0){ //маркируем пустой файл
              fileBuyProduct.open(QFile::WriteOnly);
              fileBuyProduct.write(markerEmptyList.toUtf8());
              fileBuyProduct.close();
              return;
            } else {
              fileBuyProduct.open(QFile::WriteOnly);
              for (QString bufStr : listFileBuyProduct) {
                  fileBuyProduct.write(bufStr.toUtf8());
                }
              fileBuyProduct.close();
            }
        } else {
          return;
        }
    }

}
