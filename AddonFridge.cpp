#include "AddonfFridge.hh"

AddonFridge::AddonFridge(QObject *parent) : QObject(parent)
{
  pmtreader.moveToThread(&thread1);
  thread1.start();
  server.sendInitFridge();
  connect(this, &AddonFridge ::signalInitReader, &pmtreader, &PMTReader::slotInit);
  connect(this, &AddonFridge::signalGetUid, &pmtreader, &PMTReader::slotGetUid);
  connect(&pmtreader, &PMTReader::signalSendUid, this, &AddonFridge::slotRecieveUid);
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
          server.sendUID(value);
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
void AddonFridge::slotRunRFIDProcess()
{
  myprocess.runRFIDReader();
}
void AddonFridge::slotKillRFIDProcess()
{
  myprocess.killRFIDReader();
}
