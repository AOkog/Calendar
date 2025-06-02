#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calendardata.h"
#include <QHeaderView>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QCalendarWidget>
#include <QTableView>
#include <QStringList>
#include <QVector>
#include <QStackedWidget>
#include <QPushButton>
#include <QComboBox>
#include <string>
class QLabel;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private:
    CalendarData one;
    QTableView *hours = new QTableView();;
    QWidget *central = new QWidget(this);
    QWidget *event_page = new QWidget(this);
    QStackedWidget *stack = new QStackedWidget(this);
    QCalendarWidget *calender = new QCalendarWidget;
    QPushButton *add_event = new QPushButton("Add Event", this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    QPushButton *back_button = new QPushButton("back", this);
    QPushButton *confirm_button = new QPushButton("confirm", this);
    QVBoxLayout *layout2 = new QVBoxLayout(this);
    QComboBox *year = new QComboBox(this);
    QComboBox *day = new QComboBox(this);
    QComboBox *month = new QComboBox(this);
    QComboBox *hour = new QComboBox(this);
    QLabel *yearLabel = new QLabel("Select the Year", this);
    QLabel *monthLabel = new QLabel("Select the Month", this);
    QLabel *hourLabel = new QLabel("Select the hour", this);
    QLabel *dayLabel = new QLabel("Select the day", this);
    int year_final;
    int hour_final;
    int day_final;
    int month_final;
    void onBackButton();
    void onConfirmButton();
    void onChangeEvent();
    void onDateClicked(const QDate &date);
    void yearChanged(const QString &text);
    void dayChanged(const QString &text);
    void monthChanged(const QString &text);
    void hourChanged(const QString &text);

};

#endif // MAINWINDOW_H
