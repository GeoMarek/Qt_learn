#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_astroid_clicked()
{
    this->ui->render_area->setShape(RenderArea::ShapeType::Astroid);
    //this->ui->render_area->setBackgroundColor(Qt::red);
    this->ui->render_area->repaint();
    update_ui();
}

void MainWindow::on_button_cycloid_clicked()
{
    this->ui->render_area->setShape(RenderArea::ShapeType::Cycloid);
    //this->ui->render_area->setBackgroundColor(Qt::green);
    this->ui->render_area->repaint();
    update_ui();
}

void MainWindow::on_button_huygens_cycloid_clicked()
{
    this->ui->render_area->setShape(RenderArea::ShapeType::HuygensCyclodid);
    //this->ui->render_area->setBackgroundColor(Qt::blue);
    this->ui->render_area->repaint();
    update_ui();
}

void MainWindow::on_button_hypo_cycloid_clicked()
{
    this->ui->render_area->setShape(RenderArea::ShapeType::HypoCycloid);
    this->ui->render_area->repaint();
    update_ui();
}

void MainWindow::on_button_line_clicked()
{
    this->ui->render_area->setShape(RenderArea::ShapeType::Line);
    this->ui->render_area->repaint();
    update_ui();
}

void MainWindow::on_spin_scale_valueChanged(double scale)
{
    this->ui->render_area->setScale(scale);
}

void MainWindow::update_ui()
{
    this->ui->spin_scale->setValue(this->ui->render_area->getScale());
    this->ui->spin_interval->setValue(this->ui->render_area->getInterval());
    this->ui->spin_step_count->setValue(this->ui->render_area->getStepCount());
}

void MainWindow::on_spin_interval_valueChanged(double interval)
{
    this->ui->render_area->setInterval(interval);
}

void MainWindow::on_spin_step_count_valueChanged(int count)
{
    this->ui->render_area->setStepCount(count);
}

void MainWindow::on_button_background_clicked()
{
    auto actual_color =  this->ui->render_area->getBackgroundColor();
    QColor color = QColorDialog::getColor(actual_color, this, "Select color");
    ui->render_area->setBackgroundColor(color);
}

void MainWindow::on_button_line_color_clicked()
{
    auto actual_color =  this->ui->render_area->getShapeColor();
    QColor color = QColorDialog::getColor(actual_color, this, "Select color");
    ui->render_area->setShapeColor(color);
}
