#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include <QDebug>
#include <QImage>
#include <QObject>
#include <QString>
#include <QUrl>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickImageProvider>

class Processor : public QObject {
private:
    Q_OBJECT
    Q_PROPERTY(QImage image READ getImage NOTIFY imageChanged)

public:
    Processor(QObject* parent = nullptr);

    QImage getImage();
    void setImage(const QImage& srcimg);

    /**********************************************
     * REGISTERED (EXPOSED) CLASS MEMBER FUNCTION *
     **********************************************/

    Q_INVOKABLE void saveImage(const QUrl& imageProviderUrl);

signals:
    void imageChanged();

private:
    QImage image;
};

#endif  // _PROCESSOR_H
