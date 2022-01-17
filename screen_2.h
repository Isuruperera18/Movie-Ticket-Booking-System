#ifndef SCREEN_2_H
#define SCREEN_2_H

#include <QMainWindow>
#include "system_database.h"
#include "select_seat_2.h"
#include "cancel_seat_2.h"
#include "confirm_booking_2.h"

/*!
 * \brief Handle the processes of availability changes, price changes and opening Dialog windows
 */
namespace Ui {
class Screen_2;
}

class Screen_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Screen_2(QWidget *parent = nullptr);
    ~Screen_2();

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
     * \brief This function will open Select_Seat_2 Dialog window
     */
    void on_btnSelectSeat2_clicked();


    /*!
     * \brief This function will open Cancel_Seat_2 Dialog window
     */
    void on_btnCancelSeat2_clicked();


    /*!
     * \brief This function will open Confirm_Booking_2 Dialog window
     */
    void on_btnConfirmBooking2_clicked();


    /*!
     * \brief This function will reset the seats availability
     */
    void on_btnReset_clicked();

public slots:

    /*!
     * \brief Generate the price according to selecting and cancelling seats
     * \param Current price
     */
    void setPrice(QString newValue);

private:
    Ui::Screen_2 *ui;
    Select_Seat_2 *ptrselect_seat_2;
    Cancel_Seat_2 *ptrcancel_seat_2;
    Confirm_Booking_2 *ptrconfirm_booking_2;
};

#endif // SCREEN_2_H
