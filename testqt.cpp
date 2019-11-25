#include "testqt.h"
#include "ui_testqt.h"
#define RFID_ENABLE 0
#define OUT_1 1
#define OUT_2 2
#define CHECK_DOOR 3

TestQT::TestQT(QWidget *parent) : QMainWindow(parent), ui(new Ui::TestQT)
{
  ui->setupUi(this);
  fsWatcher = new QFileSystemWatcher(this);
  fsWatcher->addPath(PathesFiles::pathFileConnect);
  fsWatcher->addPath(PathesFiles::pathFileProduct);
  fsWatcher->addPath(PathesFiles::pathFileBuyProduct);
  fsWatcher->addPath(PathesFiles::pathFileModes);
  connect(fsWatcher, &QFileSystemWatcher::fileChanged, this, &TestQT::slotTextOutput);
}
TestQT::~TestQT()
{
  delete ui;
}
void TestQT::slotTextOutput(){
  QFile fileConnect(PathesFiles::pathFileConnect);
  QFile fileProduct(PathesFiles::pathFileProduct);
  QFile fileBuyProduct(PathesFiles::pathFileBuyProduct);
  QFile fileModes(PathesFiles::pathFileModes);
  if (fileConnect.open(QFile::ReadOnly)) {
      if (fileConnect.exists()){
          QString strConnect="";
          while(!fileConnect.atEnd()){
              strConnect += fileConnect.readLine();
            }
          ui->textBrowser->setText(strConnect);
          fileConnect.close();
        }
    }
  if (fileProduct.open(QFile::ReadOnly)) {
      if (fileProduct.exists()){
          QString strProduct="";
          while(!fileProduct.atEnd()){
              strProduct += fileProduct.readLine();
            }
          ui->textBrowser_2->setText(strProduct);
          fileProduct.close();
        }
    }
  if (fileBuyProduct.open(QFile::ReadOnly)) {
      if (fileBuyProduct.exists()){
          QString strBuyProduct="";
          while(!fileBuyProduct.atEnd()){
              strBuyProduct += fileBuyProduct.readLine();
            }
          ui->textBrowser_3->setText(strBuyProduct);
          fileBuyProduct.close();
        }
    }
  if (fileModes.open(QFile::ReadOnly)) {
      if (fileModes.exists()){
          QString strFileModes="";
          while(!fileModes.atEnd()){
              strFileModes += fileModes.readLine();
            }
          ui->textBrowser_4->setText(strFileModes);
          fileModes.close();
        }
    }}
void TestQT::on_pushButton_8_clicked(){
  if (Files::readFileConnect(RFID_ENABLE) > 0){
      Files::writeFileConnect(RFID_ENABLE, 0);
    } else if (Files::readFileConnect(RFID_ENABLE) == 0){
      Files::writeFileConnect(RFID_ENABLE, 1);
    }
  if (Files::readFileConnect(RFID_ENABLE) < 0) {
      qDebug () << "Not fing FileConnect!";
    }
}
void TestQT::on_pushButton_9_clicked()
{
  if (Files::readFileConnect(OUT_1) > 0){
      Files::writeFileConnect(OUT_1, 0);
    } else if (Files::readFileConnect(OUT_1) == 0){
      Files::writeFileConnect(OUT_1, 1);
    }
  if (Files::readFileConnect(OUT_1) < 0){
      qDebug () << "Not fing FileConnect!";
    }
}
void TestQT::on_pushButton_clicked()
{
  if (Files::readFileConnect(OUT_2) > 0){
      Files::writeFileConnect(OUT_2, 0);
    } else if (Files::readFileConnect(OUT_2) == 0){
      Files::writeFileConnect(OUT_2, 1);
    }
  if (Files::readFileConnect(OUT_2) < 0){
      qDebug () << "Not fing FileConnect!";
    }
}
void TestQT::on_pushButton_2_clicked()
{
  if (Files::readFileConnect(CHECK_DOOR) > 0){
      Files::writeFileConnect(CHECK_DOOR, 0);
    } else if (Files::readFileConnect(CHECK_DOOR) == 0) {
      Files::writeFileConnect(CHECK_DOOR, 1);
    }
  if (Files::readFileConnect(CHECK_DOOR) < 0) {
      qDebug () << "Not fing FileConnect!";
    }
}
void TestQT::on_pushButton_3_clicked()
{
  static int flagRunRfid = 0;
  if (flagRunRfid == 0){
      flagRunRfid = 1;
      MyProcess::runRFIDReader();
      ui->pushButton_3->setStyleSheet("background-color: rgb(0, 255, 0)");
    } else {
      flagRunRfid = 0;
      MyProcess::killRFIDReader();
      ui->pushButton_3->setStyleSheet("background-color: rgb(237, 212, 0)");
    }
}
void TestQT::on_pushButton_SaleMode_clicked(){
  Files::changeModeToModeFile(Fridge::modeSale, Fridge::statusBuyerCanOpenTheDoor);
}
void TestQT::on_pushButtonFillingMode_clicked(){
  Files::changeModeToModeFile(Fridge::modeFilling, Fridge::statusFiller);
}
void TestQT::on_pushButton_ServiceMode_clicked(){
  Files::changeModeToModeFile(Fridge::modeService, Fridge::statusMaintenanceEngineer);
}
void TestQT::on_pushButton_Standby_clicked(){
  Files::changeModeToModeFile(Fridge::modeInitialization, Fridge::statusStandby);
}
void TestQT::on_pushButton_TestButton_clicked(){
  Files::changeStatusToModeFile(Fridge::statusButtonGoToShopPressed);
}
void TestQT::on_pushButton_ServiceMode_2_clicked()
{
  Files::changeStatusToModeFile(Fridge::statusReopenDoor);
}
