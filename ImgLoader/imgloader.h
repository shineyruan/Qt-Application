#ifndef _IMGLOADER_H
#define _IMGLOADER_H

#include <QFile>
#include <QObject>
#include <QString>

class ImageLoader : public QObject {
private:
    Q_OBJECT
    Q_PROPERTY(QString imageURL READ getImageURL WRITE setImageUrl NOTIFY imageChanged)

public:
    ImageLoader(QObject *parent = nullptr);
    QString getImageUrl();
    void setImageUrl(const QString &url);

signals:
    void imageChanged();

private:
    QString imageURL;
};

#endif  // _IMGLOADER_H
