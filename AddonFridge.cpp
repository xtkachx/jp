#include "AddonfFridge.hh"
QTimer *AddonFridge::timerRequest = new QTimer;
int AddonFridge::timeRequest = 3000;
AddonFridge::AddonFridge(QObject *parent) : QObject(parent)
{
  pmtreader.moveToThread(&thread1);
  thread1.start();
  server.sendInitFridge();
  connect(this, &AddonFridge::signalInitReader, &pmtreader, &PMTReader::slotInit);
  connect(this, &AddonFridge::signalGetUid, &pmtreader, &PMTReader::slotGetUid);
  connect(&pmtreader, &PMTReader::signalSendUid, this, &AddonFridge::slotRecieveUid);
  connect(&server, &Server::signalStatusUID, this, &AddonFridge::slotRecieveStatusUID);
  connect(&files, &Files::signalInitReader, this, &AddonFridge::slotInitReader);
  connect(&files, &Files::signalEnableNFCReader, this, &AddonFridge::slotReadUID);
  connect(&files, &Files::signalRunRFIDProcess, this, &AddonFridge::slotRunRFIDProcess);
  connect(&files, &Files::signalKillRFIDProcess, this, &AddonFridge::slotKillRFIDProcess);

}
void AddonFridge::slotInitReader(){
  emit signalInitReader();
  qDebug () << "emit signalInitReader";
}
void AddonFridge::slotReadUID(){
  emit signalGetUid();
}
void AddonFridge::slotRecieveUid(QString field, QString value){
  if (files.getStatusModeFile() != Fridge::statusStandby){
      if (field == "UID"){
          //fake
          connect(timerRequest, &QTimer::timeout, this, &AddonFridge::slotFakeTransmitUID);
          timerRequest->start(timeRequest);
//          server.sendUID(value);
          files.changeStatusToModeFile(Fridge::statusUIDSendToServer);
        }
      if (field == "error"){
          if ((value == "6")){
              emit signalGetUid();
            } else {
              files.changeStatusToModeFile(Fridge::statusUIDNoValid);
            }
        }
    }
}
void AddonFridge::slotFakeTransmitUID()
{
  timerRequest->stop();
  disconnect(timerRequest, &QTimer::timeout, this, &AddonFridge::slotFakeTransmitUID);
  server.sendUID("FA5673FF");
}
void AddonFridge::slotRecieveStatusUID(QString status)
{
  if (status == "buyer"){
      Files::changeModeToModeFile(Fridge::modeSale, Fridge::statusBuyerCanOpenTheDoor);
    }
  if (status == "service"){
      Files::changeModeToModeFile(Fridge::modeService, Fridge::statusMaintenanceEngineer);
    }
  if (status == "filling"){
      Files::changeModeToModeFile(Fridge::modeFilling, Fridge::statusFiller);
    }
  if (status == ""){
      Files::changeStatusToModeFile(Fridge::errorNoResponseFromServer);
    }
}
void AddonFridge::slotRunRFIDProcess()
{
  myprocess.runRFIDReader();
}
void AddonFridge::slotKillRFIDProcess()
{
  myprocess.killRFIDReader();
}
