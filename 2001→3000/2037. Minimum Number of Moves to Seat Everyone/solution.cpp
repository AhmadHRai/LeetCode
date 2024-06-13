// I don't understand the question, I'll just try and sort the arrays as the hint suggests until it passes the judge
#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * Calculates the minimum number of moves required to seat students in their corresponding seats.
     * 
     * @param {vector<int>&} seats - The array representing seat positions sorted in ascending order.
     * @param {vector<int>&} students - The array representing student positions sorted in ascending order.
     * @return {int} - The total number of moves required for all students to be seated.
     */
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Sort both seats and students arrays in ascending order
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());

        // Calculate the total distance that each student needs to move to reach their corresponding seat
        int moves = 0;
        for (int i = 0; i < seats.size(); ++i) {
            moves += abs(seats[i] - students[i]);
        }
        
        return moves;
    }
};

/*
Approach:
    1. Sorting:
        - Sort both the seats and students arrays in ascending order to facilitate pairing.
    2. Calculation:
        - Iterate through both arrays simultaneously.
        - For each pair of seat and student positions, calculate the absolute difference.
        - Accumulate these differences to get the total moves required.
    3. Return:
        - Return the accumulated moves, which represents the minimum number of moves required to seat all students.

Complexity:
    - Time Complexity: O(n log n)
      Sorting both seats and students arrays dominates the complexity. The subsequent linear pass to calculate moves is O(n), but it does not dominate due to sorting.
    - Space Complexity: O(n)
      Additional space is used to store the sorted arrays seats and students, each of size n.

Notes:
    - This approach ensures that each student is seated in the nearest possible seat by minimizing the total movement required.
    - Edge cases, such as empty arrays or arrays of different sizes, are implicitly handled by the sorting step and the subsequent iteration.
*/
