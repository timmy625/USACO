//Timothy Mathew
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> animals = {{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};
    map<string, int> M;
    map<string, string> years;
    M["Bessie"] = 0;
    years["Bessie"] = "Ox";
    for (int i = 0; i < n; i++) {
        string cow1, when, year, cow2, buffer;
        cin >> cow1 >> buffer >> buffer >> when >> year >> buffer >> buffer >> cow2;
        years[cow1] = year;
        int num1 = animals[years[cow1]];
        int num2 = animals[years[cow2]]; 
        if (when == "next") {
            if (num1 <= num2) {num1 += 12;}
            M[cow1] = (num1-num2) + M[cow2];
        } else {
            if (num1 >= num2) {num2 += 12;}
            M[cow1] = M[cow2] - (num2-num1);
        }
    }
  cout << abs(M["Elsie"]) << "\n";
  return 0;
}

