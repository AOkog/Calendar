#ifndef CALENDARDATA_H
#define CALENDARDATA_H

#include <QMap>
#include <QDate>
#include <QStringList>


class CalendarData {
private:
  QMap<QDate, QStringList> events;

public:
    void storeEvent();
    void removeEvent();
    void load();
    void save();




};
