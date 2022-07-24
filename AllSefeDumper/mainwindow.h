#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "formsite.h"
#include "addsitewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showAddSiteWindow();

    void test();

    void testAddSite();

private:
    Ui::MainWindow *ui;
    AddSiteWindow *addSiteWindow;
};
#endif // MAINWINDOW_H
