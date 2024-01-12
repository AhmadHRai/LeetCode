class Solution {
public:
    // Function to determine if two strings are close
    bool closeStrings(string word1, string word2) {
        // Declare four vectors of size 26 and initialize them with zeros
        // w1 and w2 will store the frequencies of characters in word1 and word2
        // w3 and w4 will store the presence of characters in word1 and word2
        vector<int>w1(26,0),w2(26,0),w3(26,0),w4(26,0);
        
        // Loop through each character in word1
        for(char c:word1)
            // Increment the frequency of the current character in w1
            // Set the presence of the current character to 1 in w3
            w1[c-'a']++,w3[c-'a'] = 1;
    
        // Loop through each character in word2
        for(char c:word2)
            // Increment the frequency of the current character in w2
            // Set the presence of the current character to 1 in w4
            w2[c-'a']++,w4[c-'a'] = 1;
        
        // Sort w1 and w2 in ascending order
        sort(begin(w1),end(w1));
        sort(begin(w2),end(w2));
        
        // Return true if w1 and w2 are equal and w3 and w4 are equal
        // This means that both words have the same character frequency distribution
        // and the same set of characters
        return w1==w2&&w3==w4;
    }
};

/* 
Complexity:

    The time complexity is O(n log n), where n is the maximum length of the words. This is because the code loops through each character in the words, which takes O(n) time, and 
    sorts the vectors, which takes O(n log n) time. The comparison of the vectors takes O(1) time, as the vectors have a fixed size of 26. Therefore, the overall time complexity 
    is O(n log n).
    
    The space complexity is O(1), as the code only uses four vectors of fixed size 26, which is a constant. The code does not use any extra space that depends on the input size. 
    Therefore, the overall space complexity is O(1).

 */

/* 
Some lame notes:
    - The code uses the vector class from the standard library to store the character counts and presence for both words. A vector is a dynamic array that can grow and shrink as needed.
    - The code uses the sort function from the algorithm header to sort the vectors in ascending order. The sort function takes two iterators as arguments, which specify the range of elements to sort. The code uses the begin and end functions from the iterator header to get the iterators pointing to the first and past-the-last elements of the vectors.
 */