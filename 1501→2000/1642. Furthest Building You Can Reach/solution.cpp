// Define a class named Solution
class Solution {
public:
    // Define a function that takes four parameters: a vector of integers representing the heights of the buildings, an integer representing the number of bricks available, an integer representing the number of ladders available, and returns an integer representing the furthest building that can be reached
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // Get the size of the heights vector and store it in a variable named n
        int n = heights.size();
        // Declare a priority queue of integers with the greater comparator, which means the smallest element will be at the top of the queue. This will store the differences between the heights of adjacent buildings that require a ladder
        priority_queue<int, vector<int>, greater<int>> pq;
        // Loop through the heights vector from the first element to the second last element
        for (int i = 0; i < n - 1; ++i) {
            // Calculate the difference between the height of the next building and the current building and store it in a variable named diff
            int diff = heights[i + 1] - heights[i];
            // If the difference is positive, it means we need to climb up to the next building
            if (diff > 0) {
                // If the size of the priority queue is less than the number of ladders available, we can use a ladder to climb up to the next building and push the difference to the priority queue
                if (pq.size() < ladders) {
                    pq.push(diff);
                // Else, if the priority queue is full or empty, we need to use bricks to climb up to the next building
                } else {
                    // If the priority queue is empty or the top element of the priority queue is greater than or equal to the difference, we can use bricks to cover the difference and reduce the number of bricks by the difference
                    if (pq.empty() || pq.top() >= diff) {
                        bricks -= diff;
                    // Else, if the top element of the priority queue is less than the difference, we can swap the top element with the difference, which means we use a ladder for the larger difference and bricks for the smaller difference, and reduce the number of bricks by the top element
                    } else {
                        int poll = pq.top(); pq.pop();
                        pq.push(diff);
                        bricks -= poll;
                    }
                    // If the number of bricks becomes negative, it means we cannot climb up to the next building, so we return the current index as the furthest building that can be reached
                    if (bricks < 0) return i;
                }
            }
        }
        // If we reach the end of the loop, it means we can climb up to the last building, so we return n - 1 as the furthest building that can be reached
        return n - 1;
    }
};


/* 
Complexity:
    The time complexity of this solution is O(n log k), where n is the number of buildings and k is the number of ladders. This is because we iterate through the heights vector once, 
    and for each positive difference, we push or pop from the priority queue, which takes O(log k) time.
    
    The space complexity of this solution is O(k), where k is the number of ladders. This is because we use a priority queue to store at most k differences.
 */