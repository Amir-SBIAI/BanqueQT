#include "window.h"
#include <QMessageBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    // id
    QLabel *idLabel = new QLabel(tr("Identifiant:"));
    idLineEdit = new QLineEdit;
    idLineEdit->setPlaceholderText("Entrer votre identifiant");

    // mdp
    QLabel *passwordLabel = new QLabel(tr("Mot de passe:"));
    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setPlaceholderText("Entrer votre mot de passe");

    // case afficher/masquer
    showIDCheckBox = new QCheckBox(tr("Afficher l'identifiant"));
    connect(showIDCheckBox, &QCheckBox::toggled, this, &Window::toggleIDField);

    // case afficher/masquer
    showPasswordCheckBox = new QCheckBox(tr("Afficher le mot de passe"));
    connect(showPasswordCheckBox, &QCheckBox::toggled, this, &Window::togglePasswordField);

    // bouton de connexion
    QPushButton *connectButton = new QPushButton(tr("Se connecter"));
    connect(connectButton, &QPushButton::clicked, this, &Window::onConnectButtonClicked);


    // Layout principal
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(idLabel, 0, 0);
    layout->addWidget(idLineEdit, 0, 1);
    layout->addWidget(showIDCheckBox, 0, 2);
    layout->addWidget(passwordLabel, 1, 0);
    layout->addWidget(passwordLineEdit, 1, 1);
    layout->addWidget(showPasswordCheckBox, 1, 2);
    layout->addWidget(connectButton, 2, 1);

    setLayout(layout);
    setWindowTitle(tr("COMPTE EN BANQUE"));
}

void Window::toggleIDField(bool checked)
{
    idLineEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::PasswordEchoOnEdit);
}

void Window::togglePasswordField(bool checked)
{
    passwordLineEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
}


void Window::onConnectButtonClicked()
{
    QString id = idLineEdit->text();
    QString password = passwordLineEdit->text();

    // Vérification des identifiants
    if (id == "Amir" && password == "1234") {
        QWidget *newWindow = new QWidget;
        newWindow->setWindowTitle("MENU DU COMPTE");
        newWindow->resize(400, 300);
        // Créer un layout pour la nouvelle fenêtre
        QVBoxLayout *layout = new QVBoxLayout;


        QPushButton *CrediterButton = new QPushButton(tr("Crediter"));
        QPushButton *DebiterButton = new QPushButton(tr("Debiter"));
        QPushButton *TransfertButton = new QPushButton(tr("Transfert"));
        QPushButton *InfosButton = new QPushButton(tr("Afficher Infos"));
        QPushButton *quitButton = new QPushButton(tr("Quitter"));

        // Ajouter les boutons au layout vertical
        layout->addWidget(CrediterButton);
        layout->addWidget(DebiterButton);
        layout->addWidget(TransfertButton);
        layout->addWidget(InfosButton);
        layout->addWidget(quitButton);



        // pr fermer la fenetre ( QUITTER )
        connect(quitButton, &QPushButton::clicked, newWindow, &QWidget::close);
        // pr ouvrir la page crediter
        connect(CrediterButton, &QPushButton::clicked, this, &Window::openCrediterPage);
        // pr ouvrir la page debiter
        connect(DebiterButton, &QPushButton::clicked, this, &Window::openDebiterPage);
        // pr ouvrir la page transfert
        connect(TransfertButton, &QPushButton::clicked, this, &Window::openTransfertPage);
        // pr ouvrir la page infos
        connect(InfosButton, &QPushButton::clicked, this, &Window::openInfosPage);

        // Appliquer le layout à la nouvelle fenêtre
        newWindow->setLayout(layout);

        newWindow->show();


    } else {
        QMessageBox::warning(this, tr("Erreur de connexion"), tr("Identifiants ou mot de passe incorrects."));
    }
}


void Window::openCrediterPage()
{
    // page créditer
    QWidget *creditWindow = new QWidget;
    creditWindow->setWindowTitle("CREDITER");
    creditWindow->resize(400, 300);
    creditWindow->show();
}

void Window::openDebiterPage()
{
    // page créditer
    QWidget *creditWindow = new QWidget;
    creditWindow->setWindowTitle("DEBITER");
    creditWindow->resize(400, 300);
    creditWindow->show();
}

void Window::openTransfertPage()
{
    // page créditer
    QWidget *creditWindow = new QWidget;
    creditWindow->setWindowTitle("TRANSFERT");
    creditWindow->resize(400, 300);
    creditWindow->show();
}

void Window::openInfosPage()
{
    // page créditer
    QWidget *creditWindow = new QWidget;
    creditWindow->setWindowTitle("INFORMATIONS");
    creditWindow->resize(400, 300);
    creditWindow->show();
}

