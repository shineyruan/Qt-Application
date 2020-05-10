#include "simpleqml.h"

#include "ui_simpleqml.h"

SimpleQML::SimpleQML(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SimpleQML) {
    ui->setupUi(this);
}

SimpleQML::~SimpleQML() {
    delete ui;
}
