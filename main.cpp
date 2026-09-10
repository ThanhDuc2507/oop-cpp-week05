#include <iostream>
using namespace std;

int main() {
    float scores[10] = {7.5, 8.0, 6.5, 9.5, 7.0, 9.0, 5.5, 7.5, 8.5, 4.5};

    int range1 = 0;
    int range2 = 0;
    int range3 = 0;
    int range4 = 0;
    int range5 = 0;

    for (int i = 0; i < 10; i++) {
        if (scores[i] < 5.0) {
            range1++;
        } else if (scores[i] < 6.5) {
            range2++;
        } else if (scores[i] < 8.0) {
            range3++;
        } else if (scores[i] < 9.0) {
            range4++;
        } else {
            range5++;
        }
    }

    cout << "----- SCORE DISTRIBUTION -----" << endl;
    cout << "0 - <5    : " << range1 << endl;
    cout << "5 - <6.5  : " << range2 << endl;
    cout << "6.5 - <8  : " << range3 << endl;
    cout << "8 - <9    : " << range4 << endl;
    cout << "9 - 10    : " << range5 << endl;

    return 0;
}