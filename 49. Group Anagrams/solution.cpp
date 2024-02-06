class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create an unordered map that maps a sorted string to a vector of its anagrams
        unordered_map<string, vector<string>> mp;
        // Loop over the input vector of strings
        for (string s : strs) {
            // Make a copy of the current string and sort it
            string t = s; 
            sort(t.begin(), t.end());
            // Add the original string to the vector of its sorted string in the map
            mp[t].push_back(s);
        }
        // Create a vector of vectors to store the grouped anagrams
        vector<vector<string>> anagrams;
        // Loop over the map and add each vector of anagrams to the result vector
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        // Return the result vector
        return anagrams;
    }
};

/* 
Complexity:
    The time complexity of the code is O(nklogk), where n is the size of the input vector and k is the maximum length of any string in the vector. This is because we need to loop over the vector once, which takes O(n) time, and for each string, we need to sort it, which takes O(klogk) time. The insertion and retrieval from the unordered map are constant time operations, so they do not affect the overall time complexity.
    
    The space complexity of the code is O(nk), where n and k are the same as above. This is because we need to store the sorted strings and the vectors of anagrams in the unordered map, which takes O(nk) space. The result vector also takes O(nk) space, so the total space complexity is O(nk).
*/