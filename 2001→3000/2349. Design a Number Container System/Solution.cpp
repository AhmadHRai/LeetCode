class NumberContainers {
    public:
        // Map to store number -> min heap of indices
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numberToIndices;
        // Map to store index -> number
        unordered_map<int, int> indexToNumbers;
    
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            // Update index to number mapping
            indexToNumbers[index] = number;
    
            // Add index to the min heap for this number
            numberToIndices[number].push(index);
        }
        
        int find(int number) {
           // If number doesn't exist in our map
            if (numberToIndices.find(number) == numberToIndices.end()) {
                return -1;
            }
    
            // Get reference to min heap for this number
            auto& minHeap = numberToIndices[number];
    
            // Keep checking top element until we find valid index
            while (!minHeap.empty()) {
                int index = minHeap.top();
    
                // If index still maps to our target number, return it
                if (indexToNumbers[index] == number) {
                    return index;
                }
    
                // Otherwise remove this stale index
                minHeap.pop();
            }
    
            return -1;
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */

/*
Approach Summary:

    This solution uses two maps to efficiently manage the relationship between numbers and indices. The `numberToIndices` map stores numbers as keys and min heaps of 
    indices as values, allowing for quick retrieval of the smallest index for a given number. The `indexToNumbers` map ensures that indices are correctly mapped to their 
    current numbers, enabling the removal of stale indices.

Complexity Analysis:
    Time Complexity:
    - `change`: O(log N), where N is the number of indices for a given number, due to the push operation on the min heap.
    - `find`: O(N) in the worst case if all indices are stale, but typically O(log N) for finding the smallest valid index.
    
    Space Complexity: O(N), where N is the total number of indices, for storing the maps.
*/