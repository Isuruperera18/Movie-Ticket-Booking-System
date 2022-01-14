#include "system_database.h"

System_Database* System_Database::instance = nullptr;

System_Database::System_Database()
{
    init();
}


void System_Database::init()
{
    qDebug() << "In init()";
    systemdb = QSqlDatabase::addDatabase("QSQLITE", "Data");
    systemdb.setDatabaseName("C:/Users/Isuru Perera/Documents/Qt/Movie_Ticket_Booking_System/TicketBookingSystem.db"); // database file path

    if(QFile::exists("C:/Users/Isuru Perera/Documents/Qt/Movie_Ticket_Booking_System/TicketBookingSystem.db"))
        qDebug() << "System Database Available";
    else
        qDebug() << "System Database Unavailable";

    if (!systemdb.open())
         qDebug() << systemdb.lastError().text();
    else
         qDebug() << "System Database Loaded";

}


System_Database *System_Database::getInstance()
{
    qDebug() << "In System_Database::getInstance()";
    if(instance == nullptr)
    instance = new System_Database();
    return instance;
}


QSqlDatabase System_Database::getSystemDBInstance()
{
    qDebug() <<"In getSystemDBInstance()";
    return systemdb;
}


void System_Database::ResetInstance()
{
    qDebug() << "Deleting Instance of System_Database";
    delete instance;
    instance = nullptr;
}


System_Database::~System_Database()
{
    qDebug() << "Closing System_Database Connection";
    systemdb.close();
}
