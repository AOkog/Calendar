#include "calendardata.h"

CalendarData::CalendarData(){
   QDate now = QDate::currentDate();
    load(now);
}

QStandardItemModel* CalendarData::getCurrentDate(){
    return &current_date;
}


void CalendarData::load(QDate current) {
    current_date.clear();
    const QMap<int, QStringList> events = events_stored.value(current);
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

void CalendarData::storeEvent(int year, int month, int day, int hour, QString item) {
    QDate event_date(year, month, day);
    if(events_stored.contains(event_date)) {
        QMap<int, QStringList> today = events_stored.value(event_date);
        today[hour].append(item);
        events_stored[event_date] = today;
    } else {
        QMap<int, QStringList> today;
        today.insert(hour, QStringList{item});
        events_stored.insert(event_date, today);
    }
}