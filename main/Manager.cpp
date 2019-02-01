#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QStyle>
#include <QDebug>

#include "Manager.h"
#include "PluginManager.h"
#include "Interface.h"

Manager::Manager(QWidget *parent) : QWidget(parent) {

}

QWidget *Manager::getWidgets(void) {
    PluginManager plManager;

    Calc *calc = new Calc(this); // Экземпляр обработчика

    /* Компановка виджета */
    QVBoxLayout *combLayout = new QVBoxLayout(); // Главный лэйаут для компановки виджета
    QVBoxLayout *topLayout = new QVBoxLayout();
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    QHBoxLayout *numLayout = new QHBoxLayout();
    QHBoxLayout *equLayout = new QHBoxLayout();

    QWidget *combWidget = new QWidget(this); // Виджет, в котором происходит компановка других виджетов

    bottomLayout->addLayout(numLayout);
    bottomLayout->addLayout(equLayout);

    combLayout->addLayout(topLayout);
    combLayout->addLayout(bottomLayout);
    combWidget->setLayout(combLayout);

    /* Загрузка плагинов */
    plManager.load();
    if (plManager.size() < 2) {
        QMessageBox msg(this);
        msg.setText("Can not load all plugins!!!");
        msg.exec();
    }

    for (int i = 0; i < plManager.size(); i++) {
        QObject *plugin = plManager[i];
        Interface *interface = qobject_cast<Interface*>(plugin);

        if (interface->getID() == 1) {
            QWidget *valW = interface->getWidget(VAL_WIDGET);
            interface->display(TOP_WIDGET, topLayout);
            interface->display(EQU_WIDGET, equLayout);
            calc->setDispaly(valW->findChild<QLineEdit*>("lineEdit")); // Добавление строки вывода
        } else if (interface->getID() == 2) {
            interface->display(NUM_WIDGET, numLayout);
        }

        if (plManager.size() == 2) {
            interface->setConnection(calc);
        }
    }


    return combWidget;
}

Manager::~Manager() {

}


