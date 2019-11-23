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
  connect(&files, &Files::signalTextBrowser, this, &AddonFridge::slotRecieveText);
  connect(&files, &Files::signalRunRFIDProcess, this, &AddonFridge::slotRunRFIDProcess);
  connect(&files, &Files::signalKillRFIDProcess, this, &AddonFridge::slotKillRFIDProcess);
}
