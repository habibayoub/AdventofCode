#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    int total = 0;
    ifstream file("input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            string number = "";
            string stringnum = "";
            string spelled[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
            string numeric[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
            string test = "one2three4five";

            for (size_t i = 0; i < 9; i++){
                size_t pos = line.find(spelled[i]);
                while (pos != -1){
                    line.replace(pos, spelled[i].length(), numeric[i]);
                    pos = line.find(spelled[i]);
                };
            }
                //cout << line << "\n";
            
            for (int i = 0; i < line.length(); i++) {
                if (isdigit(line[i])){
                    number += line[i];
                }
            }
            if (number.length() == 1){
                stringnum = number + number;
                total += stoi(number + number);   
                cout << stringnum << "\n";
 
            } else {
                stringnum = number.substr(0, 1) + "" + number.substr(number.length() - 1, 1);
                total += stoi(number.substr(0, 1) + "" + number.substr(number.length() - 1, 1));
                cout << stringnum << "\n";
            }

            
        }
        file.close();
    }
    cout << total << "\n";
    return 0;
}
