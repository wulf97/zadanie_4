#include "EquWidget.h"
#include "ui_EquWidget.h"

EquWidget::EquWidget(QWidget *parent) : QWidget(parent), ui(new Ui::EquWidget) {
    ui->setupUi(this);
}

EquWidget::~EquWidget() {
    delete ui;
}
