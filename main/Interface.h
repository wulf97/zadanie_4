#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtPlugin>


enum {
    TOP_WIDGET,
    VAL_WIDGET,
    OPERATIONS_WIDGET,
    EQU_WIDGET,
    NUM_WIDGET,
    NUM_TOP_WIDGET,
    NUM_BOTTOM_WIDGET
};

class QObject;
class QWidget;
class QBoxLayout;

class Interface {
public:
    ~Interface() {}
    virtual int getID(void) = 0;
    virtual void display(int, QBoxLayout*) = 0;
    virtual QWidget *getWidget(int) = 0;
    virtual void setConnection(QObject*) = 0;
};

#define Interface_iid "Interface_iid"

Q_DECLARE_INTERFACE(Interface, Interface_iid)

#endif // INTERFACE_H
