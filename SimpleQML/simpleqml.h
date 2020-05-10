#ifndef SIMPLEQML_H
#define SIMPLEQML_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class SimpleQML;
}
QT_END_NAMESPACE

class SimpleQML : public QMainWindow {
    Q_OBJECT

public:
    SimpleQML(QWidget *parent = nullptr);
    ~SimpleQML();

private:
    Ui::SimpleQML *ui;
};
#endif  // SIMPLEQML_H
