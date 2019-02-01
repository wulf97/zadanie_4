#include "OperationsWidget.h"
#include "ui_OperationsWidget.h"

OperationsWidget::OperationsWidget(QWidget *parent) : QWidget(parent), ui(new Ui::OperationsWidget) {
    ui->setupUi(this);
}

OperationsWidget::~OperationsWidget() {
    delete ui;
}
