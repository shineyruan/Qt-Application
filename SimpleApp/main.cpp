#include <QApplication>
#include <QLabel>
#include <QtGui>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QLabel label("Hello World!");
    label.show();
    return app.exec();
}
