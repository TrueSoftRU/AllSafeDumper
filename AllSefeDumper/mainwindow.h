#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "formsite.h"
#include "addsitewindow.h"
#include "filesystemasd.h"
#include "exportsitewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    QStringList readFileASD(QString path);

    void importSites(QString path, QTabWidget *site);

private slots:
    void showAddSiteWindow();

    void actionImportSites();
    void actionExportSites();

    void testAddSite();

private:
    Ui::MainWindow *ui;
    AddSiteWindow *addSiteWindow;
    FileSystemASD *fileSystem;
    ExportSiteWindow *exportSiteWindow;

};
#endif // MAINWINDOW_H
