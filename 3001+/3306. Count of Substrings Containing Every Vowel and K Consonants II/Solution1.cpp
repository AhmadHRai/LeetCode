class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }

private:
    bool isVowel(char c) {
        static const uint32_t vowelMask =
            (1 << ('a' - 'a')) | (1 << ('e' - 'a')) | (1 << ('i' - 'a')) |
            (1 << ('o' - 'a')) | (1 << ('u' - 'a'));
        return vowelMask & (1 << (c - 'a'));
    }

    long atLeastK(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0;
        int end = 0;
        // Keep track of counts of vowels and consonants.
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;

        // Start sliding window.
        while (end < word.length()) {
            // Insert new letter.
            char newLetter = word[end];

            // Update counts.
            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }

            // Shrink window while we have a valid substring.
            while (vowelCount.size() == 5 and consonantCount >= k) {
                numValidSubstrings += word.length() - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    if (--vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            end++;
        }

        return numValidSubstrings;
    }
};