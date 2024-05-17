#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countChar(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "�����޷����ļ�����" << filename << endl;
        return -1;
    }

    int charCount = 0;
    char c;
    while (file.get(c)) {
        ++charCount; 
    }

    file.close();
    return charCount;
}

int countWords(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "�����޷����ļ�����" << filename << endl;
        return -1;
    }

    int wordCount = 0;
    char c;
    bool is = false;
    while (file.get(c)) {
        if ((isspace(c) || c == ',') && is) { 
            ++wordCount;
        }
        else if (!is) { 
            is = true;
        }
    }

    file.close();
    return wordCount;
}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "������Ч���룡��" << endl;
        return 1;
    }

    string choice = argv[1];
    string filename = argv[2];

    if (choice == "-c") {
        cout << "�ַ�����" << countChar(filename) << endl;
    }
    else if (choice == "-w") {
        cout << "������: " << countWords(filename) << endl;
    }
    else {
        cerr << "������Чѡ�񣡣�" << endl;
        return 1;
    }

    return 0;
}