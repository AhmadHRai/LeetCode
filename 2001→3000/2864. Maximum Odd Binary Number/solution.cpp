class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // Sort the string in reverse order. This moves all '1's to the end.
        sort(s.rbegin(),s.rend());
        // Iterate through the string from the end to the beginning.
        for(int i = s.size()-1; i >= 0; i--){
            // If the current character is '1', swap it with the last '1' in the string.
            if(s[i]=='1') swap(s[i],s[s.size()-1]);
        }
        // Return the modified string.
        return s;
    }
};

/* 
Approach:
    The solution aims to make the binary number odd by ensuring the most significant bit (the leftmost bit) is '1'. This is because an odd binary number must have its 
    leftmost bit as '1'.
    
    The algorithm sorts the binary string in reverse order to bring all '1's to the end. This is because sorting in reverse places the '1's at the beginning of the string, 
    and since we want the most significant bit to be '1', we need to move all '1's to the end.
    
    Then, it iterates through the string from the end to the beginning. If it finds a '1', it swaps it with the last '1' in the string. This ensures that the leftmost bit is 
    '1', making the number odd.

 Complexity Analysis:

    Time Complexity:    The time complexity is O(n log n) due to the sorting operation. The sort function in C++ uses a comparison sort algorithm (e.g., quicksort or 
    mergesort), which has an average and worst-case time complexity of O(n log n). The subsequent loop through the string to swap '1's has a linear time complexity O(n), but 
    this is dominated by the sorting operation.

    Space Complexity:   The space complexity is O(1) because the sorting is done in-place, meaning the additional space required does not grow with the size of the input string. The loop iterating through the string does not use any additional space that scales with the input size.
 */