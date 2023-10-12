#include <iostream>
#include <vector>

using namespace std;

class DS {
    public:
        int* arr;

        DS(int n) {
            arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = -1;
        }

        int find(int x) {
            return (arr[x] < 0) ? x : (arr[x] = find(arr[x]));
        }

        void merge(int a, int b) {
            int p1 = find(a);
            int p2 = find(b);
            
            if (p1 == p2) return;

            arr[p1] += arr[p2];
            arr[p2] = p1;
        }
};

int main() {
    int n;
    cin >> n;
    
    char** types = new char*[n];
    int** colors = new int*[n];

    DS typeDS(n * n);
    DS colorDS(n * n);

    // Get input
    for (int i = 0; i < n; i++) {
        types[i] = new char[n];
        colors[i] = new int[n];

        for (int j = 0; j < n; j++) {
            cin >> types[i][j] >> colors[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i && types[i][j] == types[i - 1][j])
                typeDS.merge(i * n + j, (i - 1) * n + j);

            if (j && types[i][j] == types[i][j - 1])
                typeDS.merge(i * n + j, i * n + j - 1);

            if (i && colors[i][j] == colors[i - 1][j])
                colorDS.merge(i * n + j, (i - 1) * n + j);

            if (j && colors[i][j] == colors[i][j - 1])
                colorDS.merge(i * n + j, i * n + j - 1);
        }
    }

    vector<int> maxTypes(26);
    vector<int> maxColors(26);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int size = -typeDS.arr[i * n + j];
            if (size > maxTypes[types[i][j] - 'A'])
                maxTypes[types[i][j] - 'A'] = size;
            size = -colorDS.arr[i * n + j];
            if (size > maxColors[colors[i][j]])
                maxColors[colors[i][j]] = size;
        }
    }
    
    int maxType = 0;
    int maxColor = 0;
    for (int i = 0; i < 26; i++) {
        maxType += (maxTypes[i] * (maxTypes[i] - 1) / 2);
        maxColor += (maxColors[i] * (maxColors[i] - 1) / 2);
    }

    cout << maxType << " " << maxColor << endl;

    return 0;
}