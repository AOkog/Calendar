#include "calendardata.h"

CalendarData::CalendarData(){
   QDate now = QDate::currentDate();
    load(now);
}

QStandardItemModel* CalendarData::getCurrentDate(){
    return &current_date;
}

int CalendarData::getLongest(){
    return longest_hour;
}

QDate CalendarData::getQCurrent(){
    return qcurrent;
}

void CalendarData::load(QDate current) {
    current_date.clear();
    longest_hour = 0;
    const QMap<int, QStringList> events = events_stored.value(current);
    QList<QStandardItem*> items;
    QStringList hourLabels;
    for (auto it = events.begin(); it != events.end(); ++it) {
        int time = it.key();
        hourLabels << QString("%1:00").arg(time);
        QStringList event_list = it.value();
        items.clear();
        if(event_list.size() > longest_hour) {
            longest_hour = event_list.size();
        }
        for (const QString &text : event_list) {
            QStandardItem *item = new QStandardItem(text);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            items.append(item);
        }
        current_date.appendRow(items);
    }
    current_date.setVerticalHeaderLabels(hourLabels);
    qcurrent = current;
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


QDate CalendarData::removeEvent(int hour, int index){
    if(events_stored.contains(qcurrent) && !events_stored[qcurrent].isEmpty()){
        if(events_stored[qcurrent].contains(hour) && !events_stored[qcurrent][hour].isEmpty()) {
            if(events_stored[qcurrent][hour].size() > 1) {
                events_stored[qcurrent][hour].removeAt(index-1);
            } else {
                events_stored[qcurrent].remove(hour);
            }
        } else {
            events_stored[qcurrent].remove(hour);
        }
    } else {
        events_stored.remove(qcurrent);
    }
    return qcurrent;
}

void CalendarData::writeFile(){
    QString path = QCoreApplication::applicationDirPath() + "/data.txt";
    QFile file(path);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for(QDate date : events_stored.keys()) {
            out << date.toString(Qt::ISODate) << "\n";
            for(int hours : events_stored[date].keys()) {
                out << " " << hours << ":" << events_stored[date][hours].join("|") << "\n";
            }
        }
        file.close();
    }
}

void CalendarData::readFile() {
    QString path = QCoreApplication::applicationDirPath() + "/data.txt";
    QFile file(path);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QDate cDate;

        while(!in.atEnd()) {
            QString line = in.readLine().trimmed();

            if(!line.contains(":")) {
                cDate = QDate::fromString(line, Qt::ISODate);
            } else {
                QStringList parts = line.split(":");
                int hour = parts[0].trimmed().toInt();
                 QStringList events = parts[1].split("|", Qt::SkipEmptyParts);
                events_stored[cDate][hour] = events;
            }
        }
    }
}

