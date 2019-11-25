#ifndef INFORMATION_HH
#define INFORMATION_HH
#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileSystemWatcher>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <QTime>
#include <QDate>
#include <QString>
typedef struct structProduct{
  QString marker;
  QString EPC;
} StructProduct_t;
class Information : public QMainWindow
{
  Q_OBJECT
public:
  explicit Information(QWidget *parent = nullptr);
  void readJsonProduct(QString const &fileDesc);
  void writeVectorTagsToTxt();
private slots:
  void changedUpdateFolder(const QString & dirName);

private:
  QFileSystemWatcher *fsWatcher;
  QVector <StructProduct_t> productVect;
  void addTagFromJson(StructProduct_t &product, QString field, QString value);
};

#endif // INFORMATION_HH
