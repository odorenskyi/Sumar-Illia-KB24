#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <ctime>
#include <sstream>
#include <bitset>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <regex>
#include "Modules/Sumar.h"

using namespace std;

vector<string> splitIntoWords(const string& content) {
    vector<string> words;
    stringstream ss(content);
    string word;
    while (ss >> word) {
        while (!word.empty() && ispunct(word.back())) {
            word.pop_back();
        }
        while (!word.empty() && ispunct(word.front())) {
            word.erase(0, 1);
        }
        if (!word.empty()) {
            words.push_back(word);
        }
    }
    return words;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    ifstream input("flows/input.txt");
    ofstream output("flows/output.txt");
    ofstream appendFile("flows/output.txt", ios::app);

    if (!input.is_open() || !output.is_open() || !appendFile.is_open()) {
        cout << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    string content((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());

    string authorName = "Ілля Сумар";
    string organization = "ЦНТУ";
    string city = "Кропивницький";
    string country = "Україна";
    string year = "2025";

    output << "Автор: " << authorName << endl;
    output << "Навчальний заклад: " << organization << endl;
    output << "Місто: " << city << endl;
    output << "Країна: " << country << endl;
    output << "Рік: " << year << endl << endl;

    output << "У файлі input.txt міститься " << content.size() << " символів." << endl << endl;

    vector<string> words = splitIntoWords(content);

    vector<string> keywords = {"програма", "модуль", "студент", "програміст"};
    for (const string& keyword : keywords) {
        string base = keyword.substr(0, 6);
        bool exactMatch = false;
        bool similarMatch = false;

        for (const string& w : words) {
            if (w == keyword) {
                exactMatch = true;
                break;
            }
            else if (w.size() >= base.size() && w.substr(0, base.size()) == base) {
                similarMatch = true;
            }
        }

        if (exactMatch) {
            output << "Слово \"" << keyword << "\" знайдено у файлі." << endl;
        } else if (similarMatch) {
            output << "Слово \"" << keyword << "\" не знайдено, але знайдено подібне." << endl;
        } else {
            output << "Слово \"" << keyword << "\" НЕ знайдено у файлі." << endl;
        }
    }

    int digitCount = 0;
    for (char c : content) {
        if (isdigit(c)) digitCount++;
    }

    time_t now = time(0);
    tm* localTime = localtime(&now);

    appendFile << endl;
    appendFile << "Кількість цифр у вхідному файлі: " << digitCount << endl;

    appendFile << "Дата й час допису: "
               << (localTime->tm_mday < 10 ? "0" : "") << localTime->tm_mday << "."
               << (localTime->tm_mon + 1 < 10 ? "0" : "") << localTime->tm_mon + 1 << "."
               << 1900 + localTime->tm_year << " "
               << (localTime->tm_hour < 10 ? "0" : "") << localTime->tm_hour << ":"
               << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << ":"
               << (localTime->tm_sec < 10 ? "0" : "") << localTime->tm_sec << endl;

    regex numberRegex(R"(([-+]?\d*\.?\d+))");
    sregex_iterator it(content.begin(), content.end(), numberRegex);
    sregex_iterator end;

    vector<double> numbers;
    while (it != end && numbers.size() < 4) {
        numbers.push_back(stod(it->str()));
        ++it;
    }

    if (numbers.size() < 4) {
        appendFile << "Недостатньо чисел у вхідному файлі для задачі 10.3." << endl;
    } else {
        double x = numbers[0], y = numbers[1], z = numbers[2];
        int b = static_cast<int>(numbers[3]);

        double result = s_calculation(x, y, z);
        appendFile << "Результат обчислення s_calculation(" << x << ", " << y << ", " << z << ") = " << result << endl;

        bitset<32> binaryB(b);
        appendFile << "Число b = " << b << " у двійковій системі: " << binaryB << endl;
    }

    input.close();
    output.close();
    appendFile.close();

    cout << "Програму виконано успішно!" << endl;
    return 0;
}
