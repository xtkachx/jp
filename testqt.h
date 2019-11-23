#ifndef TESTQT_H
#define TESTQT_H
#include "files.hh"
#include <QMainWindow>
#include <QApplication>
#include <QFile>
#include <QFileInfo>

namespace Ui {
  class TestQT;
}
class TestQT : public QMainWindow
{
  Q_OBJECT

public:
  explicit TestQT(QWidget *parent = nullptr);
  ~TestQT();

private slots:
  void on_pushButton_8_clicked();
  void on_pushButton_9_clicked();
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();

  void on_pushButton_SaleMode_clicked();

  void on_pushButtonFillingMode_clicked();

  void on_pushButton_ServiceMode_clicked();

  void on_pushButton_TestButton_clicked();

  void on_pushButton_Standby_clicked();

  void on_pushButton_UID_Sent_clicked();

  void on_pushButton_ServiceMode_2_clicked();

private:
  Ui::TestQT *ui;
  Files files;
  QFileSystemWatcher *fsWatcher;

};

#endif // TESTQT_H
