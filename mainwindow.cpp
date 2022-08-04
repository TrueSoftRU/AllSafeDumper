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
    connect(ui->action_HideShowDelitedSite, &QAction::toggled, [this](bool check){
        ui->tabSites->setTabsClosable(check);
    });

    connect(ui->action_addSite, &QAction::triggered, this, &MainWindow::showAddSiteWindow);
    connect(ui->tabSites, &QTabWidget::tabCloseRequested, [this](int index){
       ui->tabSites->removeTab(index);
    });

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
    QString path = QFileDialog::getOpenFileName(this, "Выбрать файл", "", "ASD File (*.asd)");
    //qDebug() << emit readFileASD(path);
    emit importSites(path, ui->tabSites);
}

void MainWindow::actionExportSites()
{
    exportSiteWindow = new ExportSiteWindow(this, ui->tabSites);
    exportSiteWindow->show();
}

void MainWindow::testAddSite()
{
    ui->tabSites->addTab(new FormSite(), QString("Tab %0").arg(ui->tabSites->count() + 1));
}

