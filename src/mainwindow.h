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
class QLabel;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *label;
    CalendarData one;
};

#endif // MAINWINDOW_H
