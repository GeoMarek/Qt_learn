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
    void on_button_astroid_clicked();

    void on_button_cycloid_clicked();

    void on_button_huygens_cycloid_clicked();

    void on_button_hypo_cycloid_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
