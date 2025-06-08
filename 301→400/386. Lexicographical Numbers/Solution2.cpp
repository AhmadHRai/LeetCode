class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        // Start generating numbers from 1 to 9
        for (int start = 1; start <= 9; ++start) {
            generateLexicalNumbers(start, n, lexicographicalNumbers);
        }
        return lexicographicalNumbers;
    }

private:
    void generateLexicalNumbers(int currentNumber, int limit,
                                vector<int>& result) {
        // If the current number exceeds the limit, stop recursion
        if (currentNumber > limit) return;

        // Add the current number to the result
        result.push_back(currentNumber);

        // Try to append digits from 0 to 9 to the current number
        for (int nextDigit = 0; nextDigit <= 9; ++nextDigit) {
            int nextNumber = currentNumber * 10 + nextDigit;
            // If the next number is within the limit, continue recursion
            if (nextNumber <= limit) {
                generateLexicalNumbers(nextNumber, limit, result);
            } else {
                break;  // No need to continue if nextNumber exceeds limit
            }
        }
    }
};