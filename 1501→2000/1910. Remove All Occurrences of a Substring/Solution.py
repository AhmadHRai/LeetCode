class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        # Length of the substring to be removed
        N = len(part)

        try:
            # Continuously remove occurrences of the substring until none are found
            while True:
                # Find the index of the first occurrence of the substring
                i = s.index(part)
                # Remove the substring by concatenating the parts before and after it
                s = s[:i] + s[i + N:]
        except ValueError:
            # If no occurrences are found, the `index` method raises a ValueError
            return s
'''
Approach Summary:
This solution iteratively removes all occurrences of a given substring from a string. It uses a loop to continuously find and remove the substring until no more occurrences are found. Throws an exception if the substring is not found. // Crackhead solution

Complexity Analysis:
- Time Complexity: O(N*M), where N is the length of the string and M is the length of the substring, because in the worst case, the substring could be removed from every position in the string.
- Space Complexity: O(N), for creating new strings during each removal operation.
'''
