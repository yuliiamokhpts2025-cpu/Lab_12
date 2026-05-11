#include "display.h"
#include "date.h"
#include <iostream>
#include <iomanip>
using namespace std;

void printDate(const Date& d) {
    if (d.day   < 10) cout << "0";
    cout << d.day << ":";
    if (d.month < 10) cout << "0";
    cout << d.month << ":";
    if (d.year  < 10) cout << "0";
    cout << d.year;
}

void displayResult() {
    int cmp;
    cmp = compareDate(date1, date2);

    if      (cmp == 0) history[historyCount].result = "Дати рівні";
    else if (cmp <  0) history[historyCount].result = "Перша передує другій";
    else               history[historyCount].result = "Друга передує першій";

    cout << "\nДати у хронологічному порядку:\n";
    if (cmp <= 0) {
        cout << "1. "; printDate(date1); cout << "\n";
        cout << "2. "; printDate(date2); cout << "\n";
    } else {
        cout << "1. "; printDate(date2); cout << "\n";
        cout << "2. "; printDate(date1); cout << "\n";
    }
    cout << "Результат: " << history[historyCount].result << "\n";

    if (historyCount < MAX_HISTORY) {
        history[historyCount].date1 = date1;
        history[historyCount].date2 = date2;
        historyCount++;
    }
}

void displayTable() {
    int i;

    if (historyCount == 0) {
        cout << "\nІсторія порівнянь порожня.\n";
        return;
    }

    cout << "\n";
    cout << "+-----+----------+----------+----------------------+\n";
    cout << "| #   | Дата 1   | Дата 2   | Результат            |\n";
    cout << "+-----+----------+----------+----------------------+\n";

    for (i = 0; i < historyCount; i++) {
        cout << "| " << setw(3) << left << i + 1 << " | ";
        printDate(history[i].date1);
        cout << " | ";
        printDate(history[i].date2);
        cout << " | " << setw(20) << left << history[i].result << " |\n";
    }

    cout << "+-----+----------+----------+----------------------+\n";
    cout << "Всього порівнянь: " << historyCount << "\n";
}
