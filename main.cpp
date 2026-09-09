#include <iostream>
using namespace std;

int main() {
    int n;
    double scores[20];
    int pass = 0;
    int fail = 0;

    cout << "How many students? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter score for student " << i + 1 << ": ";
        cin >> scores[i];
    }

    for (int i = 0; i < n; i++) {
        if (scores[i] >= 5) {
            pass++;
        } else {
            fail++;
        }
    }

    cout << "===== STATISTICS =====" << endl;
    cout << "Passed: " << pass << " students" << endl;
    cout << "Failed: " << fail << " students" << endl;

    double passRate = (double)pass / n * 100;

    cout << "Pass rate: " << passRate << "%" << endl;

    return 0;
}