#ifndef CALENDARDATA_H
#define CALENDARDATA_H

#include <QMap>
#include <QDate>
#include <QStringList>
#include <QStandardItemModel>
#include <QStringList>
#include <QVector>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
class CalendarData {
private:
  QMap<QDate, QMap<int, QStringList>> events_stored;
  QStandardItemModel current_date;
  QDate qcurrent;
  int longest_hour{0};
public:
    CalendarData();
    void storeEvent(int year, int month, int day, int hour, QString item);
    QDate removeEvent(int hour, int index);
    void load(QDate date);
    void writeFile();
    void readFile();
    int getLongest();
    QDate getQCurrent();
    QStandardItemModel* getCurrentDate();


};

#endif
