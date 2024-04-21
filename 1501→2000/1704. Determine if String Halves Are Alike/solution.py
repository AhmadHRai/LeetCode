# Import the set class from the built-in module
from builtins import set

# Define a class named Solution
class Solution:
    # Define a method named halvesAreAlike that takes a string s as a parameter and returns a boolean
    def halvesAreAlike(self, s: str) -> bool:
        # Create a set object from a string of vowels (both uppercase and lowercase)
        vowels = set('aeiouAEIOU')
        # Initialize two variables named a and b to store the number of vowels in the first and second half of s, and set them to zero
        a = b = 0
        # Initialize two variables named i and j to store the indices of the first and last characters of s, and set them to zero and len(s) - 1 respectively
        i, j = 0, len(s) - 1
        # Use a while loop to run until i and j cross each other, which means that both halves of s have been checked
        while i < j:
            # Increment a by one if the character at index i is a vowel, using the in operator to check membership in the set
            a += s[i] in vowels
            # Increment b by one if the character at index j is a vowel, using the in operator to check membership in the set
            b += s[j] in vowels
            # Increment i by one to move to the next character in the first half
            i += 1
            # Decrement j by one to move to the previous character in the second half
            j -= 1
        # Return true if a and b are equal, which means that both halves have the same number of vowels
        return a == b

""" 
Complexity

    The time complexity is O(n), where n is the length of the string. This is because the code loops through each character in the string, which takes O(n) time, and performs 
    constant-time operations on the set object, such as checking membership.
    
    The space complexity is O(1), as the code only uses a set object of fixed size 10, which is a constant. The code does not use any extra space that depends on the input size. 
    Therefore, the overall space complexity is O(1).
 """