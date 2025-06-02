#include "calendardata.h"

CalendarData::CalendarData(){
   QDate now = QDate::currentDate();
    load(now);
}

QStandardItemModel* CalendarData::getCurrentDate(){
    return &current_date;
}

void CalendarData::dateHoursEvents(const QMap<QDate, QMap<int, QStringList>> &events, QDate current) {
    dateHoursEvents(events.value(current));
}

void CalendarData::dateHoursEvents(const QMap<int, QStringList> &events) {
    current_date.clear();
    QList<QStandardItem*> items;
    QStringList hourLabels;
    for (auto it = events.begin(); it != events.end(); ++it) {
        int time = it.key();
        hourLabels << QString("%1:00").arg(time);
        QStringList event_list = it.value();
        items.clear();
        for (const QString &text : event_list)
            items.append(new QStandardItem(text));
        current_date.appendRow(items);
    }
    current_date.setVerticalHeaderLabels(hourLabels);
}

void CalendarData::load(QDate date) {
    QDate today = QDate::currentDate();
    QDate todayagain(2025, 6, 2);
     QDate todayagai(2025, 6, 5);
      QDate todayaga(2025, 6, 6);
    QMap<int, QStringList> today_test;
    QStringList event_what_if = {"one is a very long sentence that will take up a lot of the screen", "two", "three"};
    today_test.insert(5, event_what_if);
      today_test.insert(23, event_what_if);
    events_stored.insert(todayagain, today_test);
    events_stored.insert(todayaga, today_test);
    events_stored.insert(todayagai, today_test);
    dateHoursEvents(events_stored, date);
}