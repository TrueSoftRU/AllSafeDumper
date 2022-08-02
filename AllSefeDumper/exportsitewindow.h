#ifndef EXPORTSITEWINDOW_H
#define EXPORTSITEWINDOW_H

#include <QMainWindow>

namespace Ui {
class ExportSiteWindow;
}

class ExportSiteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExportSiteWindow(QWidget *parent = nullptr, QStringList listSite = {""});
    ~ExportSiteWindow();

signals:
    void showWindow();
    void onClickAllCheckBox();

public slots:
    void addElement();

private slots:
    void workerExportListSite(QString textCheckBox);



private:
    Ui::ExportSiteWindow *ui;
    QStringList _listSite;
    QStringList exportListSite;
};

#endif // EXPORTSITEWINDOW_H
