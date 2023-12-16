# Intuition

To solve the anagram problem, we can count the frequency of each letter in both strings and compare them. If the frequencies of all letters are the same in both strings, then the two strings are anagrams of each other.

# Approach

We can use an integer array `freq` of length 26 to keep track of the frequency of each letter in the two strings. We first check if the length of both strings is the same. If not, we return false because anagrams must have the same length. We loop through each character in both strings and increment the frequency of the corresponding letter in `s` and decrement the frequency of the corresponding letter in `t`.\
Finally, we loop through the `freq` array and check if all requencies are zero. If not, we return false. If all frequencies are zero, we return true because both strings are anagrams of each other.

# Complexity

- Time complexity: O(n), where n is the length of the strings. We need to loop through each character in both strings once to count the frequency of each letter, and then loop through the `freq` array once to check if all frequencies are zero.

- Space complexity: O(1), because the size of the `freq` array is fixed at 26, which is a constant value. Therefore, the space required to store the `freq` array does not depend on the length of the strings.
