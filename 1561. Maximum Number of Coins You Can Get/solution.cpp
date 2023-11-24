// Define a class named Solution that contains a public method named maxCoins
class Solution {
public:
    // Define the maxCoins method that takes a vector of integers as a parameter and returns an integer
    int maxCoins(vector<int>& piles) {
      // Sort the vector of piles in ascending order using the sort function
      sort(piles.begin(), piles.end());
      // Initialize a variable named ans to store the answer and set it to zero
      int ans = 0;
      // Get the size of the vector and store it in a variable named n
      int n = piles.size();
      // Use a for loop to iterate over the vector from the index n/3 to the index n-1 with a step of 2
      for (int i = n / 3; i < n; i += 2)
          // Add the value of the pile at the current index to the ans variable
          ans += piles[i];
       // Return the ans variable as the final answer
       return ans;
    }
};

/* 
The time complexity of the code is O(n log n), where n is the size of the vector, because the sorting function takes O(n log n) time and the for 
loop takes O(n) time. 
The space complexity of the code is O(1), because no extra space is used apart from the input vector and some variables.
 */