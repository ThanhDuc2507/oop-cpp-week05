#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void displayAll(Flower flowers[], int n) {
    cout << "\n--- Danh sach tat ca cac loai hoa ---\n";
    cout << left << setw(15) << "Ten hoa" << setw(12) << "Gia" << setw(12) << "So luong" << setw(15) << "Loai" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << flowers[i].name 
             << setw(12) << flowers[i].price 
             << setw(12) << flowers[i].quantity 
             << setw(15) << flowers[i].type << endl;
    }
}

void findMostExpensive(Flower flowers[], int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].price > flowers[maxIdx].price) maxIdx = i;
    }
    cout << "\nHoa co gia cao nhat: " << flowers[maxIdx].name << " (" << flowers[maxIdx].price << ")\n";
}

void findCheapest(Flower flowers[], int n) {
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].price < flowers[minIdx].price) minIdx = i;
    }
    cout << "Hoa co gia re nhat: " << flowers[minIdx].name << " (" << flowers[minIdx].price << ")\n";
}

void findLargestQuantity(Flower flowers[], int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].quantity > flowers[maxIdx].quantity) maxIdx = i;
    }
    cout << "Hoa co so luong nhieu nhat: " << flowers[maxIdx].name << " (" << flowers[maxIdx].quantity << ")\n";
}

int calculateTotalQuantity(Flower flowers[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += flowers[i].quantity;
    return total;
}

double calculateAveragePrice(Flower flowers[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += flowers[i].price;
    return sum / n;
}

void processTypeQuery(Flower flowers[], int n) {
    string searchType;
    cout << "\nNhap loai hoa can tim: ";
    cin >> searchType;
    
    int count = 0;
    cout << "Cac hoa thuoc loai '" << searchType << "':\n";
    for (int i = 0; i < n; i++) {
        if (toLower(flowers[i].type) == toLower(searchType)) {
            cout << " - " << flowers[i].name << endl;
            count++;
        }
    }
    cout << "=> Tong so hoa thuoc loai '" << searchType << "': " << count << endl;
}

void searchByName(Flower flowers[], int n) {
    string searchName;
    cout << "\nNhap ten hoa can tim: ";
    cin >> searchName;
    
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (toLower(flowers[i].name) == toLower(searchName)) {
            cout << "=> Tieu chi [Check Exist]: YES (Hoa co trong danh sach)\n";
            cout << "Thong tin chi tiet: " << flowers[i].name 
                 << " | Gia: " << flowers[i].price 
                 << " | SL: " << flowers[i].quantity 
                 << " | Loai: " << flowers[i].type << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "=> Tieu chi [Check Exist]: NO (Khong tim thay hoa)\n";
}

void countLowQuantity(Flower flowers[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (flowers[i].quantity < 5) count++;
    }
    cout << "\nSo luong hoa co kho duoi 5: " << count << endl;
}

void countInPriceRange(Flower flowers[], int n) {
    double minP, maxP;
    cout << "\nNhap khoang gia (min max): ";
    cin >> minP >> maxP;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (flowers[i].price >= minP && flowers[i].price <= maxP) count++;
    }
    cout << "So loai hoa trong khoang gia [" << minP << " - " << maxP << "]: " << count << endl;
}

double calculateTotalValue(Flower flowers[], int n) {
    double totalValue = 0;
    for (int i = 0; i < n; i++) {
        totalValue += flowers[i].price * flowers[i].quantity;
    }
    return totalValue;
}

void findMostValuable(Flower flowers[], int n) {
    int maxIdx = 0;
    double maxVal = flowers[0].price * flowers[0].quantity;
    for (int i = 1; i < n; i++) {
        double val = flowers[i].price * flowers[i].quantity;
        if (val > maxVal) {
            maxVal = val;
            maxIdx = i;
        }
    }
    cout << "Hoa co tong gia tri lon nhat: " << flowers[maxIdx].name << " (" << maxVal << ")\n";
}

void sortByPrice(Flower flowers[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (flowers[i].price > flowers[j].price) {
                swap(flowers[i], flowers[j]);
            }
        }
    }
}

void sortByName(Flower flowers[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (toLower(flowers[i].name) > toLower(flowers[j].name)) {
                swap(flowers[i], flowers[j]);
            }
        }
    }
}

