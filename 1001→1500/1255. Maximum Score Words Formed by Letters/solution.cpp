class Solution {
public:
    int helper(vector<string>& words, int curr, vector<char> letters, vector<int>& score){
        // Base case: there is no element
        if(curr < 0) return 0;
        
        // Using unordered_maps as they have better time complexity than normal map by a factor of log(N)
        unordered_map<char, int> curr_dict, curr_word, remaining;
        
        // Converting the current word in consideration and the letter vector in key-value format:
        // where keys are alphabets and values are their frequency
        for(int i = 0; i < letters.size(); i++) {
            curr_dict[letters[i]]++;
        }
        for(int i = 0; i < words[curr].size(); i++) {
            curr_word[words[curr][i]]++;
        }
        
        vector<char> letters_remaining;
        remaining = curr_dict;
        int flag = 1;
        
        // Checking if curr_word can be constructed using the letters vector by comparing frequency of alphabets
        for(auto temp : curr_word) {
            if(curr_dict[temp.first] < temp.second) {
                flag = 0;
                break;
            }
            remaining[temp.first] -= temp.second;
        }
        
        // If the current word cannot be constructed, we will simply pass it
        if(flag == 0) {
            return helper(words, curr - 1, letters, score);
        }
        
        // Now comes the case where the current word can be constructed. We have 2 options either construct the
        // word (receive some score, and reduce the letters vector) or simply pass it
        // Calculating the score received for constructing the word
        int curr_score = 0;
        for(int i = 0; i < words[curr].size(); i++) {
            curr_score += score[words[curr][i] - 'a'];
        }
        
        // Creating a new vector after reducing the alphabets used for making the current word
        for(auto temp : remaining) {
            for(int i = 0; i < temp.second; i++)
                letters_remaining.emplace_back(temp.first);
        }
        
        // Calling on the next word with reduced letters vector and adding the score 
        int ans2 = helper(words, curr - 1, letters_remaining, score) + curr_score;        
        
        // Returning the maximum value for the two options we had if current word can be constructed
        return max(helper(words, curr - 1, letters, score), ans2);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // Will iterate from last element to first.
        return helper(words, words.size() - 1, letters, score);        
    }
};

/*
Approach Explanation:

    This solution utilizes a recursive approach to calculate the maximum score that can be achieved using a given set of words, a set of available letters, and their 
    corresponding scores. It iterates through each word and recursively calculates the maximum score achievable considering two scenarios: constructing the current word or 
    skipping it. At each step, it checks if the current word can be constructed using the available letters and calculates the score accordingly.

Complexity Analysis:

    Time Complexity: The time complexity of this solution depends on the size of the words, letters, and their scores. In the worst case, where all combinations of 
    constructing or skipping words are explored, the time complexity can be exponential. However, due to memoization, the actual time complexity is significantly reduced in 
    practice.
    
    Space Complexity: The space complexity mainly depends on the size of the input arrays and the recursion depth. The space complexity of this solution is primarily 
    dominated by the recursion stack and auxiliary data structures used for memoization, resulting in a space complexity of O(N), where N is the size of the input.
*/