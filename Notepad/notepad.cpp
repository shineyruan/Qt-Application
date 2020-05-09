#include "notepad.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Notepad) {
    ui->setupUi(this);
    textChanged = false;
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

    textChanged = false;
}

void Notepad::on_actionSave_As_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    currentFileName = fileName;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();

    textChanged = false;
}

void Notepad::on_actionNew_triggered() {
    currentFileName.clear();
    if (!ui->textEdit->toPlainText().isEmpty()) {
        // if there is no text, no need to trigger text change
        // by resetting with an empty string
        ui->textEdit->setText(QString());
    }
    setWindowTitle("Notepad");
}

void Notepad::on_textEdit_textChanged() {
    if (!textChanged) {
        textChanged = true;
        setWindowTitle(windowTitle().append("*"));
    }
}
