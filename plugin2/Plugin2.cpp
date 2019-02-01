#include <QBoxLayout>
#include <QPushButton>
#include <QString>
#include <QDebug>

#include "Plugin2.h"
#include "NumTopWidget.h"
#include "NumBottomWidget.h"

Plugin2::Plugin2() {
    m_layout = new QVBoxLayout();
    m_numTopW = new NumTopWidget(this);
    m_numBottomW = new NumBottomWidget(this);

    m_layout->addWidget(m_numTopW);
    m_layout->addWidget(m_numBottomW);
}

int Plugin2::getID(void) {
    return 2;
}

void Plugin2::display(int i, QBoxLayout *layout) {
    if (i == NUM_WIDGET) {
        layout->addLayout(m_layout);
    }
}

QWidget *Plugin2::getWidget(int i) {
    switch (i) {
    case NUM_TOP_WIDGET:
        return m_numTopW;
    break;
    case NUM_BOTTOM_WIDGET:
        return m_numBottomW;
    break;
    default:
        return nullptr;
    }
}

void Plugin2::setConnection(QObject *obj) {
    QPushButton *numButtons[10];
    QString buttonName;

    /* Присоединение слотов */
    for (int i = 0; i < 4; ++i) {
        buttonName = "button" + QString::number(i);
        /* Добавление кнопки в массив по их имени */
        numButtons[i] = m_numBottomW->findChild<QPushButton*>(buttonName);
        /* Обработка нажатия одной из кнопок */
        connect(numButtons[i], SIGNAL(released()), obj, SLOT(calculate()));
    }

    for (int i = 4; i < 10; ++i) {
        buttonName = "button" + QString::number(i);
        /* Добавление кнопки в массив по их имени */
        numButtons[i] = m_numTopW->findChild<QPushButton*>(buttonName);
        /* Обработка нажатия одной из кнопок */
        connect(numButtons[i], SIGNAL(released()), obj, SLOT(calculate()));
    }
}
