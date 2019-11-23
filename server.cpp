#include "server.hh"
Server::Server(QWidget *parent) : QWidget(parent)
{
  timerStatusFridge = new QTimer();
  connect(timerStatusFridge, SIGNAL(timeout()), this, SLOT(checkStatusFridge()));
  //  timerStatusFridge->start(3000);

  urlInitFridge = "http://81.173.114.250:81/api/fridge?request=";
  urlSendingBuyProducts = "http://mayer.zmogesh.com/api/get-products?request=";
  urlSendStatusFridge = "http://mayer.zmogesh.com/api/get-products?request=";
  urlSendUid = "http://mayer.zmogesh.com/api/get-products?request=";

}
//---------------------------------------------------------------------------------------------
//------------------------------Initialization-------------------------------------------------
//---------------------------------------------------------------------------------------------
void Server::sendInitFridge()
{
  QString param = addInitToJson(getMacAddress(), getIpTun0());
  QNetworkRequest request(QUrl(urlInitFridge + param.toUtf8().toBase64()));
  QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
  connect(mngr, SIGNAL(finished(QNetworkReply*)), this, SLOT(getResponseInit(QNetworkReply*)));
  mngr->get(request);
}
void Server::getResponseInit(QNetworkReply *reply)
{
  QByteArray arrayReply = reply->readAll();
}
//----------------------------------------------------------------------------------------------
//------------------------------UID request/reply-----------------------------------------------
//----------------------------------------------------------------------------------------------
void Server::sendUID(QString strUID)
{
  QNetworkRequest request(QUrl(urlSendUid + strUID.toUtf8().toBase64()));
  QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
  connect(mngr, SIGNAL(finished(QNetworkReply*)), this, SLOT(getResponseUid(QNetworkReply*)));

  mngr->get(request);
}
void Server::getResponseUid(QNetworkReply *reply)
{
  QString status;
  QByteArray arrayReply = reply->readAll();
  //  checkResponseStatusUid();
  status = "buyer";
  if (status == "buyer"){
      files.changeModeToModeFile(Fridge::modeSale, Fridge::statusBuyerCanOpenTheDoor);
    }
  if (status == "service"){
      files.changeModeToModeFile(Fridge::modeService, Fridge::statusMaintenanceEngineer);
    }
  if (status == "filling"){
      files.changeModeToModeFile(Fridge::modeFilling, Fridge::statusFiller);
    }
  if (status == ""){
      files.changeStatusToModeFile(Fridge::errorNoResponseFromServer);
    }
  QThread::msleep(3000);
  QObject *networkManager = sender();
  networkManager->deleteLater();
}
QString Server::checkResponseStatusUid(QString statusUid)
{
  statusUid = "";
  return statusUid;
}

//----------------------------------------------------------------------------------------------
//------------------------------status Fridge---------------------------------------------------
//----------------------------------------------------------------------------------------------
void Server::sendStatusFridge(QString strStatus)
{
  QNetworkRequest request(QUrl(urlSendStatusFridge + strStatus.toUtf8().toBase64()));
  QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
  connect(mngr, SIGNAL(finished(QNetworkReply*)), this, SLOT(getResponse(QNetworkReply*)));
  mngr->get(request);
}
void Server::getResponseStatus(QNetworkReply *reply)
{
  qDebug() << "Ответ от сервера:";
  QString strReply = reply->readAll();
  qDebug() << strReply;
  QObject *networkManager = sender();
  networkManager->deleteLater();
}
//----------------------------------------------------------------------------------------------
//------------------------------send buying product---------------------------------------------
//----------------------------------------------------------------------------------------------
void Server::sendBuyingProducts(QString strJsonProducts)
{
  QNetworkRequest request(QUrl(urlSendingBuyProducts + strJsonProducts.toUtf8().toBase64()));
  QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
  connect(mngr, SIGNAL(finished(QNetworkReply*)), this, SLOT(getResponse(QNetworkReply*)));
  mngr->get(request);
}
void Server::getResponseBuyingProducts(QNetworkReply *reply)
{
  qDebug() << "Ответ от сервера:";
  QString strReply = reply->readAll();
  qDebug() << strReply;
  QObject *networkManager = sender();
  networkManager->deleteLater();
}
//--------------------------------------------------------------------------------------------------

