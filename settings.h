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
    void saveSettings(bool TabsClosable, bool AutoLog);

public slots:
    bool loadTabsClosable();
    bool loadAutoLog();

private slots:
    void saveTabsClosable(bool check);
    void saveAutoLog(bool check);

private:
    QSettings *settings;
};

#endif // SETTINGS_H
