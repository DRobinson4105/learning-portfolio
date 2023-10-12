#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int score = 0;
    int w, b, d, s, t;
    cin >> w >> b >> d >> s >> t;

    double x, y;
    int currScore;
    int mult;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;

        if (x * x + y * y < b * b) {
            score += 50;
            continue;
        }

        currScore = 0;

        if (x * x + y * y < d * d)
            mult = 2;
        else if (x * x + y * y < s * s)
            mult = 1;
        else
            continue;
        
        if (x > 0 && y > 0)
            currScore = ceil(abs(atan(y / x)) / (M_PI * 2) * w);
        else if (y > 0)
            currScore = ceil((abs(atan(x / y)) + M_PI_2) / (M_PI * 2) * w);
        else if (x > 0)
            currScore = ceil((abs(atan(x / y)) + M_PI + M_PI_2) / (M_PI * 2) * w);
        else 
            currScore = ceil((abs(atan(y / x)) + M_PI) / (M_PI * 2) * w);

        score += currScore * mult;
    }

    cout << score << endl;

    return 0;
}