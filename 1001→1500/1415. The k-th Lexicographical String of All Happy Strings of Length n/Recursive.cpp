class Solution {
    public:
        string getHappyString(int n, int k) {
            string result = ""; // Result string to store the k-th happy string
            vector<string> happyStrings; // Vector to store all happy strings
    
            // Lambda function to generate happy strings recursively
            function<void(string)> generateHappyStrings = [&](string currentString) {
                // Base case: If the current string has reached the desired length
                if (currentString.length() == n) {
                    happyStrings.push_back(currentString); // Add the string to the vector
                    return;
                }
    
                // Try all possible characters
                for (char c : {'a', 'b', 'c'}) {
                    // Check if the character is different from the last one in the string
                    if (currentString.empty() || currentString.back() != c) {
                        generateHappyStrings(currentString + c); // Recurse to generate the next string
                    }
                }
            };
    
            // Generate all happy strings
            generateHappyStrings("");
    
            // Sort the happy strings lexicographically
            sort(happyStrings.begin(), happyStrings.end());
    
            // Check if k exceeds the number of happy strings
            if (k > happyStrings.size()) {
                return ""; // Return empty string if k is too large
            } else {
                return happyStrings[k - 1]; // Return the k-th happy string
            }
        }
    }
    /*
    Approach Summary:
        This solution generates all happy strings of length n, sorts them lexicographically, and returns the k-th string. It uses a recursive lambda function to generate 
        all possible happy strings.
    
    Complexity Analysis:
    - Time Complexity: O(N * 3^N), where N is the length of the string, because all possible combinations of characters need to be generated and sorted.
    - Space Complexity: O(3^N), for storing all generated happy strings.
    */
    