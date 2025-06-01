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
  QMap<QDate, QMap<QString, QStringList>> events;
  QStandardItemModel current_date;
public:
    CalendarData();
    void storeEvent();
    void removeEvent();
    void load();
    void save();
    void dateHoursEvents(const QVector<QStringList> &rows);
    void dateHoursEvents(const QMap<QDate, QMap<QString, QStringList>> &events, QDate current);
    void dateHoursEvents(const QMap<QString, QStringList> &events);
    QStandardItemModel* getCurrentDate();


};

#endif
