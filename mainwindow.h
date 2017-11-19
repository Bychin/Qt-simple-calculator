//
// Created by Bychin on 17.11.2017.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QWidget* defaultCalcWidget;
    QWidget* simpleCalcWidget;
    QWidget* complCalcWidget;
    QWidget* mainWidget;

    QGridLayout* defaultCalcLayout;
    QGridLayout* simpleCalcLayout;
    QGridLayout* complCalcLayout;
    QGridLayout* mainLayout;

    void CreateDefaultCalcWidget();
    void CreateSimpleCalcWidget();
    void CreateComplCalcWidget();

    void SpawnSimpleMode();
    void SpawnComplMode();

public slots:
    void SwitchMode();

    /*void DigitOrSignClicked();
    void FunctionClicked();

    void ClearInput();
    void Equals();

    void Add_x_y();
    void Add_x_square();
    void Add_x_cubed();
    void Add_x_fact();
    void Add_x_root_y();
    void Add_x_root_3();
    void Add_invert();*/

};

#endif // MAINWINDOW_H
