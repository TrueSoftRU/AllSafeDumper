#include "qdynamiccheckbox.h"

QDynamicCheckBox::QDynamicCheckBox(QWidget *parent, QString text)
    : QCheckBox{parent}
{
    this->setText(text);

    QObject::connect(this, &QCheckBox::toggled, [this](){
       emit onTogleGetText(this->text());
    });

    QObject::connect(this, &QDynamicCheckBox::togleCheckAll, [this](){
        this->toggle();
    });
}

