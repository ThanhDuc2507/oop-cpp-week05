#include <iostream>
using namespace std;

int main() {
    float scores[10] = {7.5, 8.0, 6.5, 9.5, 7.0, 9.0, 5.5, 7.5, 8.5, 4.5};

    for (int i = 1; i < 10; i++) {
        if (scores[i] > scores[i - 1]) {
            cout << "Student " << i + 1 << " improved compared to Student " << i << endl;
        }
    }

    return 0;
}