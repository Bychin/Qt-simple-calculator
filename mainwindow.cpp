//
// Created by Bychin on 17.11.2017.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cctype>
#include <cmath>

#if _WIN32
#define SEPARATOR '.'
#endif

#if __unix
#define SEPARATOR ','
#endif

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Калькулятор (обычный)");
    setWindowOpacity(0.98);
    setMinimumSize(380, 450);
    setMaximumSize(380, 450);

    ui->lineEdit->setPlaceholderText("0");
    ui->lineEdit->setReadOnly(true);
    ui->radioButtonSimple->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->radioButtonCompl->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->radioButtonSimple->setChecked(true);
    connect(ui->radioButtonSimple, SIGNAL(toggled(bool)), SLOT(SwitchMode()));

    CreateSimpleCalcWidget();
    CreateComplCalcWidget();
    CreateDefaultCalcWidget();
    mainWidget = new QWidget;
    SpawnSimpleMode();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SwitchMode() {
    mainWidget->setParent(this);
    simpleCalcWidget->setParent(this);
    complCalcWidget->setParent(this);
    if (!ui->radioButtonSimple->isChecked()) {
        delete mainLayout;
        setWindowTitle("Калькулятор (инженерный)");
        setMinimumSize(685, 450);
        setMaximumSize(685, 450);
        SpawnComplMode();
    }
    else {
        delete mainLayout;
        setWindowTitle("Калькулятор (обычный)");
        setMinimumSize(380, 450);
        setMaximumSize(380, 450);
        SpawnSimpleMode();
    }
}

void MainWindow::SpawnSimpleMode() {
    mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    complCalcWidget->hide();
    mainLayout->addWidget(defaultCalcWidget, 0, 0, 1, 3);
    mainLayout->addWidget(simpleCalcWidget,  1, 0, 2, 3);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
}

void MainWindow::SpawnComplMode() {
    mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    mainLayout->addWidget(defaultCalcWidget, 0, 0, 1, 9);
    mainLayout->addWidget(complCalcWidget,   1, 0, 2, 4);
    mainLayout->addWidget(simpleCalcWidget,  1, 4, 2, 5);
    complCalcWidget->show();

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
}

