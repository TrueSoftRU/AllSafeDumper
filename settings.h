#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);

signals:
    void saveSettings(bool TabsClosable);

public slots:
    bool loadTabsClosable();
private slots:
    void saveTabsClosable(bool check);

private:
    QSettings *settings;
};

#endif // SETTINGS_H
