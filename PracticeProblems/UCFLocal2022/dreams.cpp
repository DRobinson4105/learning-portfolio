#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, k;
    cin >> t >> k;
    k--;
    int total = 0;
    int lastSegment;

    vector<int> tracks(t);
    for (int i = 0; i < t; i++) {
        cin >> tracks[i];
        total += tracks[i];
    }

    int days;
    cin >> days;
    for (int i = 0; i < days; i++) {
        int numSegments, time = 0;
        cin >> numSegments;

        for (int j = 0; j < numSegments; j++) {
            int segment;
            cin >> segment;

            if (j % 2 == 0) {
                time += segment;
            }
            else {
                int num = (int)(segment / total);
                time += tracks[k] * num;

                if (lastSegment != tracks[k])
                    time += (tracks[k] - lastSegment % tracks[k] > segment) ? segment : tracks[k] - lastSegment % tracks[k];
                
                int calc = segment - num * total - tracks[k] + lastSegment % tracks[k];
                if (calc > total - tracks[k]) {
                    time += calc - total + tracks[k];
                }
            }

            lastSegment = segment;
        }
        
        cout << time << endl;

    }

    return 0;
}