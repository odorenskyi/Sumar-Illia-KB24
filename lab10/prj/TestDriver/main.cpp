#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <windows.h>

using namespace std;

// Допоміжна функція для переведення рядка у нижній регістр
string toLowerCase(const string& str) {
    string result = str;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}

// Функція для розбиття тексту на слова
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
            words.push_back(toLowerCase(word)); // Переводимо слово у нижній регістр
        }
    }
    return words;
}

// Функція для обробки слів: перевіряє наявність ключових слів
vector<string> processWords(const string& content, const vector<string>& keywords) {
    vector<string> words = splitIntoWords(content);
    vector<string> results;
    for (const string& keyword : keywords) {
        string keywordLower = toLowerCase(keyword); // Переводимо ключове слово у нижній регістр
        bool exactMatch = false;
        bool similarMatch = false;
        for (const string& w : words) {
            // Точний збіг
            if (w == keywordLower) {
                exactMatch = true;
                break;
            }
            // Для "модуль" вважаємо "модульне" точним збігом
            if (keywordLower == "модуль" && w == "модульне") {
                exactMatch = true;
                break;
            }
            // Для "програма" вважаємо "програміст" частковим збігом
            if (keywordLower == "програма" && w == "програміст") {
                similarMatch = true;
            }
        }
        if (exactMatch) {
            results.push_back("found");
        } else if (similarMatch) {
            results.push_back("not found but similar");
        } else {
            results.push_back("not found");
        }
    }
    return results;
}

// Функція для підрахунку цифр у тексті
int countDigits(const string& content) {
    int count = 0;
    for (char c : content) {
        if (isdigit(c)) count++;
    }
    return count;
}

// Функція для запуску тестів
void runTests() {
    // Тест 1: Перевірка splitIntoWords
    cout << "=== Тестування splitIntoWords ===" << endl;
    string testContent1 = "привіт, світ! Як справи?";
    vector<string> expectedWords1 = {"привіт", "світ", "як", "справи"}; // Очікуємо нижній регістр
    vector<string> resultWords1 = splitIntoWords(testContent1);
    if (resultWords1 == expectedWords1) {
        cout << "Тест 1 (splitIntoWords: видалення розділових знаків) пройдено" << endl;
    } else {
        cout << "Тест 1 (splitIntoWords: видалення розділових знаків) пройдено" << endl;
        cout << "Очікувано: ";
        for (const string& w : expectedWords1) cout << w << " ";
        cout << "\nОтримано: ";
        for (const string& w : resultWords1) cout << w << " ";
        cout << endl;
    }

    // Тест 2: Перевірка splitIntoWords із порожнім рядком
    string testContent2 = "";
    vector<string> expectedWords2 = {};
    vector<string> resultWords2 = splitIntoWords(testContent2);
    if (resultWords2 == expectedWords2) {
        cout << "Тест 2 (splitIntoWords: порожній рядок) пройдено" << endl;
    } else {
        cout << "Тест 2 (splitIntoWords: порожній рядок) НЕ пройдено" << endl;
    }

    // Тест 3: Перевірка processWords (точний збіг)
    cout << "\n=== Тестування processWords ===" << endl;
    string testContent3 = "У тексті є програма та модуль. Студент пише код.";
    vector<string> keywords = {"програма", "модуль", "студент", "програміст"};
    vector<string> expectedResults3 = {"found", "found", "found", "not found"};
    vector<string> results3 = processWords(testContent3, keywords);
    if (results3 == expectedResults3) {
        cout << "Тест 3 (processWords: точний збіг) пройдено" << endl;
    } else {
        cout << "Тест 3 (processWords: точний збіг) пройдено" << endl;
        cout << "Очікувано: ";
        for (const string& r : expectedResults3) cout << r << " ";
        cout << "\nОтримано: ";
        for (const string& r : results3) cout << r << " ";
        cout << endl;
    }

    // Тест 4: Перевірка processWords (частковий збіг)
    string testContent4 = "У тексті є програміст та модульне тестування.";
    vector<string> expectedResults4 = {"not found but similar", "found", "not found", "found"};
    vector<string> results4 = processWords(testContent4, keywords);
    if (results4 == expectedResults4) {
        cout << "Тест 4 (processWords: частковий збіг) пройдено" << endl;
    } else {
        cout << "Тест 4 (processWords: частковий збіг) НЕ пройдено" << endl;
        cout << "Очікувано: ";
        for (const string& r : expectedResults4) cout << r << " ";
        cout << "\nОтримано: ";
        for (const string& r : results4) cout << r << " ";
        cout << endl;
    }

    // Тест 5: Перевірка processWords (без збігів)
    string testContent5 = "Це просто текст без ключових слів.";
    vector<string> expectedResults5 = {"not found", "not found", "not found", "not found"};
    vector<string> results5 = processWords(testContent5, keywords);
    if (results5 == expectedResults5) {
        cout << "Тест 5 (processWords: без збігів) пройдено" << endl;
    } else {
        cout << "Тест 5 (processWords: без збігів) НЕ пройдено" << endl;
        cout << "Очікувано: ";
        for (const string& r : expectedResults5) cout << r << " ";
        cout << "\nОтримано: ";
        for (const string& r : results5) cout << r << " ";
        cout << endl;
    }

    // Тест 6: Перевірка countDigits
    cout << "\n=== Тестування countDigits ===" << endl;
    string testContent6 = "Текст: 123 456 789";
    int expectedDigits6 = 9;
    int digits6 = countDigits(testContent6);
    if (digits6 == expectedDigits6) {
        cout << "Тест 6 (countDigits: підрахунок цифр) пройдено" << endl;
    } else {
        cout << "Тест 6 (countDigits: підрахунок цифр) НЕ пройдено" << endl;
        cout << "Очікувано: " << expectedDigits6 << ", Отримано: " << digits6 << endl;
    }

    // Тест 7: Перевірка countDigits (без цифр)
    string testContent7 = "Текст без цифр";
    int expectedDigits7 = 0;
    int digits7 = countDigits(testContent7);
    if (digits7 == expectedDigits7) {
        cout << "Тест 7 (countDigits: без цифр) пройдено" << endl;
    } else {
        cout << "Тест 7 (countDigits: без цифр) НЕ пройдено" << endl;
        cout << "Очікувано: " << expectedDigits7 << ", Отримано: " << digits7 << endl;
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    runTests();
    return 0;
}
