#include <iostream>
using namespace std;

int main() {
    float scores[10] = {7.5, 8.0, 6.5, 9.5, 7.0, 9.0, 5.5, 7.5, 8.5, 4.5};
    bool found = false;

    for (int i = 0; i < 10; i++) {
        if (scores[i] < 5.0) {
            cout << "First failing student: Student " << i + 1 << endl;
            cout << "Score: " << scores[i];
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "All students pass!";
    }

    return 0;
}