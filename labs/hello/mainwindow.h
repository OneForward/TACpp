#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_x1_valueChanged(int arg1);

    void on_x2_valueChanged(int arg1);

    void on_reset_clicked();

    void on_about_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
