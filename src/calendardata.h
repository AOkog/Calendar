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
    void storeEvent();
    void removeEvent();
    void load(QDate date);
    void save();
    void dateHoursEvents(const QVector<QStringList> &rows);
    void dateHoursEvents(const QMap<QDate, QMap<int, QStringList>> &events, QDate current);
    void dateHoursEvents(const QMap<int, QStringList> &events);
    QStandardItemModel* getCurrentDate();


};

#endif
