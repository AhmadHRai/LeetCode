class Solution {
public:
    // Function to determine which child holds the pillow after 'time' minutes
    int passThePillow(int n, int time) {
        // Calculate the number of complete passes around the circle
        int chunks = time / (n - 1);
        
        // Determine the current holder of the pillow based on even or odd number of passes
        return chunks % 2 == 0 ? (time % (n - 1) + 1) : (n - time % (n - 1));
    }
};

/*

Approach Summary:

The `passThePillow` function determines which child holds the pillow after 'time' minutes have passed in a game where children pass the pillow every `(n - 1)` minutes in a circle.

1. **Calculate Chunks**:
   - `chunks` calculates how many complete passes of `(n - 1)` minutes each child makes within `time` minutes.

2. **Determine Pillow Holder**:
   - If `chunks` (number of complete passes) is even, the pillow is with the child who is `(time % (n - 1) + 1)`th in the circle (1-based index).
   - If `chunks` is odd, the pillow is with the child who is `n - (time % (n - 1))`th in the circle.

Complexity:
    Time Complexity: 
    - The function runs in O(1) time complexity because it involves simple arithmetic operations.

    Space Complexity: 
    - The space complexity is O(1) as there are no additional data structures used that grow with input size.

*/

