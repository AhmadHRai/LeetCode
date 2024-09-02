class Solution {
public:
    // Function to find the index of the student who will not get enough chalk
    int chalkReplacer(vector<int>& chalk, int initialChalkPieces) {
        long long totalChalkNeeded = 0; // Total chalk needed for all students
        
        // Calculate the total amount of chalk needed for all students
        for (int studentChalkUse : chalk) {
            totalChalkNeeded += studentChalkUse;
        }
        
        // Determine the remaining chalk after full rounds
        int remainingChalk = initialChalkPieces % totalChalkNeeded;
        
        // Iterate over each student to find who will not get enough chalk
        for (int studentIndex = 0; studentIndex < chalk.size(); studentIndex++) {
            if (remainingChalk < chalk[studentIndex]) {
                return studentIndex; // Return the index of the student who will not get enough chalk
            }
            remainingChalk -= chalk[studentIndex]; // Subtract the chalk used by the current student
        }
        
        return 0; // Return 0 if no student is found to be lacking chalk (should not reach here with valid inputs)
    }
};

/*
Approach Summary:
- Compute the total amount of chalk needed for one complete round of all students.
- Determine the effective amount of chalk left after distributing full rounds.
- Iterate through the list of students to find the first student who would not receive enough chalk with the remaining pieces.

Time Complexity:
- O(n), where n is the number of students. The function processes the list of chalk twice: once to compute the total chalk needed and once to find the index of the student who will not receive enough chalk.

Space Complexity:
- O(1). Space is used for variables, and no additional space is required beyond the input list.
*/
