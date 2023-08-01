#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <QListView>
#include <QStringListModel>
#include <QStringList>
#include "QString"
#include <QListWidgetItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color: #333138;");



    std::ifstream f("../NGW/colors.json");
    QStringList qstrings;

    json colors_config = json::parse(f);
    f.close();
    for(auto data : colors_config["colors"]) {
        QString newItemText = QString::fromStdString(data["name"]);
        qstrings << newItemText;
    }
    QStringListModel* model = new QStringListModel(this);
    model->setStringList(qstrings);
    ui->ColorsList->setModel(model);
    ui->selectColorsFrame->show();

    QString styleSheet = R"(
            QListView {
                border: none;
                background: #333138;
                color: white;
                font-size: 16px;
                font-weight: bold;
            }

            QListView::item {
                margin-top: 15px;
            }

            QListView::item:selected {
                background-color: white;
                color: #333138;
            }
        )";

    ui->ColorsList->setStyleSheet(styleSheet);


    this->setCallbacks();
    this->ui_definitions();
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
    std::ifstream f("../NGW/colors.json");
    QStringList qstrings;

    json colors_config = json::parse(f);
    for(auto data : colors_config["colors"]) {
        QString newItemText = QString::fromStdString(data["name"]);
        qstrings << newItemText;
    }
    QStringListModel* model = new QStringListModel(this);
    model->setStringList(qstrings);
    ui->ColorsList->setModel(model);
    QString styleSheet = R"(
            QListView {
                border: none;
                background: #333138;
                color: white;
                font-size: 16px;
                font-weight: bold;
            }

            QListView::item {
                margin-top: 15px;
            }

            QListView::item:selected {
                background-color: white;
                color: #333138;
                margin-top: 15px;
                font-size: 16px;
                font-weight: bold;
            }
        )";

    ui->ColorsList->setStyleSheet(styleSheet);
    ui->selectColorsFrame->show();
}
