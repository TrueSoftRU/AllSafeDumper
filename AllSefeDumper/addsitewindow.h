#ifndef ADDSITEWINDOW_H
#define ADDSITEWINDOW_H

#include <QMainWindow>
#include "formsite.h"

namespace Ui {
class AddSiteWindow;
}

class AddSiteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddSiteWindow(QWidget *parent = nullptr, QTabWidget *tabWidget = nullptr);
    ~AddSiteWindow();

private slots:
    void addSite();

private:
    Ui::AddSiteWindow *ui;
    QTabWidget *siteTab;
};

#endif // ADDSITEWINDOW_H
