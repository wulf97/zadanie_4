#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>

#include "Plugin1.h"
#include "ValWidget.h"
#include "OperationsWidget.h"
#include "EquWidget.h"

Plugin1::Plugin1() {
    m_valW = new ValWidget(this);
    m_operationsW = new OperationsWidget(this);
    m_equW = new EquWidget(this);
}

int Plugin1::getID(void) {
    return 1;
}

void Plugin1::display(int i, QBoxLayout *layout) {
    switch (i) {
        case TOP_WIDGET:
            layout->addWidget(m_valW);
            layout->addWidget(m_operationsW);
        break;
        case EQU_WIDGET:
            layout->addWidget(m_equW);
        break;
    }
}

QWidget *Plugin1::getWidget(int i) {
    switch (i) {
        case VAL_WIDGET:
            return m_valW;
        break;
        case OPERATIONS_WIDGET:
            return m_operationsW;
        break;
        case EQU_WIDGET:
            return m_equW;
        break;
        default:
            return nullptr;
    }
}

void Plugin1::setConnection(QObject *obj) {
    QPushButton *numButtons[10];
    QPushButton *buttonC;
    QPushButton *buttonPlus;
    QPushButton *buttonMinus;
    QPushButton *buttonMul;
    QPushButton *buttonDel;
    QPushButton *buttonEqu;

    buttonC = m_operationsW->findChild<QPushButton*>("buttonC");
    buttonPlus = m_operationsW->findChild<QPushButton*>("buttonPlus");
    buttonMinus = m_operationsW->findChild<QPushButton*>("buttonMinus");
    buttonMul = m_operationsW->findChild<QPushButton*>("buttonMul");
    buttonDel = m_operationsW->findChild<QPushButton*>("buttonDel");
    buttonEqu = m_equW->findChild<QPushButton*>("buttonEqu");

    connect(buttonC, SIGNAL(released()), obj, SLOT(calculate()));
    connect(buttonPlus, SIGNAL(released()), obj, SLOT(calculate()));
    connect(buttonMinus, SIGNAL(released()), obj, SLOT(calculate()));
    connect(buttonMul, SIGNAL(released()), obj, SLOT(calculate()));
    connect(buttonDel, SIGNAL(released()), obj, SLOT(calculate()));
    connect(buttonEqu, SIGNAL(released()), obj, SLOT(calculate()));
}
