#include "cancel_seat_2.h"
#include "ui_cancel_seat_2.h"

Cancel_Seat_2::Cancel_Seat_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cancel_Seat_2)
{
    ui->setupUi(this);
}

Cancel_Seat_2::~Cancel_Seat_2()
{
    delete ui;
}


void Cancel_Seat_2::systemFunction()
{
    ui->cmbCancel->clear();

    QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
    query.prepare("select Seat_Number from Seat_Availability_2 where Available='F'"); // fetching selected seats

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
        ui->cmbCancel->addItem(query.value(0).toString());
    }

    if(ui->cmbCancel->count()<0)
        ui->btnCancel2->setEnabled(false);
}


void Cancel_Seat_2::on_btnCancel2_clicked()
{
    QString seat = ui->cmbCancel->currentText();

    QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
    query.prepare("update Seat_Availability_2 set Available='T' where Seat_Number= '" + seat +"'"); // update seats availability to available

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblSeat->setText(query.lastError().text());
    }
    else{
        if(query.numRowsAffected() > 0)
        {
            ui->lblSeat->setText(QString("%1 Selection Cancelled").arg(seat)); // showing cancelled seat number
            qDebug() << "Reading succeed"<< query.lastQuery();

            QString price = "$0"; // reduce the price after cancellation
            emit priceReduce(price);
        }
        else
        {
            ui->lblSeat->setText("Unable to cancel the seat");
        }

    }
    systemFunction();
    emit seatCancel();
}

