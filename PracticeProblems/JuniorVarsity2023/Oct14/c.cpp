#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    int n, l, h;
    cin >> n >> l >> h;

    vector<int> profits(n + 1);
    profits[0] = 0;

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        profits[i] = p + profits[i - 1];
    }

    int maxSegment, minSegment;

    int segSize;
    bool notFound = true;
    for (segSize = l; segSize <= h && notFound; segSize++) {
        for (int starting = 0; starting <= n - 1 && notFound; starting++) {
            if (profits[starting] <= 0 && starting != 0) continue;

            int i;
            bool flag = true;
            for (i = starting + 1; i + segSize - 1 <= n; i += segSize) {
                if (profits[i + segSize - 1] - profits[i] <= 0) {
                    flag = false;
                    break;
                }
            }

            if (flag && (n + 1 == i || profits[n] - profits[i] > 0)) {
                maxSegment = (i - starting - 1) / segSize;
                if (starting != 0)
                    maxSegment++;
                if (n + 1 != i)
                    maxSegment++;
                notFound = false;
            }
        }
    }
    
    notFound = true;
    for (int maxSize = h; maxSize >= segSize && notFound; maxSize--) {
        int maxStarting = n % maxSize;
        for (int starting = 0; starting <= maxStarting && notFound; starting++) {
            if (profits[starting] <= 0 && starting != 0) continue;

            int i;
            bool flag = true;
            for (i = starting + 1; i + maxSize - 1 <= n; i += maxSize) {
                if (profits[i + maxSize - 1] - profits[i] <= 0) {
                    flag = false;
                    break;
                }
            }

            if (flag && (n + 1 == i || profits[n] - profits[i] > 0)) {
                minSegment = (i - starting - 1) / segSize;
                if (starting != 0)
                    minSegment++;
                if (n + 1 != i)
                    minSegment++;
                notFound = false;
            }
        }
    }

    cout << minSegment << " " << maxSegment << endl;
    return 0;
}