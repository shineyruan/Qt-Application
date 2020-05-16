#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include <QImage>
#include <QObject>
#include <QString>
#include <QVariant>

class Processor : public QObject {
private:
    Q_OBJECT
    Q_PROPERTY(QImage image READ getImage NOTIFY imageChanged)

public:
    Processor(QObject *parent = nullptr);

    QImage getImage();
    void setImage(QVariant var);

signals:
    void imageChanged();

private:
    QImage image;
};

#endif  // _PROCESSOR_H
