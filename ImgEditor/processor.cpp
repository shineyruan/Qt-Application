#include "processor.h"

Processor::Processor(QObject* parent) : QObject(parent) {}

QImage Processor::getImage() {
    return image;
}

void Processor::setImage(const QImage& srcimg) {
    image = srcimg;
    emit imageChanged();
}

void Processor::saveImage(const QUrl& imageProviderUrl) {
    qDebug() << Q_FUNC_INFO << imageProviderUrl;
    QQmlEngine* engine = QQmlEngine::contextForObject(this)->engine();
    QQmlImageProviderBase* imageProviderBase = engine->imageProvider(imageProviderUrl.host());
    QQuickImageProvider* imageProvider = static_cast<QQuickImageProvider*>(imageProviderBase);
    QSize imageActualSize;
    QSize imageRequestedSize;
    QString imageId = imageProviderUrl.path().remove(0, 1);
    QImage img = imageProvider->requestImage(imageId, &imageActualSize, imageRequestedSize);
    qDebug() << Q_FUNC_INFO << imageId << imageActualSize;
    this->image = img;
}
