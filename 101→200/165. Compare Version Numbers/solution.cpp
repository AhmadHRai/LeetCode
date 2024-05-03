class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0; // Initialize index for version1
        int j = 0; // Initialize index for version2
        int n1 = version1.size(); // Store the size of version1
        int n2 = version2.size(); // Store the size of version2
        
        int num1 = 0; // Initialize variable to store the numeric part of version1
        int num2 = 0; // Initialize variable to store the numeric part of version2
        while(i<n1 || j<n2) // Continue until we've processed all characters in both version strings
        {
            // Extract numeric part of version1
            while(i<n1 && version1[i]!='.'){
                num1 = num1*10+(version1[i]-'0'); // Accumulate the numeric value
                i++; // Move to the next character
            }
            
            // Extract numeric part of version2
            while(j<n2 && version2[j]!='.'){
                num2 = num2*10+(version2[j]-'0'); // Accumulate the numeric value
                j++; // Move to the next character
            }
            
            // Compare the numeric parts
            if(num1>num2) return 1; // If version1 is greater, return 1
            else if(num1 < num2) return -1; // If version2 is greater, return -1
            
            num1 = 0; // Reset num1 for the next segment
            num2 = 0; // Reset num2 for the next segment
            i++; // Move to the next segment in version1
            j++; // Move to the next segment in version2
        }
        
        return 0; // If all segments are equal, return 0
    }
};

/* 
Approach:

    This solution iterates through the version strings `version1` and `version2` to compare their version numbers. It extracts the numeric parts of the version strings 
    by iterating through each character and accumulating the numeric value until a dot ('.') is encountered, indicating the end of a version number segment. For each 
    segment, it compares the numeric values and returns 1 if `version1` is greater, -1 if `version2` is greater, or 0 if they are equal.

Complexity:

    Time Complexity: O(n + m), where n and m are the lengths of `version1` and `version2` respectively. This is because the algorithm iterates through each character in 
    the version strings once.
    Space Complexity: O(1), as the algorithm does not use any additional space that scales with the input size.

*/