#include <iostream>
using namespace std;

int main() {
    int n;

    do {
        cout << "How many students? ";
        cin >> n;

        if (n < 2 || n > 20) {
            cout << "Invalid number of students!" << endl;
            cout << "Please enter a number from 2 to 20." << endl;
        }

    } while (n < 2 || n > 20);

    return 0;
}