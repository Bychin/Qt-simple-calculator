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

    bool OnlyDigits();
    void SetDigits(bool);

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

    bool digits_only = true;

public slots:
    void SwitchMode();

    void NumberClicked();
    void UnFnClicked();
    void BinFnClicked();
    void DotClicked();

    void ClearInput();
    void BackSpace();
    void Equals();
};

#endif // MAINWINDOW_H
