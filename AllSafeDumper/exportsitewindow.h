#ifndef EXPORTSITEWINDOW_H
#define EXPORTSITEWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QCheckBox>
#include "filesystemasd.h"

namespace Ui {
class ExportSiteWindow;
}

class ExportSiteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExportSiteWindow(QWidget *parent = nullptr, QTabWidget *sites = nullptr);
    ~ExportSiteWindow();

signals:
    void showWindow();
    void onClickAllCheckBox();
    void exportedSites(QString path, QStringList selectedSites, QTabWidget *sites);

public slots:
    void addElement();

private slots:
    void workerExportListSite(QString textCheckBox);
    void exportSites();



private:
    Ui::ExportSiteWindow *ui;
    QStringList listSite;
    QTabWidget *_sites;
    QStringList exportListSite;
    FileSystemASD *fileSystemASD;
};

#endif // EXPORTSITEWINDOW_H
