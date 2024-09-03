class Solution {
public:
    // Function to transform a string `s` into a lucky number after `k` transformations
    int getLucky(string s, int k) {
        // Convert each character in the string to its corresponding numeric value
        string number = "";
        for (char x : s) {
            number += to_string(x - 'a' + 1); // Convert 'a' to 1, 'b' to 2, ..., 'z' to 26
        }
        
        // Perform the transformation `k` times
        while (k > 0) {
            int temp = 0;
            for (char x : number) {
                temp += x - '0'; // Sum the digits of the current number
            }
            number = to_string(temp); // Convert the sum back to a string
            k--;
        }
        
        return stoi(number); // Return the final result as an integer
    }
};

/*
Approach Summary:
- Convert each character of the input string `s` to its corresponding numeric value based on its position in the alphabet.
- Perform `k` transformations where each transformation involves summing the digits of the current numeric string and converting it back to a string.
- Return the final number after `k` transformations.

Time Complexity:
- O(k * m), where k is the number of transformations and m is the length of the number string in the worst case. The function performs digit summation `k` times, and each summation involves iterating through the number string.

Space Complexity:
- O(m), where m is the length of the numeric string. The space is used to store the intermediate numeric strings during the transformations.
*/
