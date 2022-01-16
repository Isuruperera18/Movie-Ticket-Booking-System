#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ptrscreen_1  = new Screen_1(this);
    ptrscreen_2 = new Screen_2(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrscreen_1;
    delete ptrscreen_2;
}


void MainWindow::on_btnScreen1_clicked()
{
    ptrscreen_1->show();
    //hide();
}


void MainWindow::on_btnScreen2_clicked()
{
    ptrscreen_2->show();
    //hide();
}

