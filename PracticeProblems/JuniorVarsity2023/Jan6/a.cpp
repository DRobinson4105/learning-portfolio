#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int numDigits = 0;
unordered_set<int> digits;

void getDigits(ll num) {
    while (num) {
        numDigits++;
        digits.insert(num % 10);
        num /= 10;
    }
}

ll toLong(string s) {
    ll res = 0;
    for (char c : s) {
        res *= 10;
        res += c - '0';
    }
    return res;
}

int main() {
    ll num; cin >> num;
    getDigits(num);
    string numStr = to_string(num);
    if (digits.size() == 10) {
        cout << "Impossible" << endl;
        return 0;
    }

    string lowerNum, upperNum;
    int lowestDigit = 0, highestDigit = 9, lowestNonZero = 1;
    while (digits.count(lowestDigit)) lowestDigit++;
    while (digits.count(highestDigit)) highestDigit--;
    while (digits.count(lowestNonZero)) lowestNonZero++;

    // Lower
    if (numStr[0] != '1' || numStr == "1") {
        for (int i = numStr[0] - 1; i >= '0'; i--) {
            if (!digits.count(i - '0')) {
                lowerNum.push_back(i);
                break;
            }
        }
    }

    for (int i = 0; i < numDigits - 1; i++)
        lowerNum.push_back(highestDigit + '0');

    // Upper
    bool flag = true;
    if (numStr[0] != '9') {
        for (int i = numStr[0] + 1; i <= '9'; i++) {
            if (!digits.count(i - '0')) {
                upperNum.push_back(i);
                flag = false;
                break;
            }
        }
    }
    if ((numStr[0] != '9' && flag) || (numStr[0] == '9' && lowestNonZero != 0)) {
        upperNum.push_back(lowestNonZero + '0');
        upperNum.push_back(lowestDigit + '0');
    }

    for (int i = 0; i < numDigits - 1; i++)
        upperNum.push_back(lowestDigit + '0');
    
    int first = 0;
    while (first < lowerNum.length() - 1 && lowerNum[first] == '0')
        first++;
    if (first) lowerNum = lowerNum.substr(first, lowerNum.length() - first);

    ll lower = toLong(lowerNum);
    ll upper = toLong(upperNum);

    if (upper == 0 || num - lower < upper - num)
        cout << lower << endl;
    else if (upper - num < num - lower)
        cout << upper << endl;
    else
        cout << lower << " " << upper << endl;

    return 0;
}