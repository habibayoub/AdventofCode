#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void processLine(string& line, int& total) {

    string spelled[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string numeric[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    for (size_t i = 0; i < 9; i++){
        size_t pos = line.find(spelled[i]);
        while (pos != -1){
            line.replace(pos, spelled[i].length(), numeric[i]);
            pos = line.find(spelled[i]);
        };
    }

    string number = "";
    for (char c : line) {
        if (isdigit(c)) {
            number += c;
        }
    }
    total += (number.length() == 1) ? stoi(number + number) : stoi(number.substr(0, 1) + "" + number.substr(number.length() - 1, 1));
}

int main() {
    string line;
    int total = 0;
    ifstream file("input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            processLine(line, total);
        }
        file.close();
    }
    cout << total << "\n";
    return 0;
}
