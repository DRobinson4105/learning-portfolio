#include <bits/stdc++.h>

using namespace std;

struct DiaperBox {
    int size, capacity;
    double price;
    DiaperBox(int size, double price, int capacity) : size(size), price(price), capacity(capacity) {}
};

int main() {
    int T; cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int n, d; cin >> n >> d;
        vector<DiaperBox*> boxes(d);
        vector<int> wastes(n);

        for (int i = 0; i < d; i++) {
            int size, capacity;
            double price;
            cin >> size >> price >> capacity;

            boxes[i] = new DiaperBox(size, price, capacity);
        }

        for (int i = 0; i < n; i++)
            cin >> wastes[i];
        
        double lowest = numeric_limits<double>::max();;
        int boxNum;

        for (int i = 0; i < d; i++) {
            DiaperBox* box = boxes[i];
            double total = box->price;
            int curr = 0;
            int diapersLeft = box->size - 1;
            for (int waste : wastes) {
                if (waste > box->capacity) {
                    total = numeric_limits<double>::max();;
                    break;
                }
                if (curr + waste > box->capacity) {
                    curr = 0;
                    if (diapersLeft)
                        diapersLeft--;
                    else {
                        total += box->price;
                        diapersLeft = box->size - 1;
                    }
                }
                curr += waste;
            }
            if (curr > box->capacity) {
                curr = 0;
                if (diapersLeft)
                    diapersLeft--;
                else {
                    total += box->price;
                    diapersLeft = box->size - 1;
                }
            }
            if (total < lowest) {
                lowest = total;
                boxNum = i + 1;
            }
        }

        cout << fixed << setprecision(2);
        cout << "Diaper Scenario #" << t << ": Buying box " << boxNum << ", you spend $" << lowest << "." << endl;
    }
    return 0;
}