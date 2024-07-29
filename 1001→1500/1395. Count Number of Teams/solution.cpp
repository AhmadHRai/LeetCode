#include <vector>
using namespace std;

class Solution {
public:
    // Function to count the number of valid teams
    int numTeams(vector<int>& rating) {
        int n = rating.size(); // Get the size of the rating array
        int count = 0;        // Initialize the count of valid teams
        
        // Traverse through each soldier as the middle soldier
        for (int j = 0; j < n; ++j) {
            int left_smaller_count = 0; // Count of soldiers to the left with a smaller rating
            int left_larger_count = 0;  // Count of soldiers to the left with a larger rating
            int right_smaller_count = 0; // Count of soldiers to the right with a smaller rating
            int right_larger_count = 0;  // Count of soldiers to the right with a larger rating

            // Count how many soldiers before index j have rating < rating[j]
            // and how many have rating > rating[j]
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    ++left_smaller_count; // Increment count for smaller ratings on the left
                } else if (rating[i] > rating[j]) {
                    ++left_larger_count;  // Increment count for larger ratings on the left
                }
            }

            // Count how many soldiers after index j have rating < rating[j]
            // and how many have rating > rating[j]
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) {
                    ++right_smaller_count; // Increment count for smaller ratings on the right
                } else if (rating[k] > rating[j]) {
                    ++right_larger_count;  // Increment count for larger ratings on the right
                }
            }

            // Calculate the number of valid teams with rating[j] as the middle soldier
            count += left_smaller_count * right_larger_count; // Teams where rating[j] is the middle soldier and increasing sequence
            count += left_larger_count * right_smaller_count; // Teams where rating[j] is the middle soldier and decreasing sequence
        }
        
        return count; // Return the total count of valid teams
    }
};

/*
Approach:
1. **Initialize Counters**: For each soldier considered as the middle soldier, initialize counters for soldiers to the left and right with ratings smaller and larger than the current soldier.
2. **Count Valid Teams**:
   - **Left Side Counting**: For each soldier, count how many soldiers before them have ratings smaller and larger than themselves.
   - **Right Side Counting**: Count how many soldiers after them have ratings smaller and larger.
   - **Calculate Valid Teams**: Compute the number of valid teams using combinations of these counts, where the current soldier is the middle soldier.

Complexity Analysis:
1. **Time Complexity**:
   - **Nested Loops**: For each soldier (middle soldier), two nested loops iterate over the left and right sides respectively, leading to a time complexity of O(n^2), where n is the number of soldiers.

2. **Space Complexity**:
   - **Auxiliary Space**: The solution uses a constant amount of extra space for counters, leading to a space complexity of O(1).

Overall, the solution is efficient for smaller input sizes but may become slower for larger values of n due to the quadratic time complexity.
*/
