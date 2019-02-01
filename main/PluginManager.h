#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QVector>

class QObject;

class PluginManager {
public:
    PluginManager();

    QObject *operator [](int);

    void load(void);
    bool isLoad(void);
    int size(void);
    QObject *get(int);
    QObject *getPlugin1(void);
    QObject *getPlugin2(void);

private:
    QVector<QObject*> *m_plugins;
};

#endif // PLUGINMANAGER_H
