#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color: #333138;");
    this->ui_definitions();
    this->setCallbacks();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCallbacks() {
    connect(ui->cameraButton, &QPushButton::clicked, this, &MainWindow::on_camera_btn_clicked);
    connect(ui->colorButton, &QPushButton::clicked, this, &MainWindow::on_select_colors_btn_clicked);
    connect(ui->AddNewColorButton, &QPushButton::clicked, this, &MainWindow::on_add_new_color_btn_clicked);
}

void MainWindow::ui_definitions() {
    ui->selectColorsFrame->hide();
}

void MainWindow::on_camera_btn_clicked() {

}

void MainWindow::on_select_colors_btn_clicked() {
    ui->selectColorsFrame->show();
}

void MainWindow::on_add_new_color_btn_clicked() {
    AddNewColor newColorDialog(this);
    connect(&newColorDialog, &AddNewColor::cancelButtonPressed, this, &MainWindow::on_cancel_new_color);
    connect(&newColorDialog, &AddNewColor::confirmedButtonPressed, this, &MainWindow::on_confirm_new_color);
    newColorDialog.setWindowTitle("Nova cor");
    newColorDialog.exec();
}

void MainWindow::on_cancel_new_color() {

}

void MainWindow::on_confirm_new_color() {

}
