#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void findNumber(const string& line, int& index) {

    if (isdigit(line[index])) {
        index++;
        findNumber(line, index);
    }
}

void processLine(const string& line, int& partNumberSum) {

    for (size_t i = 0; i < line.length(); i++) {
        if (isdigit(line[i])) {

        }
    }
    

    for (char c : line) {
        if (isdigit(c)) {
        }
    }
    
}

int main(){

    string line;
    ifstream file("input.txt");
    if (file.is_open()) {
        int partNumberSum = 0;
        while (getline(file, line)) {
            processLine(line, partNumberSum);
        }
        file.close();
        cout << "Total Sum: " << partNumberSum << endl;
    }
    return 0;
}