#include "NumBottomWidget.h"
#include "ui_NumBottomWidget.h"

NumBottomWidget::NumBottomWidget(QWidget *parent) : QWidget(parent), ui(new Ui::NumBottomWidget) {
    ui->setupUi(this);
}

NumBottomWidget::~NumBottomWidget() {
    delete ui;
}
