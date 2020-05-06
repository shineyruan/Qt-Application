#include "notepad.h"

#include <QFile>
#include <QTextStream>
#include <fstream>

#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QWidget(parent), ui(new Ui::Notepad) {
    ui->setupUi(this);
    loadText();
}

Notepad::~Notepad() {
    delete ui;
}

void Notepad::on_findButton_clicked() {
    QString searchStr = ui->lineEdit->text();
    ui->textEdit->find(searchStr, QTextDocument::FindWholeWords);
}

void Notepad::loadText() {
    QFile input_file(":/input.txt");
    input_file.open(QIODevice::ReadOnly);

    QTextStream in(&input_file);
    QString line = in.readAll();
    input_file.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
