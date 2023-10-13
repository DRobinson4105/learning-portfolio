#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
    vector<int> arr;
    int sizeVal;
    
    public:
        PriorityQueue() : sizeVal(0) {}

        // Inserts a value into the priority queue
        void enqueue(int value) {
            this->arr.push_back(value);
            this->sizeVal++;
            percUp(this->sizeVal - 1);
        }

        // Returns the value of the front element
        int front() {
            if (this->sizeVal == 0)
                throw new runtime_error("Attempted to access front value of empty priority queue");
        
            return this->arr[0];
        }

        // Removes the front element
        void dequeue() {
            swap(0, this->sizeVal - 1);
            this->sizeVal--;
            percDown(0);
        }

        // Returns the size of the priority queue
        int size() {
            return this->sizeVal;
        }
        
    private:
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