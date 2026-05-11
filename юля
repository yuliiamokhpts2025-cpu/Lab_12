#include "date.h"
#include <iostream>
using namespace std;

Date   date1;
Date   date2;
Record history[MAX_HISTORY];
int    historyCount = 0;

void inputData() {
    char sep;
    cout << "Введіть першу дату  (ДД:ММ:РР): ";
    cin >> date1.day >> sep >> date1.month >> sep >> date1.year;
    cout << "Введіть другу дату  (ДД:ММ:РР): ";
    cin >> date2.day >> sep >> date2.month >> sep >> date2.year;
}

bool isValidDate(const Date& d) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int fullYear;

    if (d.year < 0 || d.month < 1 || d.month > 12 || d.day < 1)
        return false;

    fullYear = d.year < 100 ? 2000 + d.year : d.year;
    if ((fullYear % 4 == 0 && fullYear % 100 != 0) || fullYear % 400 == 0)
        daysInMonth[1] = 29;

    return d.day <= daysInMonth[d.month - 1];
}

int compareDate(const Date& a, const Date& b) {
    if (a.year  != b.year)  return a.year  < b.year  ? -1 : 1;
    if (a.month != b.month) return a.month < b.month ? -1 : 1;
    if (a.day   != b.day)   return a.day   < b.day   ? -1 : 1;
    return 0;
}
