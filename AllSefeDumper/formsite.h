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
    explicit FormSite(QWidget *parent = nullptr);
    ~FormSite();

private:
    Ui::FormSite *ui;
};

#endif // FORMSITE_H
