#include "notepad.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Notepad) {
    ui->setupUi(this);
}

Notepad::~Notepad() {
    delete ui;
}

void Notepad::on_actionOpen_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file...");
    QFile file(fileName);
    currentFileName = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void Notepad::on_actionSave_triggered() {
    QString fileName;
    if (currentFileName.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFileName = fileName;
    } else {
        fileName = currentFileName;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}