void Server::sendFileConnect()
{
  QString strMAC = getMacAddress();
  Files::structFileConnect aStructFileConnect = {"", 0, "", 0, "", 0, "", 0};
  files.readFileConnect(&aStructFileConnect);

  const auto data = R"({})";
  auto doc = QJsonDocument::fromJson(data);
  auto obj = doc.object();
  obj.insert("unique", strMAC);
  obj.insert(aStructFileConnect.nameRfidEnable, aStructFileConnect.stateRfidEnable);
  obj.insert(aStructFileConnect.nameCheckDoor, aStructFileConnect.stateCheckDoor);
  doc.setObject(obj);
  qDebug() << "\nJSON:\n"
           << qPrintable(doc.toJson(QJsonDocument::Indented));
  QString strJson(doc.toJson(QJsonDocument::Compact));
  qDebug() << strJson;
  qDebug() << strJson.toUtf8().toBase64();
  sendStatusFridge(strJson);
}
QString Server::getMacAddress()
{
  foreach(QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
    {
      if (!(netInterface.flags() & QNetworkInterface::IsLoopBack))
        return netInterface.hardwareAddress();
    }
  return QString();
}
void Server::formBuyinglist()
{
  QStringList listBuyProducts = files.readBuyFile();
  qDebug() << listBuyProducts;
  qDebug() << listBuyProducts.size();
  const auto data = R"({"status": "success"})";
  QJsonDocument doc = QJsonDocument::fromJson(data);
  QJsonObject obj = doc.object();
  obj.insert("unique", getMacAddress());
  QJsonArray arr;
  for (QString strBuf : listBuyProducts){
      arr.append(strBuf);
    }
  obj.insert("products", arr);
  doc.setObject(obj);
  qDebug() << "\nJSON:\n"
           << qPrintable(doc.toJson( QJsonDocument::Indented ) );
  QString strJson(doc.toJson(QJsonDocument::Compact));
  qDebug() << strJson;
  qDebug() << strJson.toUtf8().toBase64();
  sendBuyingProducts(strJson);
}
QString Server::getIpTun0()
{
  QString ret = "";
  foreach(QNetworkInterface interface, QNetworkInterface::allInterfaces()){
      if (interface.flags().testFlag(QNetworkInterface::IsUp))
        foreach (QNetworkAddressEntry entry, interface.addressEntries()) {
            if (entry.ip().toString().contains(".") && interface.humanReadableName().contains("tun0")){
                ret = entry.ip().toString();
                return ret;
              }
          }
    }
  return ret;
}
void Server::checkStatusFridge()
{
  QString strMAC = getMacAddress();
  QString statusFridge = "";
  QString statusNFC = "waiting";   //write function for reading status NFC reading
  statusFridge = files.GetStateFridge();

  const auto data = R"({})";
  auto doc = QJsonDocument::fromJson(data);
  auto obj = doc.object();
  obj.insert("unique", strMAC);
  if ((statusFridge == "waiting") && (statusNFC == "waiting")){
      obj.insert("status", "OK");
    } else {

      obj.insert("status", "error");
      obj.insert("error", QJsonObject() );
      auto objError = doc.object()["error"].toObject();
      if (statusFridge != "waitng"){
          objError.insert("device", "fridge");
          objError.insert("message", statusFridge);
        }
      if (statusNFC != "waiting"){
          objError.insert("device", "NFC");
          objError.insert("message", statusNFC);
        }
      obj["error"] = objError;
    }
  doc.setObject(obj);
  qDebug() << "\nJSON:\n"
           << qPrintable(doc.toJson(QJsonDocument::Indented));
  QString strJson(doc.toJson(QJsonDocument::Compact));
  qDebug() << strJson;
  qDebug() << strJson.toUtf8().toBase64();
  sendStatusFridge(strJson);
}
QString Server::addInitToJson(QString unique, QString ipTun0)
{
  const auto data = R"({})";
  QJsonDocument doc = QJsonDocument::fromJson(data);
  QJsonObject obj = doc.object();
  obj.insert("unique", unique);
  obj.insert("ip", ipTun0);
  doc.setObject(obj);
  //  qDebug() << "\nJSON:\n"
  //           << qPrintable(doc.toJson(QJsonDocument::Indented));
  QString strJson(doc.toJson(QJsonDocument::Compact));
  return strJson;
}
