class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Initialize counters for students who prefer type 0 and type 1 sandwiches.
        int ones = 0; // Count of students who prefer type 1 sandwiches.
        int zeros = 0; // Count of students who prefer type 0 sandwiches.
        
        // Iterate through each student's preference.
        for(int stud : students){
            // Increment the counter for type 0 or type 1 sandwiches based on the student's preference.
            if(stud == 0) zeros++;
            else ones++;
        }
        
        // Iterate through each sandwich in the sandwiches vector.
        for(int sandwich : sandwiches){
            // Check if the current sandwich is of type 0.
            if(sandwich == 0){
                // If there are no students who prefer type 0 sandwiches, return the number of students who prefer type 1 sandwiches.
                if(zeros == 0) return ones;
                // Otherwise, decrement the counter for students who prefer type 0 sandwiches.
                zeros--;
            }
            // If the current sandwich is of type 1.
            else{
                // If there are no students who prefer type 1 sandwiches, return the number of students who prefer type 0 sandwiches.
                if(ones == 0) return zeros;
                // Otherwise, decrement the counter for students who prefer type 1 sandwiches.
                ones--;
            }
        }
        // If all sandwiches have been distributed without any students being left without their preferred sandwich, return 0.
        return 0;
    }
};

/* 
Approach

    The solution first counts the number of students who prefer type 0 and type 1 sandwiches. It then iterates through each sandwich in the sandwiches vector. If a sandwich is of 
    type 0 and there are no students who prefer type 0 sandwiches, it returns the number of students who prefer type 1 sandwiches. If a sandwich is of type 1 and there are no 
    students who prefer type 1 sandwiches, it returns the number of students who prefer type 0 sandwiches. Otherwise, it decrements the counter for the type of sandwich being 
    distributed. If all sandwiches are distributed without any students being left without their preferred sandwich, it returns 0.

Complexity

    Time complexity: O(n), where n is the total number of students and sandwiches. This is because each student's preference and each sandwich is processed exactly once.
    
    Space complexity: O(1), as the solution uses a constant amount of space to store the counters and does not depend on the size of the input vectors.
 */
