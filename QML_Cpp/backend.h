#if !defined(BACKEND_H)
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QVector>

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
    QVector<QString> m_prevUserNames;
    int n_prevUserName;
};

#endif  // BACKEND_H
