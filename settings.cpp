#include "settings.h"

Settings::Settings(QObject *parent)
    : QObject{parent}
{

    settings = new QSettings("settings", QSettings::IniFormat);

    QObject::connect(this, &Settings::saveSettings, this, [this](bool TabsClosable){
        saveTabsClosable(TabsClosable);
    });



    // emit loadSettings(tabsClosable);
}

bool Settings::loadTabsClosable()
{
     return settings->value("TabsClosable", false).toBool();
}

void Settings::saveTabsClosable(bool check)
{
    settings->setValue("TabsClosable", check);
}
