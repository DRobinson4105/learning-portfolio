#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DS {
    public:
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

    private:
        int* arr;
};

class Graph {
    vector<vector<int>> edges;
    int n;

    public:
        Graph(int n) {
            this->n = n;
        }

        void addEdge(int a, int b, int weight) {
            edges.push_back({weight, a, b});
        }

        int kruskalsMST() {
            DS ds(this->n);
            sort(edges.begin(), edges.end());

            int mstWeight = 0;
            for (vector<int> edge : edges) {
                int weight = edge[0];
                int a = edge[1];
                int b = edge[2];

                if (ds.find(a) != ds.find(b)) {
                    ds.merge(a, b);
                    mstWeight += weight;
                }
            }

            return mstWeight;
        }
};

int main() {
    return 0;
}