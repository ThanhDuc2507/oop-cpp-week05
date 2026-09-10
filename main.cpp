#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};

int main() {
    Flower flowers[20];
    int n;

    do {
        cout << "How many flowers? ";
        cin >> n;

        if (n < 1 || n > 20) {
            cout << "Invalid number! Enter from 1 to 20.\n";
        }
    } while (n < 1 || n > 20);

    for (int i = 0; i < n; i++) {
        cout << "\nFlower " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> flowers[i].name;

        do {
            cout << "Price: ";
            cin >> flowers[i].price;

            if (flowers[i].price <= 0) {
                cout << "Price must be greater than 0!\n";
            }
        } while (flowers[i].price <= 0);

        do {
            cout << "Quantity: ";
            cin >> flowers[i].quantity;

            if (flowers[i].quantity < 0) {
                cout << "Quantity must be greater than or equal to 0!\n";
            }
        } while (flowers[i].quantity < 0);

        cout << "Type: ";
        cin >> flowers[i].type;
    }

    cout << "\n========== FLOWER SHOP ==========\n";
    cout << left << setw(5) << "No"
         << setw(15) << "Name"
         << setw(12) << "Price"
         << setw(10) << "Qty"
         << setw(15) << "Type" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << i + 1
             << setw(15) << flowers[i].name
             << setw(12) << fixed << setprecision(1) << flowers[i].price
             << setw(10) << flowers[i].quantity
             << setw(15) << flowers[i].type << endl;
    }

    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (flowers[i].price > flowers[maxIndex].price) {
            maxIndex = i;
        }

        if (flowers[i].price < flowers[minIndex].price) {
            minIndex = i;
        }
    }

    int totalQuantity = 0;
    double totalPrice = 0;

    for (int i = 0; i < n; i++) {
        totalQuantity += flowers[i].quantity;
        totalPrice += flowers[i].price;
    }

    double averagePrice = totalPrice / n;

    cout << "\n========== ANALYSIS ==========\n";
    cout << "Most expensive flower: "
         << flowers[maxIndex].name << " ("
         << flowers[maxIndex].price << ")\n";

    cout << "Cheapest flower: "
         << flowers[minIndex].name << " ("
         << flowers[minIndex].price << ")\n";

    cout << "Total quantity: " << totalQuantity << endl;
    cout << "Average price: " << averagePrice << endl;

    cout << "\n========== COUNT BY TYPE ==========\n";

    for (int i = 0; i < n; i++) {
        bool appeared = false;

        for (int j = 0; j < i; j++) {
            if (flowers[i].type == flowers[j].type) {
                appeared = true;
                break;
            }
        }

        if (!appeared) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (flowers[j].type == flowers[i].type) {
                    count++;
                }
            }

            cout << flowers[i].type << " : " << count << endl;
        }
    }

    char choice;

    do {
        cout << "\nEnter flower name to search: ";
        string searchName;
        cin >> searchName;

        bool found = false;

        for (int i = 0; i < n; i++) {
            if (flowers[i].name == searchName) {
                cout << "\nFound!\n";
                cout << "Price: " << flowers[i].price << endl;
                cout << "Quantity: " << flowers[i].quantity << endl;
                cout << "Type: " << flowers[i].type << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Flower not found!\n";
        }

        cout << "\nSearch again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}