#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void findId(const string& line, int idLength, int& idTotal) {

    string temp = "";
    for (size_t i = 0; i < idLength; i++) {
        temp += line[i+5];
    }
    idTotal += stoi(temp);
}

void processLine(const string& line, int& idTotal) {

    map<string, int> my_map = { { "red", 12 },
                                { "blue", 14 },
                                { "green", 13 } };
    bool flag = true;
    for (size_t i = 8; i < line.length(); i++) {

        flag = true;
        string number = "";
        if (isdigit(line[i])) {

            number += line[i];
            int idLength = 0;
            if (isdigit(line[i+1])) { //check if number has 2 digits

                i++;
                number += line[i];
                if (line.find("red", i) - i == 2){
                    if ((number[0] - '0')* 10 + (number[number.length()-1] - '0') > my_map["red"]) {
                        flag = false;
                        break;
                    } 
                }
                else if (line.find("blue", i) - i == 2){
                    if ((number[0] - '0')* 10 + (number[number.length()-1] - '0') > my_map["blue"]) {
                        flag = false;
                        break;
                    } 
                }
                else if (line.find("green", i) - i == 2){
                    if ((number[0] - '0')* 10 + (number[number.length()-1] - '0') > my_map["green"]) {
                        flag = false;
                        break;
                    } 
                }
            } else { //single digit number
                if (line.find("red", i) - i == 2){
                    if ((number[0] - '0') > my_map["red"]) {
                        flag = false;
                        break;
                    }
                }
                else if (line.find("blue", i) - i == 2){
                    if ((number[0] - '0') > my_map["blue"]) {
                        flag = false;
                        break;
                    } 
                }
                else if (line.find("green", i) - i == 2){
                    if ((number[0] - '0') > my_map["green"]) {
                        flag = false;
                        break;
                    } 
                }
            }

        }
    }
    if (flag) { findId(line, line.find(":", 5) - 5, idTotal); } //if whole line succeeds, then add it's ID to total
}

int main(){
    string line;
    int idTotal = 0;
    ifstream file("input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            processLine(line, idTotal);
        }
        file.close();
    }
    cout << "idTotal: " << idTotal << endl;
    return 0;
}