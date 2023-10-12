#include <iostream>
#include <iomanip>

using namespace std;

double solveForIntersectX(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    return (((y2 - y1) / (x2 - x1)) * x1 - (y4 - y3) / (x4 - x3) *
            x3 + y3 - y1) / ((y2 - y1) / (x2 - x1) - (y4 - y3) / (x4 - x3));
}

double solveForX(double x1, double y1, double x2, double y2, double y) {
    return (y - y1 + (y2 - y1) / (x2 - x1) * x1) / ((y2 - y1) / (x2 - x1));
}

double solveForY(double x1, double y1, double x2, double y2, double x) {
    return (y2 - y1) / (x2 - x1) * (x - x1) + y1;
}

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    double intersectX = solveForIntersectX(x1, y1, x2, y2, x3, y3, x4, y4);
    if (intersectX > max(x1, x2) || intersectX < min(x1, x2) || intersectX > max(x3, x4) || intersectX < min(x3, x4)) {
        cout << 0.0 << endl;
        return 0;
    }

    double intersectY = solveForY(x1, y1, x2, y2, intersectX);

    double firstY = max(y1, y2);
    double secondY = max(y3, y4);
    double y = (firstY < secondY) ? firstY : secondY;

    double firstX = solveForX(x1, y1, x2, y2, y);
    double secondX = solveForX(x3, y3, x4, y4, y);

    cout << (abs(firstX - secondX) * abs(intersectY - y) / 2) << endl;

    return 0;
}