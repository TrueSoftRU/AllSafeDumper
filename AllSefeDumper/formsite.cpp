#include "formsite.h"
#include "ui_formsite.h"

FormSite::FormSite(QWidget *parent, QString nameSite, QString url, QString searchParametrs, bool noCast, bool command, bool tor, bool hex, bool riskLvl, bool win) :
    QWidget(parent),
    ui(new Ui::FormSite)
{
    ui->setupUi(this);
    _nameSite = nameSite;
    _url = url;
    _searchParametrs = searchParametrs;
    _noCast = noCast;
    _command = command;
    _tor = tor;
    _hex = hex;
    _riskLvl = riskLvl;
    _win = win;

    ui->lineEdit_searchParametrs->setText(_searchParametrs);
    ui->lineEdit_url->setText(_url);
    ui->checkBox_noCast->setChecked(_noCast);
    ui->checkBox_Command->setChecked(_command);
    ui->checkBox_Tor->setChecked(_tor);
    ui->checkBox_Hex->setChecked(_hex);
    ui->checkBox_RiskLvL->setChecked(_riskLvl);
    ui->checkBox_Win->setChecked(_win);

    ui->labelState->setStyleSheet("QLabel {color : red; }");

    connect(ui->pushButton_StartStop, &QPushButton::clicked, this, &FormSite::buttonStartStop);
    connect(this, &FormSite::TogleState, this, &FormSite::SiteState);
}

FormSite::~FormSite()
{
    delete ui;
}

void FormSite::buttonStartStop()
{
    emit FormSite::TogleState();
}

void FormSite::SiteState()
{
    State = !State;


    if(State){
        ui->labelState->setText("Состояние: Включён");
        ui->pushButton_StartStop->setText("Стоп");
        ui->labelState->setStyleSheet("QLabel {color : green; }");
    }else{
        ui->labelState->setText("Состояние: Выключён");
        ui->pushButton_StartStop->setText("Старт");
        ui->labelState->setStyleSheet("QLabel {color : red; }");
    }


    //TODO::CODE RUN DUMPING
}
