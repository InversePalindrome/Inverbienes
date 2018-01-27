/*
Copyright (c) 2018 InversePalindrome
DossierTable - LoginDialog.hpp
InversePalindrome.com
*/


#pragma once

#include <QDialog>
#include <QString>
#include <QLineEdit>


class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget* parent);

private:
    QLineEdit* userEntry;
    QLineEdit* passwordEntry;

    virtual void closeEvent(QCloseEvent* event) override;

signals:
    void registerUser();
    void loginUser(const QString& user, const QString& password);
};
