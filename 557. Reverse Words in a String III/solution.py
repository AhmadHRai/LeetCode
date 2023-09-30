class Solution:
    def reverseWords(self, s: str) -> str:
        # Split the string into words
        words = s.split()
        
        # Reverse each word and join them back
        reversed_words = [word[::-1] for word in words]
        
        # Join the reversed words with spaces
        return ' '.join(reversed_words)

""" The time complexity is O(n), where n is the length of the input string. This is because we need to traverse each character in the input string exactly once. 
The space complexity is also O(n), as we need to store the reversed words in a list. """