#include "ValWidget.h"
#include "ui_ValWidget.h"

ValWidget::ValWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ValWidget) {
    ui->setupUi(this);
}

ValWidget::~ValWidget() {
    delete ui;
}
