#include "exportsitewindow.h"
#include "ui_exportsitewindow.h"

#include <QCheckBox>
#include "qdynamiccheckbox.h"

ExportSiteWindow::ExportSiteWindow(QWidget *parent, QStringList listSite) :
    QMainWindow(parent),
    ui(new Ui::ExportSiteWindow)
{
    ui->setupUi(this);
    _listSite = listSite;

    connect(ui->pushButton, &QPushButton::clicked, [this](){
       qDebug() << exportListSite;
    });
    connect(ui->pushButton_2, &QPushButton::clicked, this, &ExportSiteWindow::onClickAllCheckBox);
    connect(this, &ExportSiteWindow::showWindow, this, &ExportSiteWindow::addElement);



    emit showWindow();
}

ExportSiteWindow::~ExportSiteWindow()
{
    delete ui;
}

void ExportSiteWindow::addElement()
{
    for(int i = 0; i < _listSite.count(); i++){

        QDynamicCheckBox *dCheckBox = new QDynamicCheckBox(this, _listSite[i]);
        ui->verticalLayout_2->addWidget(dCheckBox);

        connect(dCheckBox, &QDynamicCheckBox::onTogleGetText, this, &ExportSiteWindow::workerExportListSite);
        connect(this, &ExportSiteWindow::onClickAllCheckBox, dCheckBox, &QDynamicCheckBox::togleCheckAll);
    }
    QWidget *spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui->verticalLayout_2->addWidget(spacer);
}

void ExportSiteWindow::workerExportListSite(QString textCheckBox)
{
    qDebug() << textCheckBox;
    for(int i = 0; i < exportListSite.count(); i++){
        if(exportListSite[i] == textCheckBox){
            exportListSite.remove(i);
            return;
        }
    }
    exportListSite.append(textCheckBox);
}


