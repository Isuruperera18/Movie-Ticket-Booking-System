#ifndef SYSTEM_DATABASE_H
#define SYSTEM_DATABASE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QFile>

/*!
 * \brief Handle the Database coonection
 */
class System_Database
{
private:
    System_Database();
    static System_Database *instance;

    /*!
     * \brief Application Database initialization
     */
    void init();
    QSqlDatabase systemdb;

public:

    /*!
     * \brief Assigning a new object for Database
     */
    static System_Database* getInstance();

    /*!
     * \brief Deleting the Instance
     */
    static void ResetInstance();
    QSqlDatabase getSystemDBInstance();
    ~System_Database();
};

#endif // SYSTEM_DATABASE_H
