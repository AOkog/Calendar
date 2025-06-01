#include "calendardata.h"


CalendarData::CalendarData(){
    const QVector<QStringList> rows = {
        QStringList{ QStringLiteral("Verne Nilsen"), QStringLiteral("123") },
        QStringList{ QStringLiteral("Carlos Tang"), QStringLiteral("77") },
        QStringList{ QStringLiteral("Bronwyn Hawcroft"), QStringLiteral("119") },
        QStringList{ QStringLiteral("Alessandro Hanssen"), QStringLiteral("32") },
        QStringList{ QStringLiteral("Andrew John Bakken"), QStringLiteral("54") },
        QStringList{ QStringLiteral("Vanessa Weatherley"), QStringLiteral("85") },
        QStringList{ QStringLiteral("Rebecca Dickens"), QStringLiteral("17") },
        QStringList{ QStringLiteral("David Bradley"), QStringLiteral("42") },
        QStringList{ QStringLiteral("Knut Walters"), QStringLiteral("25") },
        QStringList{ QStringLiteral("Andrea Jones"), QStringLiteral("34") }
    };
    dateHoursEvents(rows);
    QStringList hourLabels;
    for (int i = 0; i <  current_date.rowCount(); ++i) {
        hourLabels << QString("%1:00").arg(i);  // "0:00", "1:00", etc.
    }
    current_date.setVerticalHeaderLabels(hourLabels);
}

void CalendarData::dateHoursEvents(const QVector<QStringList> &rows) {
    
    current_date.clear();
    QList<QStandardItem *> items;
    for (const QStringList &row : rows) {
        items.clear();
        for (const QString &text : row)
            items.append(new QStandardItem(text));
        current_date.appendRow(items);
    }
    
}

QStandardItemModel* CalendarData::getCurrentDate(){
    return &current_date;
}

void CalendarData::dateHoursEvents(const QMap<QDate, QMap<QString, QStringList>> &events, QDate current) {
    dateHoursEvents(events.value(current));
}

void CalendarData::dateHoursEvents(const QMap<QString, QStringList> &events) {
    current_date.clear();
     QList<QStandardItem *> items;
      
     for (auto it = events.begin(); it != events.end(); ++it) {
        QString time = it.key();
        QStringList events = it.value();
     }
     
     
     
     QStringList hourLabels;
    for (int i = 0; i <  current_date.rowCount(); ++i) {
        hourLabels << QString("%1:00").arg(i);  // "0:00", "1:00", etc.
    }
    current_date.setVerticalHeaderLabels(hourLabels);
}