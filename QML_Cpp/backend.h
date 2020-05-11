#if !defined(BACKEND_H)
#define BACKEND_H

#include <QObject>
#include <QString>

class BackEnd : public QObject {
private:
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString prevUserName READ prevUserName)

public:
    BackEnd(QObject *parent = nullptr);

    QString userName();
    QString prevUserName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
    QString m_prevUserName;
};

#endif  // BACKEND_H
