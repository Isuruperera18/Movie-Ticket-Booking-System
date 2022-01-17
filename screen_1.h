#ifndef SCREEN_1_H
#define SCREEN_1_H

#include <QMainWindow>
#include "system_database.h"
#include "select_seat_1.h"
#include "cancel_seat_1.h"
#include "confirm_booking_1.h"

/*!
 * \brief Handle the processes of availability changes, price changes and opening Dialog windows
 */
namespace Ui {
class Screen_1;
}

class Screen_1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Screen_1(QWidget *parent = nullptr);
    ~Screen_1();

    /*!
     * \brief This function will fetch all the seats and show each seats availability
     */
    void systemFunction();

private slots:

    /*!
     * \brief This function will generate running date and time
     */
    void showDateTime();


    /*!
     * \brief This function will open Select_Seat_1 Dialog window
     */
    void on_btnSelectSeat1_clicked();


    /*!
     * \brief This function will open Cancel_Seat_1 Dialog window
     */
    void on_btnCancelSeat1_clicked();


    /*!
     * \brief This function will reset the seats availability
     */
    void on_btnReset_clicked();


    /*!
     * \brief This function will open Confirm_Booking_1 Dialog window
     */
    void on_btnConfirmBooking1_clicked();

public slots:

    /*!
     * \brief Generate the price according to selecting and cancelling seats
     * \param Current price
     */
    void setPrice(QString newValue);

private:
    Ui::Screen_1 *ui;
    Select_Seat_1 *ptrselect_seat_1;
    Cancel_Seat_1 *ptrcancel_seat_1;
    Confirm_Booking_1 *ptrconfirm_booking_1;
};

#endif // SCREEN_1_H
