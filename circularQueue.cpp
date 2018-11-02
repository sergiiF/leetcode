/*
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

    MyCircularQueue(k): Constructor, set the size of the queue to be k.
    Front: Get the front item from the queue. If the queue is empty, return -1.
    Rear: Get the last item from the queue. If the queue is empty, return -1.
    enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
    deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
    isEmpty(): Checks whether the circular queue is empty or not.
    isFull(): Checks whether the circular queue is full or not.

*/

#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : max_size(k){
        data.resize(max_size);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;

        if (tail == max_size - 1) tail = 0;
        else ++tail;
        data[tail] = value;
        if (head == -1) head = 0;
        ++size;

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;

        if (head == max_size - 1) head = 0;
        else ++head;
        --size;

        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return data[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == max_size;
    }

    private:
        vector <int> data;
        //int* head = nullptr;
        //int* tail = nullptr;
        int head = -1;
        int tail = -1;

        int size = 0;
        int max_size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */


 int main() {
     MyCircularQueue circularQueue = MyCircularQueue(3); // set the size to be 3
        assert (circularQueue.enQueue(2) == true);
        assert (circularQueue.Rear() == 2);
        assert (circularQueue.Front() == 2);

/*
        assert (circularQueue.enQueue(2) == true);
        assert (circularQueue.enQueue(3) == true);
        assert (circularQueue.enQueue(4) == false);
        assert (circularQueue.isFull() == true);
        assert (circularQueue.deQueue() == true);
        assert (circularQueue.enQueue(4) == true);
        assert (circularQueue.Rear() == 4);
*/
 }
