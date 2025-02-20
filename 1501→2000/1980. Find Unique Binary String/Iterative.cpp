class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string result; // Result string to store the different binary string
    
            // Iterate through each binary string in the vector
            for (int i = 0; i < nums.size(); ++i) {
                // Access the i-th character of the i-th binary string
                char currentCharacter = nums[i][i];
    
                // Append the opposite binary value to the result string
                result += (currentCharacter == '0' ? '1' : '0');
            }
    
            // Return the resulting binary string
            return result;
        }
    }
    /*
    Approach Summary:
        This solution constructs a binary string that differs from each string in the input vector by ensuring that the i-th character of the result string is different 
        from the i-th character of the i-th input string.
    
    Complexity Analysis:
    - Time Complexity: O(N), where N is the number of strings in the input vector, because each string is processed once.
    - Space Complexity: O(N), for storing the result string.
    */
    