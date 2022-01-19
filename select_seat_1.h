#ifndef SELECT_SEAT_1_H
#define SELECT_SEAT_1_H

#include <QDialog>
#include "system_database.h"

/*!
 * \brief Handle the process of selecting seats in Screen_1
 */
namespace Ui {
class Select_Seat_1;
}

class Select_Seat_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Select_Seat_1(QWidget *parent = nullptr);
    ~Select_Seat_1();

    /*!
     * \brief This function will fetch available seats from the Database
     */
    void systemFunction();

private slots:

    /*!
     * \brief This function will update the seats availability to selected and show the selected seat number in the Dialog window
     */
    void on_btnSelect1_clicked();

private:
    Ui::Select_Seat_1 *ui;

signals:

    /*!
     * \brief Change the seat location color to green after selecting the seat
     */
    void seatSelect();

    /*!
     * \brief Generate the price after selecting the seat
     * \param Price after selection
     */
    void priceAdd(QString newValue);

};

#endif // SELECT_SEAT_1_H
