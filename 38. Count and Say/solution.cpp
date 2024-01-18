class Solution {
public:
    // A function to return the nth term of the count and say sequence
    string countAndSay(int n) {
        if (n == 1) return "1"; // Base case: the first term is "1"
        string term = "1"; // Initialize the term to "1"
        for (int i = 2; i <= n; i++) { // Loop from the second term to the nth term
            term = nextTerm(term); // Generate the next term from the previous term
        }
        return term; // Return the nth term
    }

    // A function to generate the next term of the sequence from the previous term
    string nextTerm(string term) {
        string result = ""; // Initialize an empty string to store the result
        int count = 1; // Initialize a counter to count the frequency of each digit
        char digit = term[0]; // Initialize the current digit to the first character of the term
        for (int i = 1; i < term.length(); i++) { // Loop through the rest of the characters in the term
            if (term[i] == digit) { // If the current character is equal to the current digit
                count++; // Increment the counter
            }
            else { // If the current character is different from the current digit
                result += to_string(count) + digit; // Append the count and the digit to the result
                count = 1; // Reset the counter to 1
                digit = term[i]; // Update the current digit to the current character
            }
        }
        result += to_string(count) + digit; // Append the last count and digit to the result
        return result; // Return the result
    }

};

/* 
Complexity:
    
    The time complexity is O(n . m), where n is the input integer and m is the length of the longest term in the sequence. This is because the code uses a loop to generate n 
    terms of the sequence, and each term takes O (m) time to generate from the previous term using the nextTerm function. The nextTerm function uses another loop to iterate over 
    the characters of the term, and performs constant-time operations in each iteration.

    The space complexity is O(m), where m is the length of the longest term in the sequence. This is because the code uses a string variable to store the current term, and the 
    size of the string is bounded by the length of the term. The nextTerm function also uses another string variable to store the result, but it is local to the function and 
    does not affect the overall space complexity.

 */