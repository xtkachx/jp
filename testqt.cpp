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
void TestQT::on_pushButton_9_clicked()
{
  if (files.readFileConnection(OUT_1) > 0){
      files.writeFileConnect(OUT_1, 0);
    } else {
      files.writeFileConnect(OUT_1, 1);
    }
}
void TestQT::on_pushButton_clicked()
{
  if (files.readFileConnection(OUT_2) > 0){
      files.writeFileConnect(OUT_2, 0);
    } else {
      files.writeFileConnect(OUT_2, 1);
    }
}
void TestQT::on_pushButton_2_clicked()
{
  if (files.readFileConnection(CHECK_DOOR)  > 0){
      files.writeFileConnect(CHECK_DOOR, 0);
    } else {
      files.writeFileConnect(CHECK_DOOR, 1);
    }
}
void TestQT::on_pushButton_3_clicked()
{
  static int flagRunRfid = 0;
  if (flagRunRfid == 0){
      flagRunRfid = 1;
      myprocess.runRFIDReader();
      ui->pushButton_3->setStyleSheet("background-color: rgb(0, 255, 0)");
    } else {
      flagRunRfid = 0;
      myprocess.killRFIDReader();
      ui->pushButton_3->setStyleSheet("background-color: rgb(237, 212, 0)");
    }
}
void TestQT::on_pushButton_8_clicked(){
  if (files.readFileConnection(RFID_ENABLE) == 1){
      files.writeFileConnect(RFID_ENABLE, 0);
    } else {
      files.writeFileConnect(RFID_ENABLE, 1);
    }
}
void TestQT::on_pushButton_SaleMode_clicked(){
  files.changeModeToModeFile(Fridge::modeSale, Fridge::statusBuyerCanOpenTheDoor);
}
void TestQT::on_pushButtonFillingMode_clicked(){
  files.changeModeToModeFile(Fridge::modeFilling, Fridge::statusFiller);
}
void TestQT::on_pushButton_ServiceMode_clicked(){
  files.changeModeToModeFile(Fridge::modeService, Fridge::statusMaintenanceEngineer);
}
void TestQT::on_pushButton_Standby_clicked(){
  files.changeModeToModeFile(Fridge::modeInitialization, Fridge::statusStandby);
}
void TestQT::on_pushButton_TestButton_clicked(){
  files.changeStatusToModeFile(Fridge::statusButtonGoToShopPressed);
}
void TestQT::on_pushButton_ServiceMode_2_clicked()
{
  files.changeStatusToModeFile(Fridge::statusReopenDoor);
}
