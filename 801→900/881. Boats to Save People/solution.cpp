class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the vector of people's weights
        sort(people.begin(), people.end());
        
        int i = 0, j = people.size() - 1, cnt = 0;
        
        while(i <= j)
        {   
            // If the lightest person and the heaviest person can go together
            if(people[i] + people[j] <= limit)
            {
                ++i; // Move to the next lightest person
                --j; // Move to the next heaviest person
            }
            // If the sum of the lightest and heaviest person is over the limit,
            // the heaviest person will go alone.
            else
                --j; // Move to the next heaviest person
            
            ++cnt; // Increment the count of boats
        }
        
        return cnt; // Return the total number of boats
    }
};

/* 
Approach:

    This solution sorts the array of people's weights and then uses two pointers (i and j) to find pairs of people that can go together in a boat, where the sum of their 
    weights is less than or equal to the limit. The algorithm iterates through the sorted array, always trying to pair the lightest person with the heaviest person that 
    can go together. If the sum of the weights of the lightest and heaviest person is over the limit, the heaviest person goes alone.

Complexity:

    Time Complexity: O(n log n) due to the sorting operation, where n is the number of people.

    Space Complexity: O(1) as it does not use any additional space that scales with the input size.

*/