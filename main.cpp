#include <iostream>
using namespace std;

int main() {
    float scores[10] = {7.5, 8.0, 6.5, 9.5, 7.0, 9.0, 5.5, 7.5, 8.5, 4.5};

    int currentStreak = 0;
    int longestStreak = 0;

    for (int i = 0; i < 10; i++) {
        if (scores[i] > 5.0) {
            currentStreak++;

            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
            }
        } else {
            currentStreak = 0;
        }
    }

    cout << "Longest pass streak: " << longestStreak << " students";

    return 0;
}