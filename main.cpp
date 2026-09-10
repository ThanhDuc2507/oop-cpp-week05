#include <iostream>
using namespace std;

int main() {
    float scores[10] = {7.5, 8.0, 6.5, 9.5, 7.0, 9.0, 5.5, 7.5, 8.5, 4.5};
    float highest = scores[0];
    float secondHighest = -1;

    for (int i = 1; i < 10; i++) {
        if (scores[i] > highest) {
            secondHighest = highest;
            highest = scores[i];
        } else if (scores[i] > secondHighest && scores[i] < highest) {
            secondHighest = scores[i];
        }
    }

    cout << "Highest score: " << highest << endl;
    cout << "Second highest score: " << secondHighest;

    return 0;
}