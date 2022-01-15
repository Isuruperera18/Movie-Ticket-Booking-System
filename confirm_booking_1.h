#ifndef CONFIRM_BOOKING_1_H
#define CONFIRM_BOOKING_1_H

#include <QDialog>
#include "system_database.h"

/*!
 * \brief Handle the process of reserving seats in Screen_1
 */
namespace Ui {
class Confirm_Booking_1;
}

class Confirm_Booking_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Confirm_Booking_1(QWidget *parent = nullptr);
    ~Confirm_Booking_1();

    /*!
     * \brief This function will fetch selected seats from the Database
     */
    void systemFunction();

private slots:

    /*!
     * \brief This function will update the seats availability to reserved and show the reserved seat number in the Dialog window
     */
    void on_btnConfirm1_clicked();

private:
    Ui::Confirm_Booking_1 *ui;

signals:

    /*!
     * \brief Change the seat location color to red after reserving the seat
     */
    void seatBook();

};

#endif // CONFIRM_BOOKING_1_H
