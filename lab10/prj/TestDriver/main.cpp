#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <windows.h>

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


vector<string> processWords(const string& content, const vector<string>& keywords) {
    vector<string> words = splitIntoWords(content);
    vector<string> results;
    for (const string& keyword : keywords) {
        string base = keyword.substr(0, 6);
        bool exactMatch = false;
        bool similarMatch = false;
        for (const string& w : words) {
            if (w == keyword) {
                exactMatch = true;
                break;
            } else if (w.size() >= base.size() && w.substr(0, base.size()) == base) {
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


int countDigits(const string& content) {
    int count = 0;
    for (char c : content) {
        if (isdigit(c)) count++;
    }
    return count;
}


void runTests() {

    string testContent1 = "� �������� �������� ��� ��������. ������� ������ ��� �������.";
    vector<string> keywords = {"��������", "������", "�������", "���������"};
    vector<string> expected1 = {"not found but similar", "found", "found", "not found"};
    vector<string> results1 = processWords(testContent1, keywords);
    if (results1 == expected1) {
        cout << "���� 1 (����� ���) ��������" << endl;
    } else {
        cout << "���� 1 (����� ���) �� ��������" << endl;
    }

    string testContent2 = "�����: 123 456 789";
    int expectedDigits2 = 9;
    int digits2 = countDigits(testContent2);
    if (digits2 == expectedDigits2) {
        cout << "���� 2 (��������� ����) ��������" << endl;
    } else {
        cout << "���� 2 (��������� ����) �� ��������" << endl;
    }
}

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    runTests();
    return 0;
}
