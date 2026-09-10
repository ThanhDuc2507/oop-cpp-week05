#include <iostream>
using namespace std;

int main() {
    float scores[10] = {7.5, 8.0, 6.5, 9.5, 7.0, 9.0, 5.5, 7.5, 8.5, 4.5};
    float x;
    int count = 0;

    cout << "Enter score: ";
    cin >> x;

    for (int i = 0; i < 10; i++) {
        if (scores[i] == x) {
            count++;
        }
    }

    cout << "Score " << x << " appears " << count << " times.";

    return 0;
}