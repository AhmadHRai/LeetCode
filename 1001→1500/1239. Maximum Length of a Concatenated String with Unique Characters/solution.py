class Solution:
    # This function takes a list of strings A and returns the maximum length of a concatenation of some of the strings that contains no duplicate characters
    def maxLength(self, A):
        # Create a list of sets to store the possible concatenations of the strings
        dp = [set()]
        # Loop through the strings in A
        for a in A:
            # If the string has duplicate characters, skip it
            if len(set(a)) < len(a): continue
            # Convert the string to a set of characters
            a = set(a)
            # Loop through the existing concatenations in dp
            for c in dp[:]:
                # If the string and the concatenation have common characters, skip them
                if a & c: continue
                # Otherwise, add the union of the string and the concatenation to dp
                dp.append(a | c)
        # Return the maximum length of the sets in dp
        return max(len(a) for a in dp)


""" 
0. Initial the result res to include the case of empty string "".
res include all possible combinations we find during we iterate the input.

1. Itearte the the input strings,
but skip the word that have duplicate characters.
The examples is kind of misleading,
but the input string can have duplicate characters,
no need to considerate these strings.

2. For each string,
we check if it's conflit with the combination that we found.
If they have intersection of characters, we skip it.
If not, we append this new combination to result.

3. return the maximum length from all combinations.

Complexity:
    The time complexity is O(2^n), where n is the number of strings in A. This is because the code generates all possible subsets of the strings in A, and each subset takes O (n) 
    time to check for duplicate characters and perform set operations.
    
    The space complexity is O(2^n), because the code uses a list of sets to store all possible subsets of the strings in A, and each set takes O (n) space to store the characters.

"""