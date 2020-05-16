#include "processor.h"

Processor::Processor(QObject *parent) : QObject(parent) {}

QImage Processor::getImage() {
    return image;
}

void Processor::setImage(QVariant var) {
    image = qvariant_cast<QImage>(var);
    emit imageChanged();
}
