#include <iostream>
using namespace std;

int main() {
    float scores[10] = {7.5, 8.0, 6.5, 9.5, 7.0, 9.0, 5.5, 7.5, 8.5, 4.5};
    float x;
    bool found = false;

    cout << "Enter score to search: ";
    cin >> x;

    for (int i = 0; i < 10; i++) {
        if (scores[i] == x) {
            cout << "Student " << i + 1 << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Score not found";
    }

    return 0;
}