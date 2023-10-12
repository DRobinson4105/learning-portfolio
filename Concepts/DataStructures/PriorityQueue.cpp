#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
    public:
        PriorityQueue() : sizeVal(0) {}

        void enqueue(int value) {
            this->arr.push_back(value);
            this->sizeVal++;
            percUp(this->sizeVal - 1);
        }

        int front() {
            if (this->sizeVal == 0)
                throw new runtime_error("Attempted to access front value of empty priority queue");
        
            return this->arr[0];
        }

        void dequeue() {
            swap(0, this->sizeVal - 1);
            this->sizeVal--;
            percDown(0);
        }

        int size() {
            return this->sizeVal;
        }
    private:
        vector<int> arr;
        int sizeVal;

        void swap(int index1, int index2) {
            int temp = this->arr[index1];
            this->arr[index1] = this->arr[index2];
            this->arr[index2] = temp;
        }

        void percUp(int index) {
            if (index == 0) return;

            int pIndex = PARENT(index);

            if (this->arr[index] < this->arr[pIndex]) {
                swap(index, pIndex);
                percUp(pIndex);
            }
        }

        void percDown(int index) {
            int bestIndex = index;

            if (LEFT(index) < this->sizeVal && this->arr[LEFT(index)] < this->arr[bestIndex])
                bestIndex = LEFT(index);

            if (RIGHT(index) < this->sizeVal && this->arr[RIGHT(index)] < this->arr[bestIndex])
                bestIndex = RIGHT(index);

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

int main() {
    PriorityQueue* queue = new PriorityQueue();

    queue->enqueue(3);
    queue->enqueue(5);
    queue->enqueue(4);
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(2);

    for (int i = 0; i < 5; i++) {
        cout << queue->front();
        queue->dequeue();
    }
    
    return 0;
}