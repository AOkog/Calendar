#ifndef CALENDARDATA_H
#define CALENDARDATA_H

#include <QMap>
#include <QDate>
#include <QStringList>
#include <QStandardItemModel>
#include <QStringList>
#include <QVector>
#include <QDebug>
class CalendarData {
private:
  QMap<QDate, QMap<int, QStringList>> events_stored;
  QStandardItemModel current_date;
public:
    CalendarData();
    void storeEvent(int year, int month, int day, int hour, QString item);
    void removeEvent();
    void load(QDate date);
    void save();
    QStandardItemModel* getCurrentDate();


};

#endif
