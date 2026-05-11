#pragma once

#include <string>
using namespace std;

const int MAX_HISTORY = 100;

struct Date {
    int day;
    int month;
    int year;
};

struct Record {
    Date date1;
    Date date2;
    string result;
};

extern Date   date1;
extern Date   date2;
extern Record history[MAX_HISTORY];
extern int    historyCount;

void inputData();
bool isValidDate(const Date& d);
int  compareDate(const Date& a, const Date& b);
