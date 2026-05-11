#pragma once
#ifndef DATE_H
#define DATE_H

#define MAX_HISTORY 100

struct Date {
    int day;
    int month;
    int year;
};

struct Record {
    Date date1;
    Date date2;
    char result[30];
};

extern Date   date1;
extern Date   date2;
extern Record history[MAX_HISTORY];
extern int    historyCount;

void inputData();
bool isValidDate(const Date& d);
int  compareDate(const Date& a, const Date& b);

#endif
