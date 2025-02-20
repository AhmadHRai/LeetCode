class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            // Set to store unique binary strings from the input vector
            unordered_set<string> s(nums.begin(), nums.end());
            int n = nums.size(); // Size of the input vector
    
            // Iterate through all possible binary strings of length n
            for (int i = 0; i < (1 << n); i++) {
                // Convert the integer to a binary string and remove leading zeros
                string binary = bitset<16>(i).to_string().substr(16 - n);
    
                // Check if the binary string is not in the set of input strings
                if (!s.count(binary)) {
                    return binary; // Return the first different binary string found
                }
            }
            return ""; // Return empty string if no different string is found
        }
    }
    /*
    Approach Summary:
        This solution generates all possible binary strings of length n and checks if each one is different from the strings in the input vector. It uses a set to 
        efficiently check for uniqueness.
    
    Complexity Analysis:
        Time Complexity: O(2^N), where N is the number of strings in the input vector, because all possible binary strings need to be generated and checked.
        Space Complexity: O(N), for storing the set of input strings.
    */
    