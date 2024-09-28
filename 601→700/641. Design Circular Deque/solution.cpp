#include <vector>
using namespace std;

class MyCircularDeque {
public:
    vector<int> v; // Vector to store the elements
    int front, back, sizee, capacity; // Front and back indices, size of deque, and its capacity

    // Constructor to initialize the circular deque with a specific capacity
    MyCircularDeque(int k) {
        v = vector<int>(k, -1); // Initialize vector with capacity k, default values set to -1
        front = 0; // Initial front position
        back = 0; // Initial back position
        sizee = 0; // Tracks current number of elements
        capacity = k; // Set capacity
    }
    
    // Inserts an element at the front of the deque
    bool insertFront(int value) {
        if (isFull()) {
            return false; // Cannot insert if full
        }

        front = (front == 0) ? capacity - 1 : front - 1; // Wrap around if at the beginning
        v[front] = value; // Insert the value at the front
        sizee++; // Increment size
        return true; // Insertion successful
    }
    
    // Inserts an element at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) {
            return false; // Cannot insert if full
        }

        v[back] = value; // Insert the value at the back
        back = (back + 1) % capacity; // Move back pointer, wrapping around if needed
        sizee++; // Increment size
        return true; // Insertion successful
    }
    
    // Deletes an element from the front of the deque
    bool deleteFront() {
        if (isEmpty()) {
            return false; // Cannot delete if empty
        }

        v[front] = -1; // Optional: clear the value
        front = (front + 1) % capacity; // Move front pointer, wrapping around if needed
        sizee--; // Decrement size
        return true; // Deletion successful
    }
    
    // Deletes an element from the rear of the deque
    bool deleteLast() {
        if (isEmpty()) {
            return false; // Cannot delete if empty
        }

        back = (back == 0) ? capacity - 1 : back - 1; // Move back pointer, wrapping around if at the beginning
        v[back] = -1; // Optional: clear the value
        sizee--; // Decrement size
        return true; // Deletion successful
    }
    
    // Gets the front element of the deque
    int getFront() {
        return isEmpty() ? -1 : v[front]; // Return -1 if empty, otherwise return front value
    }
    
    // Gets the rear element of the deque
    int getRear() {
        if (isEmpty()) return -1; // Return -1 if empty
        return (back == 0) ? v[capacity - 1] : v[back - 1]; // Return last valid element
    }
    
    // Checks if the deque is empty
    bool isEmpty() {
        return (sizee == 0); // Return true if size is zero
    }
    
    // Checks if the deque is full
    bool isFull() {
        return (sizee == capacity); // Return true if size is equal to capacity
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

/*
 * Approach:
 * The MyCircularDeque class implements a circular deque using a vector.
 * It maintains two pointers, front and back, to facilitate O(1) insertion 
 * and deletion from both ends of the deque. When the pointers reach the end 
 * of the vector, they wrap around to the beginning to utilize the available 
 * space, maintaining a circular structure.
 *
 * Complexity Analysis:
 * Time Complexity: O(1) for all operations (insertFront, insertLast, 
 * deleteFront, deleteLast, getFront, getRear, isEmpty, isFull).
 * Space Complexity: O(k), where k is the capacity of the deque, as it uses
 * a vector of size k to store the elements.
 */