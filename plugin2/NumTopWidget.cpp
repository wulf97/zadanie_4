#include "NumTopWidget.h"
#include "ui_NumTopWidget.h"

NumTopWidget::NumTopWidget(QWidget *parent) : QWidget(parent), ui(new Ui::NumTopWidget) {
    ui->setupUi(this);
}

NumTopWidget::~NumTopWidget() {
    delete ui;
}
