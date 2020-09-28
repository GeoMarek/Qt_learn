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
    void on_button_line_clicked();

    void update_ui();

    void on_spin_scale_valueChanged(double scale);
    void on_spin_interval_valueChanged(double interval);
    void on_spin_step_count_valueChanged(int count);

    void on_button_background_clicked();

    void on_button_line_color_clicked();

    void on_button_circle_clicked();

    void on_button_ellipse_clicked();

    void on_button_fancy_clicked();

    void on_button_starfish_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
