#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    QCalendarWidget *calender = new QCalendarWidget;
    //label = new QLabel("Hello, Wod!", this);
    //label->setAlignment(Qt::AlignCenter);
    QTableView *hours = new QTableView();
    QVBoxLayout *layout = new QVBoxLayout;
    
    
    hours->horizontalHeader()->hide();
    hours->setModel(one.getCurrentDate());




    layout->addWidget(calender);
    //layout->addWidget(label);
    layout->addWidget(hours);
    central->setLayout(layout);
    setCentralWidget(central);

    
}

MainWindow::~MainWindow() {}