void findTop3Expensive(Flower tempFlowers[], int n) {
    Flower f[20];
    for(int i = 0; i < n; i++) f[i] = tempFlowers[i];
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (f[i].price < f[j].price) swap(f[i], f[j]);
        }
    }
    cout << "\nTop 3 hoa dat nhat:\n";
    int limit = min(3, n);
    for (int i = 0; i < limit; i++) {
        cout << i + 1 << ". " << f[i].name << " - Gia: " << f[i].price << endl;
    }
}

void searchKeyword(Flower flowers[], int n) {
    string kw;
    cout << "\nNhap tu khoa ten hoa: ";
    cin >> kw;
    cout << "Cac hoa co chua tu khoa '" << kw << "':\n";
    for (int i = 0; i < n; i++) {
        if (toLower(flowers[i].name).find(toLower(kw)) != string::npos) {
            cout << " - " << flowers[i].name << endl;
        }
    }
}

void generateReport(Flower flowers[], int n) {
    cout << "\n================ BAO CAO TONG QUAT ================\n";
    cout << "Tong so loai hoa: " << n << endl;
    cout << "Tong so luong hoa trong kho: " << calculateTotalQuantity(flowers, n) << endl;
    cout << "Tong gia tri kho hang: " << calculateTotalValue(flowers, n) << endl;
    
    cout << "\nThong ke trung binh so luong theo loai:\n";
    string types[20];
    int typeCount = 0;
    for (int i = 0; i < n; i++) {
        bool exists = false;
        for (int j = 0; j < typeCount; j++) {
            if (toLower(flowers[i].type) == toLower(types[j])) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            types[typeCount++] = flowers[i].type;
        }
    }

    for (int i = 0; i < typeCount; i++) {
        int sumQty = 0;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (toLower(flowers[j].type) == toLower(types[i])) {
                sumQty += flowers[j].quantity;
                count++;
            }
        }
        cout << " - Loai " << types[i] << ": Trung binh " << (double)sumQty / count << " cai/loai hoa (Gom " << count << " hoa)\n";
    }
    cout << "===================================================\n";
}

int main() {
    Flower flowers[20];
    int n;

    do {
        cout << "Nhap so luong loai hoa N (1 <= N <= 20): ";
        cin >> n;
    } while (n < 1 || n > 20);

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin hoa thu " << i + 1 << ":\n";
        cout << "Ten: "; cin >> flowers[i].name;
        
        do {
            cout << "Gia (> 0): "; cin >> flowers[i].price;
        } while (flowers[i].price <= 0);

        do {
            cout << "So luong (>= 0): "; cin >> flowers[i].quantity;
        } while (flowers[i].quantity < 0);

        cout << "Loai: "; cin >> flowers[i].type;
    }

    displayAll(flowers, n);
    findMostExpensive(flowers, n);
    findCheapest(flowers, n);
    findLargestQuantity(flowers, n);
    
    cout << "\nTong so luong hoa: " << calculateTotalQuantity(flowers, n) << endl;
    cout << "Gia trung binh: " << calculateAveragePrice(flowers, n) << endl;

    processTypeQuery(flowers, n);
    searchByName(flowers, n);
    countLowQuantity(flowers, n);
    countInPriceRange(flowers, n);

    cout << "\nTong gia tri tat ca hoa: " << calculateTotalValue(flowers, n) << endl;
    findMostValuable(flowers, n);

    findTop3Expensive(flowers, n);
    searchKeyword(flowers, n);

    sortByPrice(flowers, n);
    cout << "\n[Da sap xep tang dan theo Gia]";
    displayAll(flowers, n);

    sortByName(flowers, n);
    cout << "\n[Da sap xep A-Z theo Ten]";
    displayAll(flowers, n);

    generateReport(flowers, n);

    return 0;
}