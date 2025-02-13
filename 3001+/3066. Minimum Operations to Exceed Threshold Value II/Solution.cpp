class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            // Priority queue to store elements in ascending order
            priority_queue<long, vector<long>, greater<long>> pq(nums.begin(), nums.end());
    
            int operations = 0; // Count of operations performed
    
            // Continue operations until at least two elements are available and the smallest is less than k
            while (pq.size() >= 2 && pq.top() < k) {
                long x = pq.top(); pq.pop(); // Smallest element
                long y = pq.top(); pq.pop(); // Next smallest element
    
                // Apply the operation: min(x, y) * 2 + max(x, y)
                pq.push(min(x, y) * 2 + max(x, y));
                operations++; // Increment operation count
            }
    
            return operations;
        }
    }
    /*
    Approach Summary:
        This solution uses a priority queue to efficiently manage the smallest elements in the array. It iteratively applies the given operation to the two smallest 
        elements until all elements are at least k or only one element remains.
    
    Complexity Analysis:
        Time Complexity: O(N log N), where N is the number of elements, because each element is inserted into the priority queue once and potentially removed and reinserted during operations.
        
        Space Complexity: O(N), for storing all elements in the priority queue.
    */
    