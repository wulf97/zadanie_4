#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>

#include "Calc.h"

class Manager : public QWidget {
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

    QWidget *getWidgets(void);
};

#endif // MANAGER_H
