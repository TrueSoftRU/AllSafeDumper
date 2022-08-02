#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // connect(ui->menu, SIGNAL(aboutToShow()), this, SLOT(test()));



    fileSystem = new FileSystemASD(this);

    connect(ui->action_import, &QAction::triggered, this, &MainWindow::actionImportSites);
    connect(ui->action_export, &QAction::triggered, this, &MainWindow::actionExportSites);

    connect(ui->action_addSite, &QAction::triggered, this, &MainWindow::showAddSiteWindow);

    connect(this, &MainWindow::importSites, fileSystem, &FileSystemASD::loadSites);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAddSiteWindow()
{
    addSiteWindow = new AddSiteWindow(this, ui->tabSites);
    addSiteWindow->show();
}

void MainWindow::actionImportSites()
{
    QString path = QFileDialog::getOpenFileName(this, "Выбрать файл", "C:/Users/", "ASD File (*.asd);");
    //qDebug() << emit readFileASD(path);
    emit importSites(path, ui->tabSites);
}

void MainWindow::actionExportSites()
{
    QStringList listSites = {};

    //TEST read Site;
//    qDebug() << ui->tabSites->tabText(0);
//    QWidget *widget = ui->tabSites->widget(0);
//    FormSite *form;
//    form = (FormSite*)widget;
//    qDebug() << emit form->readSite();


    for(int i = 0; i < ui->tabSites->count(); i++){
        listSites.append(ui->tabSites->tabText(i));
    }




    exportSiteWindow = new ExportSiteWindow(this, listSites);
    exportSiteWindow->show();
}

void MainWindow::testAddSite()
{
    ui->tabSites->addTab(new FormSite(), QString("Tab %0").arg(ui->tabSites->count() + 1));
}

