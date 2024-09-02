static const int kds = []() {
    ios::sync_with_stdio(false); // Disable synchronization with C I/O streams for faster input/output
    cin.tie(nullptr); // Untie cin from cout to avoid flushing cout before reading input
    cout.tie(nullptr); // Untie cout from cin to avoid flushing cout after reading input
    return 0;
}(); // Static initializer for faster I/O

class Solution {
public:
    // Function to determine the index of the student who will not get enough chalk
    int chalkReplacer(vector<int>& chalk, int initialChalkPieces) {
        long long totalChalkNeeded = 0; // Total chalk needed for all students

        // Compute the total amount of chalk needed for one complete round of all students
        for (int studentChalkUse : chalk) {
            totalChalkNeeded += studentChalkUse;
        }

        // Determine the remaining chalk after distributing full rounds
        int remainingChalk = initialChalkPieces % totalChalkNeeded;

        // Iterate through each student to find out who will not receive enough chalk
        for (int studentIndex = 0; studentIndex < chalk.size(); studentIndex++) {
            if (remainingChalk < chalk[studentIndex]) {
                return studentIndex; // Return the index of the student who will not get enough chalk
            }
            remainingChalk -= chalk[studentIndex]; // Deduct the chalk used by the current student
        }

        return 0; // Return 0 if no student is found to be lacking chalk (this case is not expected with valid inputs)
    }
};

/*
Approach Summary:
- Compute the total amount of chalk needed for one full pass through all students.
- Use modulo operation to find out the effective amount of chalk left after several full passes.
- Traverse through the list of students to find the first student who will not receive enough chalk with the remaining pieces.

Time Complexity:
- O(n), where n is the number of students. The function computes the total chalk needed and iterates through the list to find the student index.

Space Complexity:
- O(1). The space used is constant, as only a few variables are maintained aside from the input vector.
*/
