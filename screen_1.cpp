#include "screen_1.h"
#include "ui_screen_1.h"

#include<QTimer>
#include<QDateTime>

Screen_1::Screen_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Screen_1)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()) , this, SLOT(showDateTime())); // datetime signal
    timer->start();

    ptrselect_seat_1  = new Select_Seat_1(this);
    ptrcancel_seat_1 = new Cancel_Seat_1(this);
    ptrconfirm_booking_1 = new Confirm_Booking_1(this);

    connect(ptrselect_seat_1, &Select_Seat_1::seatSelect, this, &Screen_1::systemFunction); // select signal
    connect(ptrcancel_seat_1, &Cancel_Seat_1::seatCancel, this, &Screen_1::systemFunction); // cancel signal
    connect(ptrconfirm_booking_1, &Confirm_Booking_1::seatBook, this, &Screen_1::systemFunction); // book signal
    connect(ptrselect_seat_1, &Select_Seat_1::priceAdd, this, &Screen_1::setPrice); // price add signal
    connect(ptrcancel_seat_1, &Cancel_Seat_1::priceReduce, this, &Screen_1::setPrice); // price reduce signal

    systemFunction();
}


void Screen_1::showDateTime()
{
    QDateTime datetime=QDateTime::currentDateTime();
    QString datetime_text=datetime.toString("MMM dd, hh : mm ");
    ui->lblDateTime->setText(datetime_text);
}


Screen_1::~Screen_1()
{
    delete ui;
    delete ptrselect_seat_1;
    delete ptrcancel_seat_1;
    delete ptrconfirm_booking_1;
}


void Screen_1::systemFunction()
{
    qDebug() << "In systemFunction()";

    QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
    query.prepare("select Seat_Number, Available from Seat_Availability_1");

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
    }
    else{
        qDebug() << "Reading succeed"<< query.lastQuery();
    }

    while(query.next())
    {
        QString seat = "lbl" + query.value(0).toString();
        qDebug() <<"Label is : "<< seat;
        QLabel * ptr = this->findChild<QLabel*>(seat);

        if(ptr!=nullptr)
        {   qDebug() << "Label found"<<seat;
            if(query.value(1).toString().compare("F") == 0) // show selected seats in green colour
            {
                QPixmap pm(":/ImageResources/Images/Select.png");
                ptr->setPixmap(pm);
                ptr->setScaledContents(true);
                qDebug()<<query.value(0).toString() << " : is Selected";
            }
            else if(query.value(1).toString().compare("R") == 0) // show reserved seats in red colour
            {
                QPixmap pm(":/ImageResources/Images/Reserved.png");
                ptr->setPixmap(pm);
                ptr->setScaledContents(true);
                qDebug()<<query.value(0).toString() << " : is Reserved";
            }
            else
            {
                QPixmap pm(":/ImageResources/Images/Available.png"); // show available seats in grey colour
                ptr->setPixmap(pm);
                ptr->setScaledContents(true);
                qDebug()<<query.value(0).toString() << " : is Available";
            }
        }
    }
}


void Screen_1::on_btnSelectSeat1_clicked()
{
    ptrselect_seat_1->systemFunction();
    ptrselect_seat_1->show();
}


void Screen_1::on_btnCancelSeat1_clicked()
{
    ptrcancel_seat_1->systemFunction();
    ptrcancel_seat_1->show();
}


void Screen_1::on_btnReset_clicked()
{
    ui->lblTotal->setText("$0"); // reset price

    QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
    query.prepare("update Seat_Availability_1 set Available = 'T'"); // reset the seats availability to available

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
    }
    else{
        if(query.numRowsAffected() > 0)
        {
            qDebug() << "Update succeed"<< query.lastQuery();
        }
        else
        {
            qDebug() << "Update failed"<< query.lastQuery();
        }
    }
    systemFunction();
}


void Screen_1::on_btnConfirmBooking1_clicked()
{
    ptrconfirm_booking_1->systemFunction();
    ptrconfirm_booking_1->show();
}


void Screen_1::setPrice(QString newValue)
{
    ui->lblTotal->setText(newValue);
    qDebug() << "current price" << newValue << "price!";
}

