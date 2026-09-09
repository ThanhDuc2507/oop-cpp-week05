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

    cout << "===== STUDENT SCORES =====" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << scores[i] << endl;
    }

    return 0;
}