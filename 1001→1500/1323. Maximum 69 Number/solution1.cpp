class Solution {
public:
    int maximum69Number(int num) {
        int firstSix = -1;
        int tempNum = num;
        int multiplier = 1;
        
        // Find the rightmost 6 and corresponding multiplier
        while (tempNum > 0) {
            if (tempNum % 10 == 6) {
                firstSix = multiplier;
            }
            tempNum /= 10;
            multiplier *= 10;
        }
        
        // If no 6 found, return original number
        if (firstSix == -1) return num;
        
        // Add 3 * firstSix to convert 6 to 9 at that digit
        return num + 3 * firstSix;
    }
};
