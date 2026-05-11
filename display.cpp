#include "display.h"
#include "date.h"
#include <iostream>
#include <cstdio>
using namespace std;

void displayResult() {
    int  cmp;
    char d1buf[9], d2buf[9];

    cmp = compareDate(date1, date2);

    sprintf(d1buf, "%02d:%02d:%02d", date1.day, date1.month, date1.year);
    sprintf(d2buf, "%02d:%02d:%02d", date2.day, date2.month, date2.year);

    if      (cmp == 0) strcpy(history[historyCount].result, "Дати рівні");
    else if (cmp <  0) strcpy(history[historyCount].result, "Перша передує другій");
    else               strcpy(history[historyCount].result, "Друга передує першій");

    cout << "\nДати у хронологічному порядку:\n";
    if (cmp <= 0) {
        cout << "1. " << d1buf << "\n";
        cout << "2. " << d2buf << "\n";
    } else {
        cout << "1. " << d2buf << "\n";
        cout << "2. " << d1buf << "\n";
    }
    cout << "Результат: " << history[historyCount].result << "\n";

    if (historyCount < MAX_HISTORY) {
        history[historyCount].date1 = date1;
        history[historyCount].date2 = date2;
        historyCount++;
    }
}

void displayTable() {
    int  i;
    char d1buf[9], d2buf[9];

    if (historyCount == 0) {
        cout << "\nІсторія порівнянь порожня.\n";
        return;
    }

    cout << "\n";
    cout << "+-----+----------+----------+----------------------+\n";
    cout << "| #   | Дата 1   | Дата 2   | Результат            |\n";
    cout << "+-----+----------+----------+----------------------+\n";

    for (i = 0; i < historyCount; i++) {
        sprintf(d1buf, "%02d:%02d:%02d",
            history[i].date1.day,
            history[i].date1.month,
            history[i].date1.year);
        sprintf(d2buf, "%02d:%02d:%02d",
            history[i].date2.day,
            history[i].date2.month,
            history[i].date2.year);

        printf("| %-3d | %s | %s | %-20s |\n",
            i + 1, d1buf, d2buf, history[i].result);
    }

    cout << "+-----+----------+----------+----------------------+\n";
    cout << "Всього порівнянь: " << historyCount << "\n";
}
