#include "formsite.h"
#include "ui_formsite.h"

FormSite::FormSite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSite)
{
    ui->setupUi(this);
}

FormSite::~FormSite()
{
    delete ui;
}
