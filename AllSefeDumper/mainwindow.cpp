#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // connect(ui->menu, SIGNAL(aboutToShow()), this, SLOT(test()));

    addSiteWindow = new AddSiteWindow(this, ui->tabSites);

    connect(ui->action_export, &QAction::triggered, this, &MainWindow::test);

    connect(ui->action_addSite, &QAction::triggered, this, &MainWindow::showAddSiteWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAddSiteWindow()
{
    addSiteWindow->show();
}

void MainWindow::test()
{
    ui->statusbar->showMessage("TEst");
    qDebug() << "Test";
}

void MainWindow::testAddSite()
{
    ui->tabSites->addTab(new FormSite(), QString("Tab %0").arg(ui->tabSites->count() + 1));
}

