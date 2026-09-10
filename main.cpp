#include <iostream>
using namespace std;

int main() {
    float scores[10] = {7.5, 8.0, 6.5, 9.5, 7.0, 9.0, 5.5, 7.5, 8.5, 4.5};
    float a, b;
    int count = 0;

    cout << "Enter minimum score: ";
    cin >> a;

    cout << "Enter maximum score: ";
    cin >> b;

    for (int i = 0; i < 10; i++) {
        if (scores[i] >= a && scores[i] <= b) {
            count++;
        }
    }

    cout << "Students in range: " << count;

    return 0;
}