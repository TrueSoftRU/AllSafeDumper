#include "exportsitewindow.h"
#include "ui_exportsitewindow.h"
#include "qdynamiccheckbox.h"

ExportSiteWindow::ExportSiteWindow(QWidget *parent, QTabWidget *sites) :
    QMainWindow(parent),
    ui(new Ui::ExportSiteWindow)
{
    ui->setupUi(this);

    fileSystemASD = new FileSystemASD(this);
    _sites = sites;

    for(int i = 0; i < sites->count(); i++){
        listSite.append(sites->tabText(i));
    }

    connect(ui->pushButton_export, &QPushButton::clicked, this, &ExportSiteWindow::exportSites);
    connect(ui->pushButton_allSites, &QPushButton::clicked, this, &ExportSiteWindow::onClickAllCheckBox);
    connect(this, &ExportSiteWindow::showWindow, this, &ExportSiteWindow::addElement);

    connect(this, &ExportSiteWindow::exportedSites, fileSystemASD, &FileSystemASD::exportSites);

    connect(fileSystemASD, &FileSystemASD::exportedSuccessfully, [this](int countSites){
        ui->statusbar->showMessage(QString("Успешно экспортировано: %0").arg(countSites), 3000);
    });



    emit showWindow();
}

ExportSiteWindow::~ExportSiteWindow()
{
    delete ui;
}

void ExportSiteWindow::addElement()
{
    for(int i = 0; i < listSite.count(); i++){

        QDynamicCheckBox *dCheckBox = new QDynamicCheckBox(this, listSite[i]);
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

void ExportSiteWindow::exportSites()
{
    QString savePath = QFileDialog::getSaveFileName(0, "Сохранить файл как", "sites", "*.asd");
    emit exportedSites(savePath, exportListSite, _sites);
}


