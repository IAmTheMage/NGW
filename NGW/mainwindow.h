#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "unordered_map"
#include "string"
#include "addnewcolor.h"
#include <fstream>
#include <json.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QImage>
#include <QPixmap>
using json = nlohmann::json;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void setCallbacks();

    //Callbacks
    void ui_definitions();
    void on_camera_btn_clicked();
    void on_select_colors_btn_clicked();
    void on_add_new_color_btn_clicked();


    //AddNewColorDialog
    AddNewColor _newColorDialog;
    void on_cancel_new_color();
    void on_confirm_new_color();

    //Auxiliary states
    std::unordered_map<std::string, bool> preventTwoClicks;
};
#endif // MAINWINDOW_H
