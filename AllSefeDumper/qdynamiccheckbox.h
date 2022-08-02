#ifndef QDYNAMICCHECKBOX_H
#define QDYNAMICCHECKBOX_H

#include <QWidget>

#include <QCheckBox>

class QDynamicCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    explicit QDynamicCheckBox(QWidget *parent = nullptr, QString text = "");

signals:
    void onTogleGetText(QString textCheckBox);
    void togleCheckAll();

};

#endif // QDYNAMICCHECKBOX_H
