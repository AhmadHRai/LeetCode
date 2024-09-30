#include <vector>
using namespace std;

class CustomStack {
private:
    vector<int> stack;         // Vector to store the stack elements
    vector<int> increments;    // Vector to store increment values for elements in the stack
    int maxSize;              // Maximum size of the stack
public:
    // Constructor to initialize the stack with a given maxSize
    CustomStack(int maxSize) : maxSize(maxSize) {
        stack.reserve(maxSize); // Reserve space for maxSize to optimize memory usage
        increments.resize(maxSize, 0); // Initialize increments with zeros
    }
    
    // Pushes an element onto the stack if it's not full
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x); // Add element to the stack
        }
    }
    
    // Pops the top element from the stack and applies any increments
    int pop() {
        if (stack.empty()) {
            return -1; // Return -1 if the stack is empty
        }
        int index = stack.size() - 1; // Get index of the top element
        int value = stack.back() + increments[index]; // Calculate the value considering increments
        stack.pop_back(); // Remove the top element
        
        // Propagate the increment to the next element below
        if (index > 0) {
            increments[index - 1] += increments[index]; // Pass the increment down
        }
        
        increments[index] = 0; // Clear the increment for the popped element
        return value; // Return the computed value
    }
    
    // Increments the first k elements by val
    void increment(int k, int val) {
        int actualK = min(k, (int)stack.size()); // Determine the effective number of elements to increment
        if (actualK > 0) {
            increments[actualK - 1] += val; // Increment the last of the first k elements
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

/*
 * Approach:
 * The CustomStack class maintains a stack with support for increments on the first k elements. 
 * It uses two vectors: one for storing stack elements and another for managing increments. 
 * 
 * - `push(x)`: Adds an element x to the stack if it's not full. The time complexity is O(1).
 * 
 * - `pop()`: Removes and returns the top element of the stack. It also accounts for any increment that has 
 * been applied to that element. The time complexity is O(1) since it only performs a few constant-time operations.
 * 
 * - `increment(k, val)`: Increments the first k elements by val. It updates the increments array, ensuring 
 * that the last of the first k elements gets the added value. The time complexity is O(1) because it only 
 * involves a simple index operation.
 * 
 * Complexity Analysis:
 * Time Complexity: 
 * - O(1) for `push`, `pop`, and `increment` operations since they all execute in constant time.
 * 
 * Space Complexity:
 * - O(N), where N is the maximum size of the stack, for storing the stack elements and increments.
 */
