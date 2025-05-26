#include "struct_type_project_6.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool isNumber(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

bool isAlphabetic(const string& str) {
    return !str.empty();
}

void addProduct(Node*& head) {
    Product p;
    cin.ignore();
    cout << "\n➕ Додавання нового запису:\n";

    while (true) {
        cout << "Номер розділу (тільки цифри): ";
        getline(cin, p.sectionNumber);
        if (isNumber(p.sectionNumber)) break;
        cout << "❌ Помилка! Введіть лише цифри.\n";
    }

    while (true) {
        cout << "Назва розділу (тільки літери): ";
        getline(cin, p.sectionName);
        if (isAlphabetic(p.sectionName)) break;
        cout << "❌ Помилка! Введіть лише літери.\n";
    }

    while (true) {
        cout << "Код товару (тільки цифри): ";
        getline(cin, p.productCode);
        if (isNumber(p.productCode)) break;
        cout << "❌ Помилка! Введіть лише цифри.\n";
    }

    while (true) {
        cout << "Назва товару (тільки літери): ";
        getline(cin, p.productName);
        if (isAlphabetic(p.productName)) break;
        cout << "❌ Помилка! Введіть лише літери.\n";
    }

    Node* newNode = new Node{p, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) current = current->next;
        current->next = newNode;
    }

    cout << "✔️ Запис додано.\n";
}

void deleteByCode(Node*& head) {
    string code;
    cout << "\n🗑️ Введіть код товару для видалення: ";
    cin >> code;

    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->data.productCode == code) {
            if (!prev) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "✅ Запис видалено.\n";
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "❌ Запис не знайдено.\n";
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
