#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

struct result {
    string name;
    int room, time;

    result(string n, int r, int t) : name(n), room(r), time(t) {}
};

class PriorityQueue {
    public:
        vector<pair<int, int>> arr;
        int sizeVal;
        PriorityQueue(int k, vector<pair<string, int>> lectures) {
            this->sizeVal = 0;
            for (int i = 0; i < k; i++) {
                this->enqueue(i, lectures[i].second);
            }
        }

        pair<int, int> front() {
            if (this->sizeVal == 0)
                throw new runtime_error("Attempted to access front value of empty priority queue");
        
            return this->arr[0];
        }

        void addTime(int time) {
            this->arr[0].second += time;
            this->percDown(0);
        }
        
    private:
        void enqueue(int index, int value) {
            this->arr.push_back(make_pair(index, value));
            this->sizeVal++;
            percUp(this->sizeVal - 1);
        }

        void dequeue() {
            swap(0, this->sizeVal - 1);
            this->sizeVal--;
            percDown(0);
        }
        void swap(int index1, int index2) {
            pair<int, int> temp = this->arr[index1];
            this->arr[index1] = this->arr[index2];
            this->arr[index2] = temp;
        }

        void percUp(int index) {
            if (index == 0) return;

            int pIndex = PARENT(index);

            if (this->arr[index].second < this->arr[pIndex].second) {
                swap(index, pIndex);
                percUp(pIndex);
            }
        }

        void percDown(int index) {
            int bestIndex = index;

            if (RIGHT(index) < this->sizeVal && this->arr[RIGHT(index)].second < this->arr[bestIndex].second)
                bestIndex = RIGHT(index);

            if (LEFT(index) < this->sizeVal && this->arr[LEFT(index)].second < this->arr[bestIndex].second)
                bestIndex = LEFT(index);

            if (bestIndex != index) {
                swap(bestIndex, index);
                percDown(bestIndex);
            }
        }

        int PARENT(int index) {
            return (index - 1) / 2;
        }

        int LEFT(int index) {
            return 2 * index + 1;
        }

        int RIGHT(int index) {
            return 2 * index + 2;
        }
};

bool compute(vector<pair<string, int>> lectures, vector<result*>& results, int n, int t, int k) {
    PriorityQueue* queue = new PriorityQueue(k, lectures);
    for (int i = 0; i < k; i++) {
        results.push_back(new result(lectures[i].first, i, 0));
    }

    for (int i = k; i < n; i++) {
        pair<int, int> front = queue->front();
        if (t - front.second < lectures[i].second)
            return false;
        
        queue->addTime(lectures[i].second);
        results.push_back(new result(lectures[i].first, front.first, front.second));
    }

    sort(results.begin(), results.end(), [](result* a, result* b) {
        return a->name.compare(b->name) < 0;
    });

    return true;
}

int main() {
    int n, t, k, totalTime = 0;
    cin >> n >> t;

    vector<pair<string, int>> lectures(n);
    vector<result*> results;

    for (int i = 0; i < n; i++) {
        cin >> lectures[i].first >> lectures[i].second;
        totalTime += lectures[i].second;
    }

    int min = ceil((double)totalTime / t);
    int max = n;

    while (max > min) {
        results.clear();
        int k = (max + min) / 2;
        if (compute(lectures, results, n, t, k))
            max = k;
        else
            min = k;
    }
    cout << min << endl;

    for (result* res : results) {
        cout << res->name << " " << res->room << " " << res->time << endl;
    }

    return 0;
}