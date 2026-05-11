#include <iostream>
#include "date.h"
#include "display.h"
using namespace std;

extern Date   date1;
extern Date   date2;
extern Record history[MAX_HISTORY];
extern int    historyCount;

int main() {
    int choice;

    cout << "========================================\n";
    cout << "  Порівняння дат (формат ДД:ММ:РР)\n";
    cout << "========================================\n";

    do {
        inputData();

        if (!isValidDate(date1) || !isValidDate(date2)) {
            cerr << "Помилка: введено некоректну дату.\n";
        } else {
            displayResult();
        }

        cout << "\nПорівняти ще раз? (1-так / 0-вихід): ";
        cin  >> choice;
        cout << "\n";

    } while (choice == 1);

    displayTable();

    return 0;
}
