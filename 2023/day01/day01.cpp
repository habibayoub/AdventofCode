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

            for (int i = 0; i < line.length(); i++) {
                if (isdigit(line[i])){
                    number += line[i];
                }
            }
            if (number.length() == 1){
                stringnum = number + number;
                total += stoi(stringnum);   
 
            } else {
                stringnum = number.substr(0, 1) + "" + number.substr(number.length() - 1, 1);
                total += stoi(stringnum);
            }

            
            cout << total << "\n";
        }
        file.close();
    }
    return 0;
}