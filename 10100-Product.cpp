#include <iostream>
#include <vector>

using namespace std;



int main() {
    string x, y;

    vector<vector<int>> totalNumbers;

    int nx, ny;

    unsigned int bigNum = 0;

    cin >> x;
    cin >> y;

    if (x.length() <= y.length()) {
        for(unsigned int i = 0; i < x.length(); i++) {
            vector<int> number;
            nx = x[x.length()-1-i] - '0';
            int rest = 0;

            for (unsigned int zero = 0; zero < i; zero++) {
                number.push_back(0);
            }

            for(unsigned int j = 0; j < y.length()-1; j++) {
                ny = y[y.length()-1-j] - '0';
                if (ny*nx+rest >= 10) {
                    number.push_back((ny*nx+rest) % 10);
                    rest = 1;
                } else {
                    number.push_back(ny*nx+rest);
                }
            }
            ny = y[0] - '0';
            if (ny*nx+rest >= 10) {
                number.push_back((nx*ny+rest) % 10);
                number.push_back(((nx*ny+rest) - ((nx*ny+rest) % 10)) / 10);
            } else {
                number.push_back(nx*ny+rest);
            }
            totalNumbers.push_back(number);
            if (number.size() > bigNum) {
                bigNum = number.size();
            }
        }
    }
    for (unsigned int j = 0; j < totalNumbers.size(); j++) {
        unsigned int iter = bigNum - totalNumbers[j].size();
        for (unsigned int i = 0; i < iter; i++) {
            totalNumbers[j].push_back(0);
        }
    }
    unsigned int t = 0;
    int rest = 0, sum;
    vector<int> lastNumber;
    while (t < bigNum-1) {
        sum = rest;
        for (vector<int> num : totalNumbers) {
            sum += num[t];
        }
        if (sum >= 10) {
            lastNumber.push_back(sum % 10);
            rest = (sum - (sum % 10)) / 10;
        } else {
            lastNumber.push_back(sum);
            rest = 0;
        }
        t++;
    }

    sum = rest;

    for (vector<int> num:totalNumbers) {
        sum += num[bigNum-1];
    }

    lastNumber.push_back(sum);

    for (unsigned int num = 0; num < lastNumber.size(); num++) {
        cout << lastNumber[lastNumber.size()-1-num];
    }

}