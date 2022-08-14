#include "settings.h"

Settings::Settings(QObject *parent)
    : QObject{parent}
{

    settings = new QSettings("settings", QSettings::IniFormat);

    QObject::connect(this, &Settings::saveSettings, this, [this](bool TabsClosable, bool AutoLog){
        saveTabsClosable(TabsClosable);
        saveAutoLog(AutoLog);
    });



    // emit loadSettings(tabsClosable);
}

bool Settings::loadTabsClosable()
{
    return settings->value("TabsClosable", false).toBool();
}

bool Settings::loadAutoLog()
{
    return settings->value("AutoLog", false).toBool();
}

void Settings::saveTabsClosable(bool check)
{
    settings->setValue("TabsClosable", check);
}

void Settings::saveAutoLog(bool check)
{
    settings->setValue("AutoLog", check);
}
