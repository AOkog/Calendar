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
#include <QLineEdit>
#include <QHBoxLayout>
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
    QVBoxLayout *layout = new QVBoxLayout();
    QPushButton *back_button = new QPushButton("back", this);
    QPushButton *confirm_button = new QPushButton("confirm", this);
    QVBoxLayout *layout2 = new QVBoxLayout();
    QComboBox *year = new QComboBox(this);
    QComboBox *day = new QComboBox(this);
    QComboBox *month = new QComboBox(this);
    QComboBox *hour = new QComboBox(this);
    QLabel *yearLabel = new QLabel("Select the Year", this);
    QLabel *monthLabel = new QLabel("Select the Month", this);
    QLabel *hourLabel = new QLabel("Select the hour", this);
    QLabel *dayLabel = new QLabel("Select the day", this);
    QLineEdit *new_event = new QLineEdit(this);
    QHBoxLayout *removeLayout = new QHBoxLayout();
    QHBoxLayout *removeLayout2 = new QHBoxLayout();
    QLabel *label = new QLabel("Hour", this);
    QLabel *label2 = new QLabel("Item", this);
    QComboBox *hour2 = new QComboBox(this);
    QComboBox *removeItem = new QComboBox(this);
    QLabel *label3 = new QLabel("Remove items:", this);
    QPushButton *removeConfirm = new QPushButton("Confirm", this);
    QPushButton *save = new QPushButton("Save", this);
    int year_final;
    int hour_final;
    int day_final;
    int month_final;
    int remove_hour;
    int remove_index;
    QString item;
    void onBackButton();
    void onConfirmButton();
    void onChangeEvent();
    void onDateClicked(const QDate &date);
    void yearChanged(const QString &text);
    void dayChanged(const QString &text);
    void monthChanged(const QString &text);
    void hourChanged(const QString &text);
    void eventChanged(const QString &text);
    void removeHourChanged(const QString &text);
    void removeItemChanged(const QString &text);
    void onRemoveConfirm();
    void saveData();

};

#endif // MAINWINDOW_H
