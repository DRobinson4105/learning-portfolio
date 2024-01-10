#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;

    return true;
}

int primes[] = {
	2,
	3,
	5,
	7,
	11,
	13,
	17,
	19,
	23,
	29,
	31,
	37,
	41,
	43,
	47,
	53,
	59,
	61,
	67,
	71,
	73,
	79,
	83,
	89,
	97,
};

int gcd(int num1, int num2) {
    if (num2 == 0)
        return num1;

    return gcd(num2, num1 % num2);
}

int main() {
    ll n; cin >> n;
    ll num = 1;
    int i;
    for (i = 0; num < n; i++) {
        num *= primes[i];
    }
    num /= primes[--i];
    
    ll common, notCommon = num;

    for (int j = 0; j < i; j++)
        notCommon *= (primes[j] - 1) * 1.0 / primes[j];

    common = num - notCommon;

    ll factor = gcd(common, num);
    cout << (common / factor) << "/" << (num / factor) << endl;

    return 0;
}