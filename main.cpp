#include <iostream>
using namespace std;

int main() {
    int n;
    double scores[20];

    cout << "How many students? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        do {
            cout << "Enter score for student " << i + 1 << ": ";
            cin >> scores[i];

            if (scores[i] < 0 || scores[i] > 10) {
                cout << "Invalid score! Please enter a value from 0 to 10." << endl;
            }

        } while (scores[i] < 0 || scores[i] > 10);
    }

    return 0;
}