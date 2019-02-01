#ifndef PLUGIN2_H
#define PLUGIN2_H

#include <QVector>
#include <QWidget>

#include "../main/Interface.h"

class Plugin2: public QWidget, public Interface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Interface_iid")
    Q_INTERFACES(Interface)
public:
    Plugin2();
    int getID(void);
    void display(int, QBoxLayout*);
    QWidget *getWidget(int);
    void setConnection(QObject*);

private:
    QBoxLayout *m_layout;
    QWidget *m_numTopW;
    QWidget *m_numBottomW;
};

#endif // PLUGIN2_H
