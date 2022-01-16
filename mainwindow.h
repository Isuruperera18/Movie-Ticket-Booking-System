#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "screen_1.h"
#include "screen_2.h"

/*!
 * \brief Handle the process of opening Screen_1 and Screen_2
 */
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /*!
     * \brief This function will open the Screen_1 window
     */
    void on_btnScreen1_clicked();

    /*!
     * \brief This function will open the Screen_2 window
     */
    void on_btnScreen2_clicked();

private:
    Ui::MainWindow *ui;
    Screen_1 *ptrscreen_1;
    Screen_2 *ptrscreen_2;
};
#endif // MAINWINDOW_H
