#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void findSum(int& red, int& blue, int& green, int& sumOfPower) {

    sumOfPower += (red) * (blue) * (green);
}

void processLine(const string& line, int& sumOfPower) {

    int red = 0;
    int blue = 0;
    int green = 0;
    for (size_t i = 8; i < line.length(); i++) {

        string number = "";
        if (isdigit(line[i])) {

            number += line[i];
            int idLength = 0;
            if (isdigit(line[i+1])) { //check if number has 2 digits

                i++;
                number += line[i];
                if (line.find("red", i) - i == 2){
                    red = max((red), stoi(number));
                }
                else if (line.find("blue", i) - i == 2){
                    blue = max((blue), stoi(number));
                }
                else if (line.find("green", i) - i == 2){
                    green = max((green), stoi(number)); 
                }
            } else { //single digit number
                if (line.find("red", i) - i == 2){
                    red = max((red), stoi(number));
                }
                else if (line.find("blue", i) - i == 2){
                    blue = max((blue), stoi(number));
                }
                else if (line.find("green", i) - i == 2){
                    green = max((green), stoi(number)); 
                }
            }

        }
    }
    findSum(red, blue, green, sumOfPower);
}

int main(){
    string line;
    int sumOfPower = 0;
    ifstream file("input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            processLine(line, sumOfPower);
        }
        file.close();
    }
    cout << "totalSum: " << sumOfPower << endl;
    return 0;
}