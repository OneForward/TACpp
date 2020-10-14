#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_x1_valueChanged(int val)
{
    ui->y->setText(QString::number(ui->x2->value() + val));
}

void MainWindow::on_x2_valueChanged(int val)
{
    ui->y->setText(QString::number(ui->x1->value() + val));
}

void MainWindow::on_reset_clicked()
{
    ui->x1->setValue(0);
    ui->x2->setValue(0);
}

void MainWindow::on_about_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Hello Qt!");
    msgBox.exec();
}