void MainWindow::CreateSimpleCalcWidget() {
    QPushButton* pushButton0 =      new QPushButton("0");
    QPushButton* pushButton1 =      new QPushButton("1");
    QPushButton* pushButton2 =      new QPushButton("2");
    QPushButton* pushButton3 =      new QPushButton("3");
    QPushButton* pushButton4 =      new QPushButton("4");
    QPushButton* pushButton5 =      new QPushButton("5");
    QPushButton* pushButton6 =      new QPushButton("6");
    QPushButton* pushButton7 =      new QPushButton("7");
    QPushButton* pushButton8 =      new QPushButton("8");
    QPushButton* pushButton9 =      new QPushButton("9");
    QPushButton* pushButtonDot =    new QPushButton(",");
    QPushButton* pushButtonPlus =   new QPushButton("+");
    QPushButton* pushButtonMinus =  new QPushButton(QString::fromUtf8("-"));
    QPushButton* pushButtonMult =   new QPushButton(QString::fromUtf8("\u00D7"));
    QPushButton* pushButtonDivide = new QPushButton(QString::fromUtf8("\u00F7"));
    QPushButton* pushButtonEquals = new QPushButton("=");
    QPushButton* pushButtonSqrt =   new QPushButton(QString::fromUtf8("\u221A"));
    QPushButton* pushButtonInvert = new QPushButton(QString::fromUtf8("x\u207B\u00B9"));

    pushButton0->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton1->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton2->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton3->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton4->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton5->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton6->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton7->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton8->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton9->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonPlus->setSizePolicy(  QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonMinus->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonDot->setSizePolicy(   QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonMult->setSizePolicy(  QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonDivide->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonEquals->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonInvert->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonSqrt->setSizePolicy(  QSizePolicy::Preferred, QSizePolicy::Preferred);

    QString StyleSheetNumbers = "QPushButton { color: black; background-color: #FAFAFA; border: none; font: 17pt 'Microsoft YaHei UI'; outline: none;} QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #F2F2F2; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";
    QString StyleSheetSigns =   "QPushButton { color: black; background-color: #E6E6E6; border: none; font: 19pt 'Microsoft YaHei UI Light'; outline: none; } QPushButton:hover { background-color: #2ECCFA; border-style: solid; border-width: 3px; border-color: #58D3F7; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";
    pushButton0->setStyleSheet(     StyleSheetNumbers);
    pushButton1->setStyleSheet(     StyleSheetNumbers);
    pushButton2->setStyleSheet(     StyleSheetNumbers);
    pushButton3->setStyleSheet(     StyleSheetNumbers);
    pushButton4->setStyleSheet(     StyleSheetNumbers);
    pushButton5->setStyleSheet(     StyleSheetNumbers);
    pushButton6->setStyleSheet(     StyleSheetNumbers);
    pushButton7->setStyleSheet(     StyleSheetNumbers);
    pushButton8->setStyleSheet(     StyleSheetNumbers);
    pushButton9->setStyleSheet(     StyleSheetNumbers);
    pushButtonPlus->setStyleSheet(  StyleSheetSigns);
    pushButtonMinus->setStyleSheet( StyleSheetSigns);
    pushButtonDot->setStyleSheet(   StyleSheetSigns);
    pushButtonMult->setStyleSheet(  StyleSheetSigns);
    pushButtonDivide->setStyleSheet(StyleSheetSigns);
    pushButtonEquals->setStyleSheet(StyleSheetSigns);
    pushButtonInvert->setStyleSheet(StyleSheetSigns);
    pushButtonSqrt->setStyleSheet(  StyleSheetSigns);

    simpleCalcLayout = new QGridLayout(this);
    simpleCalcLayout->setSpacing(0);
    simpleCalcLayout->setContentsMargins(0, 0, 0, 0);

    simpleCalcLayout->addWidget(pushButton7,      0, 0, 1, 1);
    simpleCalcLayout->addWidget(pushButton8,      0, 1, 1, 1);
    simpleCalcLayout->addWidget(pushButton9,      0, 2, 1, 1);
    simpleCalcLayout->addWidget(pushButtonDivide, 0, 3, 1, 1);
    simpleCalcLayout->addWidget(pushButtonSqrt,   0, 4, 1, 1);
    simpleCalcLayout->addWidget(pushButton4,      1, 0, 1, 1);
    simpleCalcLayout->addWidget(pushButton5,      1, 1, 1, 1);
    simpleCalcLayout->addWidget(pushButton6,      1, 2, 1, 1);
    simpleCalcLayout->addWidget(pushButtonMult,   1, 3, 1, 1);
    simpleCalcLayout->addWidget(pushButtonInvert, 1, 4, 1, 1);
    simpleCalcLayout->addWidget(pushButton1,      2, 0, 1, 1);
    simpleCalcLayout->addWidget(pushButton2,      2, 1, 1, 1);
    simpleCalcLayout->addWidget(pushButton3,      2, 2, 1, 1);
    simpleCalcLayout->addWidget(pushButtonMinus,  2, 3, 1, 1);
    simpleCalcLayout->addWidget(pushButtonEquals, 2, 4, 2, 1);
    simpleCalcLayout->addWidget(pushButton0,      3, 0, 1, 2);
    simpleCalcLayout->addWidget(pushButtonDot,    3, 2, 1, 1);
    simpleCalcLayout->addWidget(pushButtonPlus,   3, 3, 1, 1);

    simpleCalcWidget = new QWidget(this);
    simpleCalcWidget->setLayout(simpleCalcLayout);

    connect(pushButton0,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton1,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton2,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton3,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton4,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton5,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton6,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton7,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton8,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButton9,      SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(pushButtonPlus,   SIGNAL(clicked()), this, SLOT(BinFnClicked()));
    connect(pushButtonMinus,  SIGNAL(clicked()), this, SLOT(BinFnClicked()));
    connect(pushButtonMult,   SIGNAL(clicked()), this, SLOT(BinFnClicked()));
    connect(pushButtonDivide, SIGNAL(clicked()), this, SLOT(BinFnClicked()));
    connect(pushButtonSqrt,   SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonDot,    SIGNAL(clicked()), this, SLOT(DotClicked()));
    connect(pushButtonEquals, SIGNAL(clicked()), this, SLOT(Equals()));
    connect(pushButtonInvert, SIGNAL(clicked()), this, SLOT(UnFnClicked()));
}

void MainWindow::CreateComplCalcWidget() {
    QPushButton* pushButtonSinh     = new QPushButton("sh");
    QPushButton* pushButtonSin      = new QPushButton("sin");
    QPushButton* pushButtonExp      = new QPushButton(QString::fromUtf8("e\u207F"));
    QPushButton* pushButtonXSq      = new QPushButton(QString::fromUtf8("x\u00B2"));
    QPushButton* pushButtonCosh     = new QPushButton("ch");
    QPushButton* pushButtonCos      = new QPushButton("cos");
    QPushButton* pushButtonLn       = new QPushButton("ln");
    QPushButton* pushButtonXCubed   = new QPushButton(QString::fromUtf8("x\u00B3"));
    QPushButton* pushButtonTanh     = new QPushButton("th");
    QPushButton* pushButtonTan      = new QPushButton("tan");
    QPushButton* pushButtonLog      = new QPushButton("log");
    QPushButton* pushButtonXNed     = new QPushButton(QString::fromUtf8("x\u207F"));
    QPushButton* pushButtonFact     = new QPushButton("n!");
    QPushButton* pushButtonPi       = new QPushButton(QString::fromUtf8("\u03C0"));
    QPushButton* pushButtonCubeRoot = new QPushButton(QString::fromUtf8("\u00B3\u221A"));
    QPushButton* pushButtonNRoot    = new QPushButton(QString::fromUtf8("\u207F\u221A"));

    pushButtonSinh->setSizePolicy(    QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonSin->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonExp->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonXSq->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonCosh->setSizePolicy(    QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonCos->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonLn->setSizePolicy(      QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonXCubed->setSizePolicy(  QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonTanh->setSizePolicy(    QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonTan->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonLog->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonXNed->setSizePolicy(    QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonFact->setSizePolicy(    QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonPi->setSizePolicy(      QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonCubeRoot->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonNRoot->setSizePolicy(   QSizePolicy::Preferred, QSizePolicy::Preferred);

    QString StyleSheetSpecSigns = "QPushButton {max-width: 77px; color: black; background-color: #E6E6E6; border: none; font: 14pt 'Microsoft YaHei UI Light'; outline: none; } QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #E6E6E6; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";
    QString StyleSheetSpecRoot =  "QPushButton {max-width: 77px; color: black; background-color: #E6E6E6; border: none; font: 16pt 'Microsoft YaHei UI Light'; outline: none; } QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #E6E6E6; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";
    pushButtonCosh->setStyleSheet(    StyleSheetSpecSigns);
    pushButtonCos->setStyleSheet(     StyleSheetSpecSigns);
    pushButtonSinh->setStyleSheet(    StyleSheetSpecSigns);
    pushButtonSin->setStyleSheet(     StyleSheetSpecSigns);
    pushButtonExp->setStyleSheet(     StyleSheetSpecSigns);
    pushButtonPi->setStyleSheet(      StyleSheetSpecSigns);
    pushButtonCubeRoot->setStyleSheet(StyleSheetSpecRoot);
    pushButtonNRoot->setStyleSheet(   StyleSheetSpecRoot);
    pushButtonTanh->setStyleSheet(    StyleSheetSpecSigns);
    pushButtonTan->setStyleSheet(     StyleSheetSpecSigns);
    pushButtonFact->setStyleSheet(    StyleSheetSpecSigns);
    pushButtonLn->setStyleSheet(      StyleSheetSpecSigns);
    pushButtonLog->setStyleSheet(     StyleSheetSpecSigns);
    pushButtonXSq->setStyleSheet(     StyleSheetSpecSigns);
    pushButtonXCubed->setStyleSheet(  StyleSheetSpecSigns);
    pushButtonXNed->setStyleSheet(    StyleSheetSpecSigns);

    complCalcLayout = new QGridLayout(this);
    complCalcLayout->setSpacing(0);
    complCalcLayout->setContentsMargins(0, 0, 0, 0);

    complCalcLayout->addWidget(pushButtonSinh,     0, 0, 1, 1);
    complCalcLayout->addWidget(pushButtonSin,      0, 1, 1, 1);
    complCalcLayout->addWidget(pushButtonExp,      0, 2, 1, 1);
    complCalcLayout->addWidget(pushButtonXSq,      0, 3, 1, 1);
    complCalcLayout->addWidget(pushButtonCosh,     1, 0, 1, 1);
    complCalcLayout->addWidget(pushButtonCos,      1, 1, 1, 1);
    complCalcLayout->addWidget(pushButtonLn,       1, 2, 1, 1);
    complCalcLayout->addWidget(pushButtonXCubed,   1, 3, 1, 1);
    complCalcLayout->addWidget(pushButtonTanh,     2, 0, 1, 1);
    complCalcLayout->addWidget(pushButtonTan,      2, 1, 1, 1);
    complCalcLayout->addWidget(pushButtonLog,      2, 2, 1, 1);
    complCalcLayout->addWidget(pushButtonXNed,     2, 3, 1, 1);
    complCalcLayout->addWidget(pushButtonFact,     3, 0, 1, 1);
    complCalcLayout->addWidget(pushButtonPi,       3, 1, 1, 1);
    complCalcLayout->addWidget(pushButtonCubeRoot, 3, 2, 1, 1);
    complCalcLayout->addWidget(pushButtonNRoot,    3, 3, 1, 1);

    complCalcWidget = new QWidget(this);
    complCalcWidget->setLayout(complCalcLayout);

    connect(pushButtonSin,      SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonSinh,     SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonCos,      SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonCosh,     SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonFact,     SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonTan,      SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonTanh,     SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonLn,       SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonLog,      SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonXNed,     SIGNAL(clicked()), this, SLOT(BinFnClicked()));
    connect(pushButtonXSq,      SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonXCubed,   SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonCubeRoot, SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonNRoot,    SIGNAL(clicked()), this, SLOT(BinFnClicked()));
    connect(pushButtonExp,      SIGNAL(clicked()), this, SLOT(UnFnClicked()));
    connect(pushButtonPi,       SIGNAL(clicked()), this, SLOT(NumberClicked())); ///
}

void MainWindow::CreateDefaultCalcWidget() {
    QPushButton* pushButtonBackSpace = new QPushButton(QString::fromUtf8("\u232B"), this);
    QPushButton* pushButtonClear =     new QPushButton(QString::fromUtf8("C"), this);

    QString StyleSheetBackSpace = "QPushButton { color: black; background-color: #E6E6E6; border: none; font: 17pt 'Microsoft YaHei UI Light'; outline: none; } QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #E6E6E6; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";
    QString StyleSheetClear =     "QPushButton { color: black; background-color: #E6E6E6; border: none; font: 17pt 'Microsoft YaHei UI'; outline: none; } QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #E6E6E6; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";
    QString StyleSheetRadioButton = "QRadioButton {background-color: #E6E6E6; font: 10pt 'Microsoft YaHei UI Light'; padding: 0px 0px 0px 20px;} QRadioButton::indicator { width: 20px; height: 20px; } QRadioButton::indicator::unchecked {image: url(radio_normal.svg);} QRadioButton::indicator:unchecked:hover {image: url(radio_normal.svg);} QRadioButton::indicator:unchecked:pressed {image: url(radio_checked.svg);} QRadioButton::indicator:checked {image: url(radio_checked.svg);} QRadioButton::indicator:checked:hover {image: url(radio_checked.svg);} QRadioButton::indicator:checked:pressed {image: url(radio_checked.svg);}";
    QString StyleSheetLine = "QLineEdit {font: 26pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: none; background-color: #F2F2F2;}";

    ui->radioButtonSimple->setStyleSheet(StyleSheetRadioButton);
    ui->radioButtonCompl->setStyleSheet( StyleSheetRadioButton);
    pushButtonBackSpace->setStyleSheet(  StyleSheetBackSpace);
    pushButtonClear->setStyleSheet(      StyleSheetClear);
    ui->lineEdit->setStyleSheet(         StyleSheetLine);

    pushButtonBackSpace->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonClear->setSizePolicy(    QSizePolicy::Preferred, QSizePolicy::Preferred);

    defaultCalcLayout = new QGridLayout(this);
    defaultCalcLayout->setSpacing(0);
    defaultCalcLayout->setContentsMargins(0, 0, 0, 0);

    defaultCalcLayout->addWidget(ui->lineEdit,          0, 0, 2, 5);
    defaultCalcLayout->addWidget(ui->radioButtonSimple, 2, 0, 1, 3);
    defaultCalcLayout->addWidget(ui->radioButtonCompl,  3, 0, 1, 3);
    defaultCalcLayout->addWidget(pushButtonBackSpace,   2, 3, 2, 1);
    defaultCalcLayout->addWidget(pushButtonClear,       2, 4, 2, 1);

    defaultCalcWidget = new QWidget(this);
    defaultCalcWidget->setLayout(defaultCalcLayout);

    connect(pushButtonClear,     SIGNAL(clicked()), this, SLOT(ClearInput()));
    connect(pushButtonBackSpace, SIGNAL(clicked()), this, SLOT(BackSpace()));
}

bool MainWindow::OnlyDigits() {
    return digits_only;
}

void MainWindow::SetDigits(bool new_state) {
    digits_only = new_state;
}

void MainWindow::NumberClicked() {
    QString number = ((QPushButton*)sender())->text();
    if (number == "\u03C0") {
        double pi = 3.1415926535897932384626433832795;
        ui->lineEdit->setText(ui->lineEdit->text() + QString(std::to_string(pi).c_str()));
    }
    else
        ui->lineEdit->setText(ui->lineEdit->text() + number);
}

void MainWindow::DotClicked() {
    if (ui->lineEdit->text().length()) {
        if (ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) != SEPARATOR)
            ui->lineEdit->setText(ui->lineEdit->text() + SEPARATOR);
    } else
        ui->lineEdit->setText("0" + SEPARATOR + ui->lineEdit->text());
}

void MainWindow::BinFnClicked() {
    if (OnlyDigits()) {
        QString symbol = ((QPushButton*)sender())->text();
        if (ui->lineEdit->text().length()) {
            if (symbol == "x\u207F") // x^n
                ui->lineEdit->setText(ui->lineEdit->text() + ", x\u207F n = ");
            else if (symbol == "\u207F\u221A") // x^(1/n)
                ui->lineEdit->setText(ui->lineEdit->text() + ", \u207F\u221Ax n = ");
            else
                ui->lineEdit->setText(ui->lineEdit->text() + symbol);
            SetDigits(false);
        } else if (symbol == "-")
            ui->lineEdit->setText(symbol + ui->lineEdit->text());
    }
}

double fact(double N) {
    if (N < 0)
        return 0;
    if (N == 0.0)
        return 1;
    else
        return N * fact((int)floor(N) - 1);
}

void MainWindow::UnFnClicked() {
    SetDigits(true);
    std::string symbol = ((QPushButton*)sender())->text().toStdString();
    std::string expression = ui->lineEdit->text().toStdString();
    if (expression == "")
        return;
    double number = std::stod(expression);
    if (symbol == "\u221A") // sqrt
        number = std::sqrt(number);
    else if (symbol == "sin")
        number = std::sin(number);
    else if (symbol == "sh")
        number = std::sinh(number);
    else if (symbol == "e\u207F") // exp
        number = std::exp(number);
    else if (symbol == "x\u00B2") // x^2
        number *= number;
    else if (symbol == "ch")
        number = std::cosh(number);
    else if (symbol == "cos")
        number = std::cos(number);
    else if (symbol == "ln")
        number = std::log(number);
    else if (symbol == "\u00B3\u221A") // x^(1/3)
        number = std::cbrt(number);
    else if (symbol == "x\u00B3") // x^3
        number *= (number * number);
    else if (symbol == "th")
        number = std::tanh(number);
    else if (symbol == "tan")
        number = std::tan(number);
    else if (symbol == "log")
        number = std::log10(number);
    else if (symbol == "n!") {
        if (std::floor(number) != number) {
            ui->lineEdit->setText(QString("nan"));
            return;
        }
        else
            number = fact(number);
    }else if (symbol == "x\u207B\u00B9"){
        number = 1 / number;
        expression = std::to_string(number);
        while (*(expression.rbegin()) == '0')
            expression.pop_back();
        if (*(expression.rbegin()) == SEPARATOR)
            expression.pop_back();
        ui->lineEdit->setText(QString(expression.c_str()));
    }
    expression = std::to_string(number);
    while (*(expression.rbegin()) == '0')
        expression.pop_back();
    if (*(expression.rbegin()) == SEPARATOR)
        expression.pop_back();
    ui->lineEdit->setText(QString(expression.c_str()));
}


void MainWindow::ClearInput() {
    ui->lineEdit->clear();
    SetDigits(true);
}

void MainWindow::BackSpace() {
    int length = ui->lineEdit->text().length();
    if (length) {
        char last_char = ui->lineEdit->text().at(length - 1).toLatin1();
        if (!std::isdigit(last_char))
            SetDigits(true);
        ui->lineEdit->setText(ui->lineEdit->text().left(length - 1));
    }
}

void MainWindow::Equals() {
    SetDigits(true);
    std::string expression = ui->lineEdit->text().toStdString();
    std::string search_slice = expression.substr(1);
    std::string answer = "";
    if (!std::isdigit(*(expression.rbegin())))
        BackSpace();
    if (search_slice.find('+') != std::string::npos) {
        std::string::size_type position;
        double left_number  = std::stod(expression, &position);
        double right_number = std::stod(expression.substr(position + 1));
        double answer_number = left_number + right_number;
        answer = std::to_string(answer_number);
        while (*(answer.rbegin()) == '0')
            answer.pop_back();
        if (*(answer.rbegin()) == SEPARATOR)
            answer.pop_back();
        ui->lineEdit->setText(QString(answer.c_str()));
    } else if (search_slice.find('-') != std::string::npos) {
        std::string::size_type position;
        double left_number  = std::stod(expression, &position);
        double right_number = std::stod(expression.substr(position + 1));
        double answer_number = left_number - right_number;
        answer = std::to_string(answer_number);
        while (*(answer.rbegin()) == '0')
            answer.pop_back();
        if (*(answer.rbegin()) == SEPARATOR)
            answer.pop_back();
        ui->lineEdit->setText(QString(answer.c_str()));
    } else if (search_slice.find("\u00D7") != std::string::npos) { // *
        std::string::size_type position;
        double left_number  = std::stod(expression, &position);
        double right_number = std::stod(expression.substr(position + 2));
        double answer_number = left_number * right_number;
        answer = std::to_string(answer_number);
        while (*(answer.rbegin()) == '0')
            answer.pop_back();
        if (*(answer.rbegin()) == SEPARATOR)
            answer.pop_back();
        ui->lineEdit->setText(QString(answer.c_str()));
    } else if (search_slice.find("\u00F7") != std::string::npos) { // /
        std::string::size_type position;
        double left_number  = std::stod(expression, &position);
        double right_number = std::stod(expression.substr(position + 2));
        double answer_number = left_number / right_number;
        answer = std::to_string(answer_number);
        while (*(answer.rbegin()) == '0')
            answer.pop_back();
        if (*(answer.rbegin()) == SEPARATOR)
            answer.pop_back();
        ui->lineEdit->setText(QString(answer.c_str()));
    } else if (search_slice.find(", x\u207F n = ") != std::string::npos) { // x^n
        std::string::size_type position;
        double left_number  = std::stod(expression, &position);
        double right_number = std::stod(ui->lineEdit->text().split(", x\u207F n = ")[1].toStdString());
        double answer_number = std::pow(left_number, right_number);
        answer = std::to_string(answer_number);
        while (*(answer.rbegin()) == '0')
            answer.pop_back();
        if (*(answer.rbegin()) == SEPARATOR)
            answer.pop_back();
        ui->lineEdit->setText(QString(answer.c_str()));
    } else if (search_slice.find(", \u207F\u221Ax n = ") != std::string::npos) { // x^(1/n)
        std::string::size_type position;
        double left_number  = std::stod(expression, &position);
        double right_number = std::stod(ui->lineEdit->text().split(", \u207F\u221Ax n = ")[1].toStdString());
        double answer_number = std::pow(left_number, (1 / right_number));
        answer = std::to_string(answer_number);
        while (*(answer.rbegin()) == '0')
            answer.pop_back();
        if (*(answer.rbegin()) == SEPARATOR)
            answer.pop_back();
        ui->lineEdit->setText(QString(answer.c_str()));
    }
}

