#ifndef _LOADER_H
#define _LOADER_H

#include <sys/types.h>

#include <QtCore/QObject>
#include <QtCore/QPoint>
#include <QtCore/QString>
#include <QtCore/QUrl>
#include <QtGui/QImage>

class ImgLoader : public QObject {
private:
    Q_OBJECT

public:
    ImgLoader(QObject* parent = nullptr);

    /***************************
     * QML INVOKABLE FUNCTIONS *
     ***************************/

    Q_INVOKABLE void loadImage(const QUrl& imageUrl);
    Q_INVOKABLE void setMousePos(const int& x, const int& y);

private:
    QImage img_;
    QPoint mousePos_;
};

#endif  // _LOADER_H
