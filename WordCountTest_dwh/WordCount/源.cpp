#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countChar(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "！！无法打开文件！！" << filename << endl;
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
        cerr << "！！无法打开文件！！" << filename << endl;
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
        cerr << "！！无效输入！！" << endl;
        return 1;
    }

    string choice = argv[1];
    string filename = argv[2];

    if (choice == "-c") {
        cout << "字符数：" << countChar(filename) << endl;
    }
    else if (choice == "-w") {
        cout << "单词数: " << countWords(filename) << endl;
    }
    else {
        cerr << "！！无效选择！！" << endl;
        return 1;
    }

    return 0;
}