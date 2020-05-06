#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Notepad;
}
QT_END_NAMESPACE

class Notepad : public QWidget {
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void on_findButton_clicked();

private:
    Ui::Notepad *ui;
    void loadText();
};
#endif  // NOTEPAD_H
