class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // Initialize the total time to 0.
        int totalTime = 0;
        // Get the number of people in the line.
        int n = tickets.size();
      
        // Iterate through each person in the line.
        for (int i = 0; i < n; ++i) {
            // Check if the current person is before or at position k.
            if (i <= k) {
                // If so, add the minimum of the number of tickets the kth person needs and the number of tickets the current person needs to the total time.
                totalTime += min(tickets[k], tickets[i]);
            } else {
                // If the current person is after the kth person, add the minimum of one less than the number of tickets the kth person needs and the number of tickets the current 
                person needs to the total time.
                totalTime += min(tickets[k] - 1, tickets[i]);
            }
        }
        // Return the total time calculated.
        return totalTime;
    }
};

/* 
Approach

    The solution calculates the total time required to buy tickets for all people in the line. It iterates through each person in the line. If the current person is before or at 
    position k, it adds the minimum of the number of tickets the kth person needs and the number of tickets the current person needs to the total time. If the current person is after 
    the kth person, it adds the minimum of one less than the number of tickets the kth person needs and the number of tickets the current person needs to the total time. This 
    approach ensures that each person buys the maximum number of tickets they can, given the constraints of the kth person's position and the number of tickets they need.

Complexity

    Time complexity: O(n), where n is the number of people in the line. This is because each person in the line is processed exactly once.
    
    Space complexity: O(1), as the solution uses a constant amount of space to store the total time and does not depend on the size of the input vector.
 */
