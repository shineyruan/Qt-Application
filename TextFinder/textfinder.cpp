#include "textfinder.h"

#include <QFile>
#include <QTextStream>
#include <fstream>

#include "ui_textfinder.h"

TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent), ui(new Ui::TextFinder) {
    ui->setupUi(this);
    loadText();
}

TextFinder::~TextFinder() {
    delete ui;
}

void TextFinder::on_findButton_clicked() {
    QString searchStr = ui->lineEdit->text();
    ui->textEdit->find(searchStr, QTextDocument::FindWholeWords);
}

void TextFinder::loadText() {
    QFile input_file(":/input.txt");
    input_file.open(QIODevice::ReadOnly);

    QTextStream in(&input_file);
    QString line = in.readAll();
    input_file.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
