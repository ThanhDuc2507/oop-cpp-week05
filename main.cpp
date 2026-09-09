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

    cout << "===== RESULTS =====" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << scores[i];

        if (scores[i] >= 5) {
            cout << " -> PASS" << endl;
        } else {
            cout << " -> FAIL" << endl;
        }
    }

    return 0;
}