#include "information.hh"

Information::Information(QWidget *parent) : QMainWindow(parent)
{
  fsWatcher = new QFileSystemWatcher(this);
  fsWatcher->addPath("../FolderDataUpdate/");
  connect(fsWatcher, SIGNAL(directoryChanged(QString)), this, SLOT(changed(QString)));
}
void Information::readJsonProduct(QString const &fileProd)
{
  productVect.clear();
  StructProduct_t product;
  QFile file(fileProd);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
      return;
    }
  QString strJson = file.readAll();
  file.close();
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
void Information::writeVectorTagsToTxt()
{
  QFile fileProductVector("../FolderData/Files/FileProduct.txt");
  QString strProductVector="";
  if (fileProductVector.open(QFile::WriteOnly)) {
      if (fileProductVector.exists()) {
          fileProductVector.write("");
          for (int i = 0; i < productVect.size(); i++)
            {
              strProductVector += "1 ";
              strProductVector += productVect.at(i).EPC + " ";
              strProductVector += productVect.at(i).marker;
              if (i != (productVect.size() - 1)){
                  strProductVector += "\n";
                }
            }
          fileProductVector.write(strProductVector.toUtf8());
          fileProductVector.close();
        }
    }
}
void Information::addTagFromJson(StructProduct_t &product, QString field, QString value)
{
  if (field == "EPC")
    product.EPC = value;
  else if (field == "marker")
    product.marker = value;
}
void Information::changed(const QString &dirName)
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
