#include "addsitewindow.h"
#include "ui_addsitewindow.h"

AddSiteWindow::AddSiteWindow(QWidget *parent, QTabWidget *tabWidget) :
    QMainWindow(parent),
    ui(new Ui::AddSiteWindow)
{
    ui->setupUi(this);

    siteTab = tabWidget;

    connect(ui->pushButton_add, &QPushButton::clicked, this, &AddSiteWindow::onClickedAddSite);
}

AddSiteWindow::~AddSiteWindow()
{
    delete ui;
}

void AddSiteWindow::onClickedAddSite()
{

    qDebug() << "test";

    QString nameSite = ui->lineEdit_nameSite->text();
    QString url = ui->lineEdit_siteUrl->text();
    QString data = ui->lineEdit_data->text();
    QString searchParametrs = ui->lineEdit_searchParametrs->text();

    if(nameSite.length() > 0 && url.length() > 0){
        siteTab->addTab(new FormSite(nullptr, nameSite, url, data, searchParametrs, ui->checkBox_noCast->checkState(), ui->checkBox_Command->checkState(),
                                     ui->checkBox_Tor->checkState(), ui->checkBox_Hex->checkState(), ui->checkBox_RiskLvL->checkState(), ui->checkBox_Win->checkState()), nameSite);
    }else{
        ui->statusbar->showMessage("Заполните все поля!", 3000);
    }
}
