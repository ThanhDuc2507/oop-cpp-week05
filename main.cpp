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

    cout << "===== CLASSIFICATION =====" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << scores[i] << " -> ";

        if (scores[i] >= 9) {
            cout << "Excellent";
        } else if (scores[i] >= 8) {
            cout << "Very Good";
        } else if (scores[i] >= 6.5) {
            cout << "Good";
        } else if (scores[i] >= 5) {
            cout << "Average";
        } else {
            cout << "Fail";
        }

        cout << endl;
    }

    return 0;
}