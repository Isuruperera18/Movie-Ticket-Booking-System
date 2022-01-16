#ifndef CONFIRM_BOOKING_2_H
#define CONFIRM_BOOKING_2_H

#include <QDialog>
#include "system_database.h"

/*!
 * \brief Handle the process of reserving seats in Screen_2
 */
namespace Ui {
class Confirm_Booking_2;
}

class Confirm_Booking_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Confirm_Booking_2(QWidget *parent = nullptr);
    ~Confirm_Booking_2();

    /*!
     * \brief This function will fetch selected seats from the Database
     */
    void systemFunction();

private slots:

    /*!
     * \brief This function will update the seats availability to reserved and show the reserved seat number in the Dialog window
     */
    void on_btnConfirm2_clicked();

private:
    Ui::Confirm_Booking_2 *ui;

signals:

    /*!
     * \brief Change the seat location color to red after reserving the seat
     */
    void seatBook();

};

#endif // CONFIRM_BOOKING_2_H
