#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    
    stack->addWidget(central);
    stack->addWidget(event_page);
    
    
    
    layout->addWidget(calender);
    layout->addWidget(hours);
    layout->addWidget(add_event);
    central->setLayout(layout);
    
    layout2->addWidget(yearLabel);
    layout2->addWidget(year);
    layout2->addWidget(monthLabel);
    layout2->addWidget(month);
    layout2->addWidget(dayLabel);
    layout2->addWidget(day);
    layout2->addWidget(hourLabel);
    layout2->addWidget(hour);
    layout2->addWidget(new_event);
    layout2->addWidget(confirm_button);
    layout2->addWidget(back_button);
    event_page->setLayout(layout2);

    setCentralWidget(stack);
    
    
    
    hours->horizontalHeader()->hide();
    hours->setModel(one.getCurrentDate());
    
     year->addItem("");
    year->addItem("2025");
    year->addItem("2026");
    hour->addItems(QStringList() << "" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11" << "12" << "13" << "14" << "15" << "16" << "17" << "18" << "19" << "20" << "21" << "22" << "23" << "24");
    month->addItems(QStringList() << "" << "January" << "February" << "March"  << "April" << "May" << "June" << "July" << "August" << "September" << "October" << "November" << "December");
    day->addItem("");

    connect(calender, &QCalendarWidget::clicked, this, &MainWindow::onDateClicked);
    connect(add_event, &QPushButton::clicked, this, &MainWindow::onChangeEvent);
    connect(back_button, &QPushButton::clicked, this, &MainWindow::onBackButton);
    connect(confirm_button, &QPushButton::clicked, this, &MainWindow::onConfirmButton);
    connect(year, &QComboBox::currentTextChanged, this, &MainWindow::yearChanged);
    connect(day, &QComboBox::currentTextChanged, this, &MainWindow::dayChanged);
    connect(month, &QComboBox::currentTextChanged, this, &MainWindow::monthChanged);
    connect(hour, &QComboBox::currentTextChanged, this, &MainWindow::hourChanged);
    connect(new_event, &QLineEdit::textChanged, this, &MainWindow::eventChanged);
}

MainWindow::~MainWindow() {}

void MainWindow::onDateClicked(const QDate &date) {
    one.load(date);
    hours->setModel(one.getCurrentDate());
}

void MainWindow::onChangeEvent() {
    stack->setCurrentWidget(event_page);
}

void MainWindow::onBackButton() {
    stack->setCurrentWidget(central);
}

void MainWindow::onConfirmButton() {
    if (!new_event->text().isEmpty()) {
        one.storeEvent(year_final, month_final, day_final, hour_final, item);
        new_event->clear();
    }
}

void MainWindow::yearChanged(const QString &text) {
   year_final = text.toInt();
}

void MainWindow::dayChanged(const QString &text) {
   day_final = text.toInt();
}

void MainWindow::monthChanged(const QString &text) {
    QString current = day->currentText();
    int index = day->findText(current);
    QStringList days31 = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
    QStringList days30 = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30"};
    QStringList days28 = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28"};
    day->clear();
    if(text == "January" || text == "March" || text == "May" || text == "July" || text == "October" || text == "December" || text == "August") {
        day->addItems(days31);
    } else if (text == "April" || text == "June" || text == "September" || text == "November") {
        day->addItems(days30);
    } else {
        day->addItems(days28);
    }
    if (index != -1) {
        day->setCurrentIndex(index);
    } 
    month_final = month->findText(text) + 2;
}

void MainWindow::hourChanged(const QString &text) {
    hour_final = text.toInt();
}

void MainWindow::eventChanged(const QString &text) {
    item = text;
}