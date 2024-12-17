class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;  // Map to store frequency of each character
        for (char ch : s) {
            freq[ch]++;  // Count the frequency of each character in the input string
        }

        priority_queue<char> maxHeap;  // Max heap to store characters, ordered by their value (lexicographically largest first)
        for (auto& [ch, count] : freq) {
            maxHeap.push(ch);  // Push characters into the heap
        }

        string result;  // Result string to store the final answer

        // While the heap is not empty
        while (!maxHeap.empty()) {
            char ch = maxHeap.top();  // Get the lexicographically largest character
            maxHeap.pop();  // Remove the character from the heap
            int count = freq[ch];  // Get the frequency of the character

            int use = min(count, repeatLimit);  // Limit the number of times this character can be used
            result.append(use, ch);  // Append the character to the result string

            freq[ch] -= use;  // Decrease the frequency of the character after using it

            // If there are more instances of the current character and there is still a character to use
            if (freq[ch] > 0 && !maxHeap.empty()) {
                char nextCh = maxHeap.top();  // Get the next largest character
                maxHeap.pop();  // Remove it from the heap

                result.push_back(nextCh);  // Add one occurrence of the next character
                freq[nextCh]--;  // Decrease its frequency

                // If there are still more of this character, push it back into the heap
                if (freq[nextCh] > 0) {
                    maxHeap.push(nextCh);
                }

                // Re-insert the current character into the heap for future use
                maxHeap.push(ch);
            }
        }

        return result;  // Return the constructed result string
    }
};

/*
    Time Complexity: O(N + N * log K)
        - O(N): The initial loop counts the frequency of each character in the string, which takes O(N), where N is the length of the input string.
        - O(N * log K): In the main loop, each character is popped and pushed into the priority queue (heap), where each push/pop operation takes O(log K), where K is the number of distinct characters (bounded by 26 in the worst case).
        - The total time complexity is dominated by the heap operations, so it's O(N + N * log K), where N is the length of the string and K is the number of unique characters (at most 26).

    Space Complexity: O(N + K)
        - O(N): The frequency map (`freq`) requires O(N) space for storing the counts of each character in the string.
        - O(K): The max heap stores the characters (at most 26 distinct ones).
        - Thus, the space complexity is O(N + K), where N is the size of the input string and K is the number of distinct characters in the string (up to 26).
*/
