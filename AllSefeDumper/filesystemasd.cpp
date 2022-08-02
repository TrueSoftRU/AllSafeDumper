#include "filesystemasd.h"

FileSystemASD::FileSystemASD(QObject *parent)
    : QObject{parent}
{

}

QString FileSystemASD::getNameFile(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return QFileInfo(file).fileName();
    } else {
        return "no open";
    }
}

QStringList FileSystemASD::readFileASD(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QStringList allTextLines;
        while(!file.atEnd()){
            QString line = file.readLine();
            allTextLines.append(line.split("\n"));
        }
        allTextLines.removeAll(QString(""));
        return allTextLines;
    } else {
        return QStringList("null");
    }
}

void FileSystemASD::loadSites(QString path, QTabWidget *site)
{
    QStringList sites = readFileASD(path);
    qDebug() << sites;
    if(sites != QStringList("null")){
        if(checkVersionFile(sites[0])){
            for(int i = 1; i < sites.count(); i++){
                qDebug() << "version - " << sites[0];
                qDebug() << readSite(sites[i]);
                QStringList siteParametrs = readSite(sites[i]);
                if(siteParametrs[0] != "null"){
                    site->addTab(new FormSite(nullptr, siteParametrs[0], siteParametrs[1],  siteParametrs[2], siteParametrs[9], siteParametrs[3].toInt(), siteParametrs[4].toInt(), siteParametrs[5].toInt(), siteParametrs[6].toInt(),
                            siteParametrs[7].toInt(), siteParametrs[8].toInt()), siteParametrs[0]);
                }
            }
        }

    }
}

bool FileSystemASD::checkVersionFile(QString version)
{
    QString versionProg = "1.0";
    return version == versionProg ? true : false;
}

QStringList FileSystemASD::readSite(QString site)
{
    qDebug() << "Строка вход - " << site;
    QStringList parametrsSite = site.split(",");
    qDebug() << "Кол парам. - " << parametrsSite.count();
    if(parametrsSite.count() < 10)
        return QStringList("null");

    for(int i = 0; i < parametrsSite.count(); i++){
        parametrsSite[i].remove(QString("--data=")).remove(QString("--noCast=")).remove(QString("--Command="))
                .remove(QString("--Tor=")).remove(QString("--Hex=")).remove(QString("--RiskLvL=")).remove(QString("--Win=")).remove(QString("--SearchParameters="));
        parametrsSite[i].remove(QString("\"")).remove(QString(" "));
    }
    return parametrsSite;
}


