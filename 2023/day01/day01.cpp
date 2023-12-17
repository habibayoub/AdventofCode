#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void processLine(const string& line, int& total) {
    string number = "";
    for (char c : line) {
        if (isdigit(c)) {
            number += c;
        }
    }
    total += (number.length() == 1) ? stoi(number + number) : stoi(number.substr(0, 1) + "" + number.substr(number.length() - 1, 1));
}

int main() {
    int total = 0;
    ifstream file("input.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            processLine(line, total);
        }
        file.close();
    }
    cout << total << "\n";
    return 0;
}