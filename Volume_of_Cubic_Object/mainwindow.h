#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    double x_value, y_value, z_value; //tank sizes
    double current_z_value;
    double current_litre_price;

    double volume;
    double volume_for_z_value;
    double litre_to_fill;
    double price_for_fill;

    void calcValues();
};

#endif // MAINWINDOW_H
