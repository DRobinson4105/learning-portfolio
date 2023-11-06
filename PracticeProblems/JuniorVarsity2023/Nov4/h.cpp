#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

struct position {
    double x, y, t;

    position(int x, int y, int t) : x(x), y(y), t(t) {}
};

typedef vector<position*> vp;
typedef pair<double, double> pdd;
typedef long long ll;

double calcDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

pdd calcPosition(position* start, position* end, double currTime) {
    double ratio = (currTime - start->t) / (end->t - start->t);
    double resX = ((end->x - start->x) * ratio) + start->x;
    double resY = ((end->y - start->y) * ratio) + start->y;

    return make_pair(resX, resY);
}

int main() {
    int N, T;
    cin >> N >> T;
    int lastTime;
    int numGPSTimes;

    vp positions(N);

    for (int i = 0; i < N; i++) {
        int x, y, t;
        cin >> x >> y >> t;

        positions[i] = new position(x, y, t);
        lastTime = t;
    }

    double actualDist = 0;
    double gpsDist = 0;

    for (int i = 1; i < N; i++) {
        actualDist += calcDistance(positions[i]->x, positions[i]->y, positions[i - 1]->x, positions[i - 1]->y);
    }

    int currI = 1;
    pdd lastPos = make_pair(0, 0);
    for (int i = T; i < lastTime; i += T) {
        while (positions[currI]->t < i) currI++;
        pdd nextPos = calcPosition(positions[currI - 1], positions[currI], i);
        
        gpsDist += calcDistance(lastPos.first, lastPos.second, nextPos.first, nextPos.second);
        lastPos = nextPos;
    }

    gpsDist += calcDistance(lastPos.first, lastPos.second, positions[N - 1]->x, positions[N - 1]->y);

    double percent = ((actualDist - gpsDist) / actualDist) * 100;
    // cout << fixed;
    // cout << setprecision(5);
    cout << actualDist << endl;
    cout << gpsDist << endl;
    cout << percent << endl;
    return 0;
}