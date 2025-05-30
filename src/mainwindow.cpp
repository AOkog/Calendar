#include "mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QCalendarWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    QCalenderWidget *calender = new QcalendarWidget;
    label = new QLabel("Hello, Wod!", this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(calender);
    layout->addWidget(label);
    central->setLayout(layout);
    setCentralWidget(central);

    
}

MainWindow::~MainWindow() {}
