#include "struct_type_project_6.h"
#include "modulesKovalova.h"
#include "modulesOlefirov.h"
#include "modulesSumar.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
// Прототипи функцій з модулів


using namespace std;

int main() {
     SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "uk_UA.UTF-8");

    const string filename = "products.txt";
    Node* head = loadFromFile(filename);
    int choice;

    do {
        printMenu();
        cin >> choice;
        cin.ignore(); // Очистити буфер після введення числа

        switch (choice) {
            case 1:
                searchByCode(head);
                break;
            case 2:
                addProduct(head);
                break;
            case 3:
                deleteByCode(head);
                break;
            case 4:
                saveToFile(filename, head);
                cout << "💾 Довідник збережено.\n";
                break;
            case 5:
                saveToFile(filename, head);
                cout << "👋 Програма завершується. Дані збережено.\n";
                break;
            default:
                cout << "❌ Невірний вибір. Спробуйте ще раз.\n";
        }

    } while (choice != 5);

    freeList(head);
    return 0;
}
