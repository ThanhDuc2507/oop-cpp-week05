#include <iostream>
using namespace std;

int main() {
    int n;
    double scores[20];

    cout << "How many students? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter score for student " << i + 1 << ": ";
        cin >> scores[i];
    }

    double highest = scores[0];
    double lowest = scores[0];

    for (int i = 1; i < n; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }

        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    cout << "Highest score: " << highest << endl;
    cout << "Lowest score: " << lowest << endl;

    return 0;
}