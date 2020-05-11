#include "backend.h"

BackEnd::BackEnd(QObject *parent) : QObject(parent) {}

QString BackEnd::userName() {
    return m_userName;
}

QString BackEnd::prevUserName() {
    return m_prevUserName;
}

void BackEnd::setUserName(const QString &userName) {
    m_prevUserName = m_userName;

    if (userName == m_userName) {
        return;
    }

    m_userName = userName;
    emit userNameChanged();
}