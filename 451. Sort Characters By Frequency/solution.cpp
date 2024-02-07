class Solution {
public:
    string frequencySort(const string& s) {
        // Get the size of the input string
        int n = s.size();
        // Create an unordered map to store the count of each character in the string
        unordered_map<char, int> cnt;
        // Loop over the input string and increment the count of each character
        for (char c : s)  cnt[c] += 1;
        
        // Create a vector of vectors to store the characters by their frequency
        // The index of the vector represents the frequency, and the elements are the characters with that frequency
        vector<vector<char>> bucket(n+1);
        // Loop over the map and add each character to the corresponding bucket
        for (auto [c, f] : cnt)
            bucket[f].push_back(c);
        
        // Create an empty string to store the result
        string ans;
        // Loop over the bucket from the highest frequency to the lowest
        for (int freq = n; freq >= 1; --freq)
            // Loop over the characters in each bucket
            for (char c : bucket[freq]) 
                // Append the character to the result string as many times as its frequency
                ans.append(freq, c);
        // Return the result string
        return ans;
    }
};

/* 
Complexity Analysis:
    The time complexity of the code is O(nlogn), where n is the length of the input string. This is because we need to loop over the string once, which takes O(n) time, and sort 
    the characters by their frequency, which takes O(nlogn) time. The insertion and retrieval from the unordered map and the vector are constant time operations, so they do not 
    affect the overall time complexity.
    
    The space complexity of the code is O(n), where n is the same as above. This is because we need to store the count of each character in the unordered map, which takes O(n) 
    space. The vector of vectors also takes O(n) space, because the total number of elements is equal to the number of characters in the string. The result string also takes O(n) 
    space, so the total space complexity is O(n).
 */