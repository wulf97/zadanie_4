#ifndef PLUGIN1_H
#define PLUGIN1_H

#include <QVector>
#include <QWidget>

#include "../main/Interface.h"

class Plugin1: public QWidget, public Interface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Interface_id")
    Q_INTERFACES(Interface)
public:
    Plugin1();
    int getID(void);
    void display(int, QBoxLayout*);
    QWidget *getWidget(int);
    void setConnection(QObject*);

private:
    QWidget *m_valW;
    QWidget *m_operationsW;
    QWidget *m_equW;
};

#endif // PLUGIN1_H
