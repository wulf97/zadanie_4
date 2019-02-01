#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Manager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    Manager *manager = new Manager(this);
    ui->setupUi(this);

    ui->mainLayout->addWidget(manager->getWidgets());
}

MainWindow::~MainWindow() {
    delete ui;
}
