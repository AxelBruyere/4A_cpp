#include "window.hpp"

#include "render_area.hpp"
#include "ui_mainwindow.h"

#include <iostream>

window::window(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MainWindow),render(new render_area)
{
    ui->setupUi(this);

    ui->layout_scene->addWidget(render);

    //Connection with signals
    connect(ui->quit,SIGNAL(clicked()),this,SLOT(action_quit()));
    //connect(ui->pushButton_lay,SIGNAL(clicked()), render, SIGNAL(on_pushButton_lay_clicked()));

}

window::~window()
{}

void window::action_quit()
{
    close();
}

int window::on_pushButton_lay_clicked()
{
    if(ui->radioButton_lay1->isChecked()){
        return 1;
    }
    if(ui->radioButton_lay2->isChecked()){
        return 2;
    }
    if(ui->radioButton_lay3->isChecked()){
        return 3;
    }
    else{
        return 1;
    }
}
