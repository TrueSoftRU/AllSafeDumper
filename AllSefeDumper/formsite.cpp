#include "formsite.h"
#include "ui_formsite.h"

FormSite::FormSite(QWidget *parent, QString nameSite, QString url, QString data, QString searchParametrs, bool noCast, bool command, bool tor, bool hex, bool riskLvl, bool win) :
    QWidget(parent),
    ui(new Ui::FormSite)
{
    ui->setupUi(this);
    _nameSite = nameSite;
    _url = url;
    _data = data;
    _searchParametrs = searchParametrs;
    _noCast = noCast;
    _command = command;
    _tor = tor;
    _hex = hex;
    _riskLvl = riskLvl;
    _win = win;


    ui->lineEdit_searchParametrs->setText(_searchParametrs);
    ui->lineEdit_url->setText(_url);
    ui->lineEdit_data->setText(_data);
    ui->checkBox_noCast->setChecked(_noCast);
    ui->checkBox_Command->setChecked(_command);
    ui->checkBox_Tor->setChecked(_tor);
    ui->checkBox_Hex->setChecked(_hex);
    ui->checkBox_RiskLvL->setChecked(_riskLvl);
    ui->checkBox_Win->setChecked(_win);

    ui->labelState->setStyleSheet("QLabel {color : red; }");

    connect(ui->pushButton_StartStop, &QPushButton::clicked, this, &FormSite::togleState);
    connect(this, &FormSite::togleState, this, &FormSite::siteState);
    connect(this, &FormSite::readSite, this, &FormSite::getParametrsSite);
}

FormSite::~FormSite()
{
    delete ui;
}


void FormSite::siteState()
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

QStringList FormSite::getParametrsSite()
{
    QStringList parametrs = {_nameSite, _url, _data, QString::number(_noCast), QString::number(_command), QString::number(_tor), QString::number(_hex), QString::number(_riskLvl), QString::number(_win), _searchParametrs};
    return parametrs;
}
