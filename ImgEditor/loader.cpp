#include "loader.h"

#include <QtCore/QDebug>

ImgLoader::ImgLoader(QObject* parent) : QObject(parent) {}

void ImgLoader::loadImage(const QUrl& imageUrl) {
    img_.load(imageUrl.path());
    qDebug() << "The image is loaded as: " << img_;
}

void ImgLoader::setMousePos(const int& x, const int& y) {
    mousePos_.setX(x);
    mousePos_.setY(y);
    qDebug() << "Mouse position has been set as: " << mousePos_;
}
