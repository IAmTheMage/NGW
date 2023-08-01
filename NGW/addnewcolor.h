#ifndef ADDNEWCOLOR_H
#define ADDNEWCOLOR_H

#include <json.hpp>
#include <fstream>
#include "iostream"
#include "ostream"
using json = nlohmann::json;

#include <QDialog>

namespace Ui {
class AddNewColor;
}

class AddNewColor : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewColor(QWidget *parent = nullptr);
    ~AddNewColor();

private:
    Ui::AddNewColor *ui;
    void on_cancel_button_pressed();
    void on_confirm_button_pressed();

signals:
    void cancelButtonPressed();
    void confirmedButtonPressed();
};

#endif // ADDNEWCOLOR_H
