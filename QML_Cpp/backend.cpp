#include "backend.h"

BackEnd::BackEnd(QObject *parent) : QObject(parent), n_prevUserName(0) {}

QString BackEnd::userName() {
    return m_userName;
}

QString BackEnd::prevUserName() {
    if (n_prevUserName > 0)
        return m_prevUserNames[--n_prevUserName];
    else
        return "No more previous user names";
}

void BackEnd::setUserName(const QString &userName) {
    if (userName == m_userName || userName.isEmpty()) {
        return;
    }

    m_prevUserNames.push_back(m_userName);
    n_prevUserName = m_prevUserNames.length();

    m_userName = userName;
    emit userNameChanged();
}