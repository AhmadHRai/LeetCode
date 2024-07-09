class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        // Get the number of customers
        int n = customers.size();
        
        // Initialize waiting time with the first customer's wait time
        double time_waiting = customers[0][1];
        
        // Initialize finished_prev with the end time of the first customer
        int finished_prev = customers[0][0] + customers[0][1];

        // Iterate through the remaining customers
        for (int customer_ind = 1; customer_ind < n; ++customer_ind) {
            // Extract arrival time and cooking time of the current customer
            vector<int> times = customers[customer_ind];
            int arrive = times[0];
            
            // Determine the start cooking time for the current customer
            int start_cook = max(arrive, finished_prev);
            
            // Calculate the end time for the current customer
            int end_time = start_cook + times[1];
            
            // Update finished_prev for the next customer
            finished_prev = end_time;
            
            // Accumulate total waiting time
            time_waiting += end_time - arrive;
        }

        // Return the average waiting time
        return time_waiting / n;
    }
};

/* 
Approach

    The solution calculates the average waiting time for a list of customers where each customer has an arrival time and a cooking time.
    - Start by initializing the waiting time with the cooking time of the first customer.
    - Track the end time of the first customer.
    - For each subsequent customer, determine when they start being served based on their arrival time and when the previous customer finished.
    - Update the total waiting time and the end time for each customer.
    - Finally, calculate the average waiting time by dividing the total waiting time by the number of customers.

Complexity

    Time complexity: O(n), where n is the number of customers. This is because each customer is processed exactly once.
    
    Space complexity: O(1), as only a few additional variables are used beyond the input data.
 */
