class Solution {
public:
    string smallestSubsequence(string s) {
        int freq[27] = {0};
        bitset<27> seen;
        string stack;

        for (auto& c : s)
            freq[c & 31]++;

        for (auto& c : s) {
            int x = c & 31;
            freq[x]--;

            if (seen.test(x))
                continue;

            while (stack.length() && stack.back() > c && freq[stack.back() & 31]) {
                seen.reset(stack.back() & 31);
                stack.pop_back();
            }

            stack.push_back(c);
            seen.set(x);
        }

        return stack;
    }
};
