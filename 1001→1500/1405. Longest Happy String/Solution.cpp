#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Priority queue to store characters and their counts in decreasing order
        priority_queue<pair<int, char>> pq;
        
        // Add each character with its count if greater than 0
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";  // String to store the result

        // Continue until no more valid characters are left
        while (!pq.empty()) {
            // Get the character with the highest remaining count
            auto [count1, char1] = pq.top();
            pq.pop();

            // Check for consecutive repetition of the same character
            if (result.size() >= 2 && result.back() == char1 && result[result.size() - 2] == char1) {
                if (pq.empty()) break;  // If no alternative character is available, stop

                // Retrieve the next highest count character to avoid repetition
                auto [count2, char2] = pq.top();
                pq.pop();

                // Add this character to the result
                result += char2;
                count2--;

                // If this character still has remaining count, push it back
                if (count2 > 0) pq.push({count2, char2});

                // Reinsert the most frequent character for later consideration
                pq.push({count1, char1});
            } else {
                // If no repetition issue, add the most frequent character
                result += char1;
                count1--;

                // Reinsert if the character still has remaining count
                if (count1 > 0) pq.push({count1, char1});
            }
        }

        return result;  // Return the constructed diverse string
    }
};

/*
Approach:
1. Use a Max-Heap to Maintain Character Counts:
   - Initialize a max-heap (`priority_queue`) to keep track of characters 'a', 'b', and 'c' along with their counts, prioritized by the highest count.
   - Each character and its count are pushed only if its count is greater than 0.

2. Build the Result String While Avoiding Consecutive Repetition:
   - Retrieve the character with the highest count, `char1`, and check the last two characters in `result` to avoid forming three consecutive identical characters.
   - If adding `char1` creates a sequence of three identical characters, add the second-most frequent character instead (obtained from the heap) and adjust its count.
   - Reinsert characters with remaining counts back into the heap to maintain order.

3. Continue Until No More Characters Can be Added:
   - The loop stops if no alternative characters are available, or if the max-heap is exhausted.

Complexity Analysis:
- Time Complexity: O((a + b + c) * log 3) ≈ O(a + b + c), since each operation in the heap has O(log 3) complexity (with at most three elements in the heap).
- Space Complexity: O(1), as only a few variables and a fixed-size max-heap are used.
*/
