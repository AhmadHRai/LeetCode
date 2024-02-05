class Solution:
    def firstUniqChar(self, s: str) -> int:
        hset = collections.Counter(s)
        # Traverse the string from the beginning
        for idx in range(len(s)):
            # If the count is equal to 1, it is the first distinct character in the list
            if hset[s[idx]] == 1:
                return idx
        return -1 # If no character appeared exactly once

""" 
Complexity
    The time complexity of the code is O(n), where n is the length of the string s. This is because we need to traverse s twice: once to create the Counter object, and once to 
    find the first unique character. Each traversal takes O(n) time, so the total time complexity is O(n).

    The space complexity of the code is O(m), where m is the size of the alphabet. This is because we need to store the frequency of each character in the Counter object, which 
    takes O(m) space. The space complexity does not depend on the input size n, but on the number of distinct characters in s.
 """