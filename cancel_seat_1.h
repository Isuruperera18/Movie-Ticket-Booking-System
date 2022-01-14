#ifndef CANCEL_SEAT_1_H
#define CANCEL_SEAT_1_H

#include <QDialog>
#include "system_database.h"

/*!
 * \brief Handle the process of cancelling seats in Screen_1
 */
namespace Ui {
class Cancel_Seat_1;
}

class Cancel_Seat_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Cancel_Seat_1(QWidget *parent = nullptr);
    ~Cancel_Seat_1();

    /*!
     * \brief This function will fetch selected seats from the Database
     */
    void systemFunction();

private slots:

    /*!
     * \brief This function will update the seats availability to available and show the cancellled seat number in the Dialog window
     */
    void on_btnCancel1_clicked();

private:
    Ui::Cancel_Seat_1 *ui;

signals:

    /*!
     * \brief Change the seat location color to grey after cancelling the seat
     */
    void seatCancel();

    /*!
     * \brief Reduce the price after cancelling the seat
     * \param Price after cancellation
     */
    void priceReduce(QString newValue);

};

#endif // CANCEL_SEAT_1_H
