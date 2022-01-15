#include "confirm_booking_1.h"
#include "ui_confirm_booking_1.h"

Confirm_Booking_1::Confirm_Booking_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Confirm_Booking_1)
{
    ui->setupUi(this);
}

Confirm_Booking_1::~Confirm_Booking_1()
{
    delete ui;
}


void Confirm_Booking_1::systemFunction()
{
    ui->cmbConfirm->clear();

    QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
    query.prepare("select Seat_Number from Seat_Availability_1 where Available='F'"); // fetching selected seats

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblSeat->setText(query.lastError().text());
    }
    else{
        qDebug() << "Reading succeed"<< query.lastQuery();
       }

    while(query.next())
    {
        ui->cmbConfirm->addItem(query.value(0).toString());
    }

    if(ui->cmbConfirm->count()<0)
        ui->btnConfirm1->setEnabled(false);
}


void Confirm_Booking_1::on_btnConfirm1_clicked()
{
    QString seat = ui->cmbConfirm->currentText();

    QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
    query.prepare("update Seat_Availability_1 set Available='R' where Seat_Number= '" + seat +"'"); // update seats availability to reserved

    if(!query.exec())
    {
         qDebug() << query.lastError().text() << query.lastQuery();
         ui->lblSeat->setText(query.lastError().text());
    }
    else{
        if(query.numRowsAffected() > 0)
        {
            ui->lblSeat->setText(QString("%1 Seat Booked").arg(seat)); // showing reserved seat number
            qDebug() << "Reading succeed"<< query.lastQuery();
        }
        else
        {
            ui->lblSeat->setText("Unable to book the seat");
        }

    }
    systemFunction();
    emit seatBook();
}

