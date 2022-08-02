#ifndef FILESYSTEMASD_H
#define FILESYSTEMASD_H

#include <QObject>
#include <QTabWidget>
#include <QFileDialog>
#include <QStringList>
#include "formsite.h"

class FileSystemASD : public QObject
{
    Q_OBJECT
public:
    explicit FileSystemASD(QObject *parent = nullptr);

signals:

public slots:
    QString getNameFile(QString path);
    QStringList readFileASD(QString path);
    void loadSites(QString path, QTabWidget *site);

private slots:
    bool checkVersionFile(QString version);
    QStringList readSite(QString site);

private:

};

#endif // FILESYSTEMASD_H
