#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include "connection.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString categorie=ui->line_categorie->text();
    QString contenu=ui->line_contenu->text();
    QDate d=ui->date->date();
    QString mail=ui->line_mail->text();



    Reclamation R(1,categorie,"just added",contenu,d,mail,1);

    bool test=R.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->tableView->setModel(rmp.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    bool i;
    int id_del;
    id_del=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();

    i=rmp.supprimer(id_del);
    if(i)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }

}

void MainWindow::on_pushButton_4_clicked()
{
    int id_upt=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
    QString categorie=ui->line_categorie->text();
    QString contenu=ui->line_contenu->text();
    QString etat=ui->line_etat->text();
    QDate d=ui->date->date();
    QString mail=ui->line_mail->text();
    int id_j=ui->line_idj->text().toInt();
    Reclamation R(id_upt,categorie,etat,contenu,d,mail,id_j);



    bool test=R.modifier(id_upt);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }
}
