#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_astroid_clicked()
{
    this->ui->render_area->setBackgroundColor(Qt::red);
    this->ui->render_area->repaint();
}

void MainWindow::on_button_cycloid_clicked()
{
    this->ui->render_area->setBackgroundColor(Qt::green);
    this->ui->render_area->setShape(RenderArea::ShapeType::Cycloid);
    this->ui->render_area->repaint();
}

void MainWindow::on_button_huygens_cycloid_clicked()
{
    this->ui->render_area->setBackgroundColor(Qt::blue);
    this->ui->render_area->repaint();
}

void MainWindow::on_button_hypo_cycloid_clicked()
{
    this->ui->render_area->setBackgroundColor(Qt::yellow);
    this->ui->render_area->repaint();
}
