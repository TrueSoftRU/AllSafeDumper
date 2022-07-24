#include "addsitewindow.h"
#include "ui_addsitewindow.h"

AddSiteWindow::AddSiteWindow(QWidget *parent, QTabWidget *tabWidget) :
    QMainWindow(parent),
    ui(new Ui::AddSiteWindow)
{
    ui->setupUi(this);


}

AddSiteWindow::~AddSiteWindow()
{
    delete ui;
}

void AddSiteWindow::addSite()
{

}
