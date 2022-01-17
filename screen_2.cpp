#include "screen_2.h"
#include "ui_screen_2.h"

#include<QTimer>
#include<QDateTime>

Screen_2::Screen_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Screen_2)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()) , this, SLOT(showDateTime())); // datetime signal
    timer->start();

    ptrselect_seat_2  = new Select_Seat_2(this);
    ptrcancel_seat_2 = new Cancel_Seat_2(this);
    ptrconfirm_booking_2 = new Confirm_Booking_2(this);

    connect(ptrselect_seat_2, &Select_Seat_2::seatSelect, this, &Screen_2::systemFunction); // select signal
    connect(ptrcancel_seat_2, &Cancel_Seat_2::seatCancel, this, &Screen_2::systemFunction); // cancel signal
    connect(ptrconfirm_booking_2, &Confirm_Booking_2::seatBook, this, &Screen_2::systemFunction); // book signal
    connect(ptrselect_seat_2, &Select_Seat_2::priceAdd, this, &Screen_2::setPrice); // price add signal
    connect(ptrcancel_seat_2, &Cancel_Seat_2::priceReduce, this, &Screen_2::setPrice); // price reduce signal

    systemFunction();
}


void Screen_2::showDateTime()
{
    QDateTime datetime=QDateTime::currentDateTime();
    QString datetime_text=datetime.toString("MMM dd, hh : mm ");
    ui->lblDateTime->setText(datetime_text);
}


Screen_2::~Screen_2()
{
    delete ui;
    delete ptrselect_seat_2;
    delete ptrcancel_seat_2;
    delete ptrconfirm_booking_2;
}


void Screen_2::systemFunction()
{
    qDebug() << "In systemFunction()";

    QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
    query.prepare("select Seat_Number, Available from Seat_Availability_2");


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


void Screen_2::on_btnSelectSeat2_clicked()
{
    ptrselect_seat_2->systemFunction();
    ptrselect_seat_2->show();
}


void Screen_2::on_btnCancelSeat2_clicked()
{
    ptrcancel_seat_2->systemFunction();
    ptrcancel_seat_2->show();
}


void Screen_2::on_btnConfirmBooking2_clicked()
{
    ptrconfirm_booking_2->systemFunction();
    ptrconfirm_booking_2->show();
}


void Screen_2::on_btnReset_clicked()
{
    ui->lblTotal->setText("$0"); // reset price

    QSqlQuery query(System_Database::getInstance()->getSystemDBInstance());
    query.prepare("update Seat_Availability_2 set Available = 'T'"); // reset the seats availability to available

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


void Screen_2::setPrice(QString newValue)
{
    ui->lblTotal->setText(newValue);
    qDebug() << "current price" << newValue << "price!";
}

