/*
Copyright (c) 2018 InversePalindrome
DossierLayout - LoginDialog.cpp
InversePalindrome.com
*/


#include "LoginDialog.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QToolButton>


LoginDialog::LoginDialog(QWidget* parent) :
    QDialog(parent)
{
    auto* layout = new QVBoxLayout(this);

    auto* logoLabel = new QLabel(this);

    QPixmap logoPicture(":/Resources/DossierLayoutIcon.png");
    logoPicture = logoPicture.scaledToHeight(250);

    logoLabel->setPixmap(logoPicture);

    auto* userEntry = new QLineEdit(this);

    auto* passwordEntry = new QLineEdit(this);
    passwordEntry->setEchoMode(QLineEdit::Password);

    auto* formLayout = new QFormLayout();
    formLayout->addRow(tr("Username:"), userEntry);
    formLayout->addRow(tr("Password:"), passwordEntry);

    auto* loginButton = new QPushButton(tr("Login"), this);
    auto* registerButton = new QPushButton(tr("Register"), this);
    auto* settingsButton = new QToolButton(this);
    settingsButton->setIcon(QIcon(":/Resources/Settings.png"));

    auto* layoutButton = new QHBoxLayout();
    layoutButton->addWidget(loginButton);
    layoutButton->addWidget(registerButton);
    layoutButton->addWidget(settingsButton);

    layout->addSpacing(15);
    layout->addWidget(logoLabel, 0, Qt::AlignCenter);
    layout->addSpacing(15);
    layout->addLayout(formLayout);
    layout->addLayout(layoutButton);

    QObject::connect(loginButton, &QPushButton::clicked, [this, userEntry, passwordEntry]
    {
        emit loginUser(userEntry->text(), passwordEntry->text());
    });
    QObject::connect(registerButton, &QPushButton::clicked, [this]
    {
        emit registerUser();
    });
    QObject::connect(settingsButton, &QPushButton::clicked, [this]
    {
        emit openSettings();
    });
}