#include "select_seat_1.h"
#include "ui_select_seat_1.h"

Select_Seat_1::Select_Seat_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select_Seat_1)
{
    ui->setupUi(this);
}

Select_Seat_1::~Select_Seat_1()
{
    delete ui;
}


void Select_Seat_1::systemFunction()
{
    ui->cmbSelect->clear();

    QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
    query.prepare("select Seat_Number from Seat_Availability_1 where Available='T'"); // fetching available seats

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
        ui->cmbSelect->addItem(query.value(0).toString());
    }

    if(ui->cmbSelect->count()<=0)
        ui->btnSelect1->setEnabled(false);
}


void Select_Seat_1::on_btnSelect1_clicked()
{
    QString seat = ui->cmbSelect->currentText();

    QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
    query.prepare("update Seat_Availability_1 set Available='F' where Seat_Number= '" + seat +"'"); // update seats availability to selected

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblSeat->setText(query.lastError().text());
    }
    else{
        if(query.numRowsAffected() > 0)
        {
            ui->lblSeat->setText(QString("%1 Seat Selected").arg(seat)); // showing selected seat number
            qDebug() << "Reading succeed"<< query.lastQuery();

            QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
            query.prepare("select Price from Seat_Availability_1 where Seat_Number= '" + seat + "'"); // fetching the seat price
            query.exec();
            query.next();
            QString price = query.value(0).toString(); // add the price after selection
            emit priceAdd(price);
        }
        else
        {
            ui->lblSeat->setText("Unable to select the seat");
        }

     }
     systemFunction();
     emit seatSelect();
}

