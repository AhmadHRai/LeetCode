class Solution {
public:
    int minimumPushes(string word) {
        // Initialize an array to store the frequency of each letter (26 letters in the alphabet)
        int freq[26] = {0};

        // Count the frequency of each character in the input word
        for(char c: word) 
            freq[c - 'a']++;

        // Sort the frequency array in descending order
        sort(freq, freq + 26, greater<int>());

        // Initialize the size of the frequency array being processed, the push count, and the result variable
        int sz = 0, push = 1, ans = 0;

        // Iterate through the frequency array to calculate the total number of pushes required
        for(; sz < 26 && freq[sz] != 0; sz++) {
            // Increase the push count for every 8 letters processed
            if (sz >= 8 && sz % 8 == 0) push++;

            // Accumulate the total pushes needed based on the frequency and current push count
            ans += freq[sz] * push;    
        }

        // Return the computed result
        return ans;
    }
};

/*
Approach:
1. Count the frequency of each character in the given word.
2. Sort the frequency array in descending order.
3. Initialize the number of pushes required (starting at 1).
4. Iterate through the sorted frequency array:
   - For every 8 characters processed, increment the push count.
   - Calculate the total pushes required by multiplying the frequency of each character by the current push count.
5. Return the accumulated total pushes.

Complexity Analysis:
- Time Complexity: O(N + 26 log 26) where N is the length of the word. Counting the frequency is O(N), sorting the 26 frequencies takes constant time, O(26 log 26), which is effectively O(1).
- Space Complexity: O(1) since the frequency array size is constant (26).
*/
