#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mywidget.h"
#include "vertex.h"
#include <qdebug.h>


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

void MainWindow::on_comboBox_2_activated(const QString &arg1) {
qDebug() << "Click on_comboBox_2_activated";

}

// załączenie dodawania wierzchołków i krawędzi
void MainWindow::on_rb_dodaj_clicked(bool checked)
{
    qDebug() << "Click";
    ui->ekran->koniec = false;
    ui->ekran->dodaj = true;
    ui->ekran->usun = false;
}

// załączenie usuwania wierzchołków i krawędzi
void MainWindow::on_rb_usun_clicked(bool checked)
{
    qDebug() << "Click";
    ui->ekran->koniec = false;
    ui->ekran->dodaj = false;
    ui->ekran->usun = true;


}

void MainWindow::on_rb_V_clicked(bool checked)
{
    qDebug() << "Click";
    ui->okno_skie_nieskie->setEnabled(false);
    ui->ekran->V = true;
    ui->ekran->E = false;



}

void MainWindow::on_rb_E_clicked(bool checked)
{
    qDebug() << "Click";
    ui->okno_skie_nieskie->setEnabled(true);
    ui->rb_skie->setChecked(true);
    ui->ekran->E = true;
    ui->ekran->V = false;
    ui->rb_skie->click();


}

void MainWindow::on_b_koniec_clicked()
{
    //zablohowanie edycji grafu
    qDebug() << "Click";
    ui->okno_add_del->setEnabled(false);
    ui->okno_V_E->setEnabled(false);
    ui->okno_skie_nieskie->setEnabled(false);
    ui->ekran->koniec = true;
    ui->ekran->update_mp();
    ui->ekran->update_mi();
    ui->MP->setText(ui->ekran->print_macierz_przyleglosci());
    ui->MI->setText(ui->ekran->print_macierz_incydencji());
    ui->comboBox->clear();
    ui->comboBox->addItems(ui->ekran->combo());
}

void MainWindow::on_b_edytuj_clicked()
{
    //edycja grafu
    qDebug() << "Click";
    ui->okno_add_del->setEnabled(true);
    ui->okno_V_E->setEnabled(true);
    ui->okno_skie_nieskie->setEnabled(true);
    ui->ekran->koniec = false;
}

void MainWindow::on_b_clean_clicked()
{
    //wyczyść graf
    ui->ekran->wierzcholki.clear();
    ui->ekran->krawedzie.clear();
    ui->ekran->repaint();
    ui->ekran->update_mp();
    ui->ekran->update_mi();
    ui->MP->setText(ui->ekran->print_macierz_przyleglosci());
    ui->MI->setText(ui->ekran->print_macierz_incydencji());
}

void MainWindow::on_rb_skie_clicked(bool checked)
{
    ui->ekran->skierowana = true;
    ui->ekran->nieskierowana = false;
}

void MainWindow::on_rb_nieskie_clicked(bool checked)
{
    ui->ekran->nieskierowana = true;
    ui->ekran->skierowana = false;
}



