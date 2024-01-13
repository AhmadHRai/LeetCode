# Import the Counter class from the collections module
from collections import Counter

# Define a class named Solution
class Solution:
    # Define a method named minSteps that takes two strings s and t as parameters and returns an integer
    def minSteps(self, s: str, t: str) -> int:
        # Create a Counter object from s that counts the frequency of each character in s
        counts = Counter(s)
        # Initialize a variable named ans to store the answer and set it to zero
        ans = 0
        
        # Loop through each character in t
        for c in t:
            # If the current character is present in s (i.e. its count is positive)
            if counts[c] > 0:
                # Decrement its count by one
                counts[c] -= 1
            # Otherwise (i.e. the current character is not present in s)
            else:
                # Increment the answer by one
                ans += 1
        
        # Return the final answer
        return ans

""" 
Complexity:
    The time complexity is O(n), where n is the length of the strings. This is because the code loops through each character in the strings, which takes O(n) time, and performs 
    constant-time operations on the Counter object, such as checking, updating, and decrementing counts.
    
    The space complexity is O(1), as the code only uses a Counter object of fixed size 26, which is a constant. The code does not use any extra space that depends on the input 
    size. Therefore, the overall space complexity is O(1).

 """