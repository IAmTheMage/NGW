#include "addnewcolor.h"
#include "ui_addnewcolor.h"
#include "QString"

AddNewColor::AddNewColor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewColor)
{
    ui->setupUi(this);
    connect(ui->cancelButton, &QPushButton::clicked, this, &AddNewColor::cancelButtonPressed);
    connect(ui->cancelButton, &QPushButton::clicked, this, &AddNewColor::on_cancel_button_pressed);
    connect(ui->confirmButton, &QPushButton::clicked, this, &AddNewColor::on_confirm_button_pressed);
    connect(ui->confirmButton, &QPushButton::clicked, this, &AddNewColor::confirmedButtonPressed);
}

AddNewColor::~AddNewColor()
{
    delete ui;
}

void AddNewColor::on_cancel_button_pressed(){
    this->hide();
}

void AddNewColor::on_confirm_button_pressed() {
    std::cout << "HELLO" << std::endl;
    QString colorName = ui->colorName->text();
    std::ifstream f("../NGW/colors.json");
    json colors_config = json::parse(f);
    f.close();
    json newColor = {
            { "name", colorName.toStdString() },
            { "data", json::array() } // Utilize json::array() para criar um array vazio
        };
    colors_config["colors"].push_back(newColor);
    std::ofstream updateFile("../NGW/colors.json");
    updateFile << colors_config.dump(4);
    // Fechar o arquivo
    updateFile.close();
    this->hide();
}
