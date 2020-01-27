#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calcValues();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcValues() {

    //Calculate values
    x_value = ui->X_Axis_Spinbox->value();
    y_value = ui->Y_Axis_Spinbox->value();
    z_value = ui->Z_Axis_Spinbox->value();
    current_z_value = ui->currZVal->value();
    current_litre_price = ui->litrePrice->value();

    volume = x_value * y_value * z_value * 1000;
    volume_for_z_value = x_value * y_value * current_z_value * 1000;
    litre_to_fill = volume - volume_for_z_value;
    price_for_fill = litre_to_fill * current_litre_price;

    //Change fonts
    ui->VolumeValue->setStyleSheet("QLabel {color: red;}");
    ui->CurrLitreValue->setStyleSheet("QLabel {color: red;}");
    ui->LitreValue->setStyleSheet("QLabel {color: red;}");
    ui->PriceValue->setStyleSheet("QLabel {color: red;}");

    //Write Output
    ui->VolumeValue->setText(QString::number(volume) + " Litre");
    ui->CurrLitreValue->setText(QString::number(volume_for_z_value) + " Litre");
    ui->LitreValue->setText(QString::number(litre_to_fill) + " Litre");
    ui->PriceValue->setText(QString::number(price_for_fill));
}

void MainWindow::on_pushButton_clicked()
{
    calcValues();
}
