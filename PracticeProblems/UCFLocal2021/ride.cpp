#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

double calcTime(double velocity, double distance) {
    return velocity - sqrt(velocity * velocity - 2 * distance);
}

bool validBoost(double boostAmt, int timeLimit, vector<int> boosts,
                    int numBoosts, int rideLength) {
    double time;
    double currSpeed = 0;
    double totalTime = 0;

    for (int i = 1; i < numBoosts; i++) {
        currSpeed += boostAmt;
        time = calcTime(currSpeed, boosts[i] - boosts[i - 1]);
        totalTime += time;

        if (isnan(time))
            return false;

        currSpeed -= time;
    }

    currSpeed += boostAmt;
    time = calcTime(currSpeed, rideLength - boosts[numBoosts - 1]);
    return (!isnan(time) && totalTime + time <= timeLimit);
}

int main() {
    cout << fixed;
    cout << setprecision(6);

    int L, n, t;
    cin >> L >> n >> t;

    vector<int> boosts(n);
    for (int i = 0; i < n; i++)
        cin >> boosts[i];

    double hi = L;
    double lo = 0;

    while (hi - lo > 1e-7) {
        double mid = (hi + lo) / 2;

        if (validBoost(mid, t, boosts, n, L))
            hi = mid;
        else
            lo = mid;
    }

    cout << hi << endl;
    return 0;
}