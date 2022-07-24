#ifndef FORMSITE_H
#define FORMSITE_H

#include <QWidget>

namespace Ui {
class FormSite;
}

class FormSite : public QWidget
{
    Q_OBJECT

public:
    explicit FormSite(QWidget *parent = nullptr, QString nameSite = "", QString url = "", QString searchParametrs = "", bool noCast = false, bool command= false, bool tor = false, bool hex = false, bool riskLvl = false, bool win = false);
    ~FormSite();
    bool State = false;

signals:
    void TogleState();

public slots:
    void buttonStartStop();
    void SiteState();

private:
    Ui::FormSite *ui;
    QString _nameSite;
    QString _url;
    QString _searchParametrs;
    bool _noCast;
    bool _command;
    bool _tor;
    bool _hex;
    bool _riskLvl;
    bool _win;

    QString textState;
};

#endif // FORMSITE_H
