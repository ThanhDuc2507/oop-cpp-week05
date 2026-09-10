#include <iostream>
using namespace std;

int main() {
    float scores[10] = {7.5, 8.0, 6.5, 9.5, 7.0, 9.0, 5.5, 7.5, 8.5, 4.5};
    float sum = 0;
    float average;

    for (int i = 0; i < 10; i++) {
        sum += scores[i];
    }

    average = sum / 10;

    cout << "Average score: " << average << endl;
    cout << "Students above average:" << endl;

    for (int i = 0; i < 10; i++) {
        if (scores[i] > average) {
            cout << "Student " << i + 1 << ": " << scores[i] << endl;
        }
    }

    return 0;
}