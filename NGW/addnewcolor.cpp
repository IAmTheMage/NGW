#include "addnewcolor.h"
#include "ui_addnewcolor.h"

AddNewColor::AddNewColor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewColor)
{
    ui->setupUi(this);
    connect(ui->cancelButton, &QPushButton::clicked, this, &AddNewColor::cancelButtonPressed);
    connect(ui->cancelButton, &QPushButton::clicked, this, &AddNewColor::on_cancel_button_pressed);
    connect(ui->confirmButton, &QPushButton::clicked, this, &AddNewColor::confirmedButtonPressed);
    connect(ui->confirmButton, &QPushButton::clicked, this, &AddNewColor::on_confirm_button_pressed);
}

AddNewColor::~AddNewColor()
{
    delete ui;
}

void AddNewColor::on_cancel_button_pressed(){
    this->hide();
}

void AddNewColor::on_confirm_button_pressed() {

}
