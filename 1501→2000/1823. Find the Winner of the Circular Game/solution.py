class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        # Calculate the winner's position in a 1-indexed system
        # by applying the Josephus problem solution and adding 1
        return self.josephus(n, k) + 1

    def josephus(self, n, k):
        # Base case: when there are no people, the position is 0
        # Recursive case: calculate the Josephus position for n - 1 people
        return 0 if n == 0 else (self.josephus(n - 1, k) + k) % n 

"""
def josephus(n, k):
    return 0 if n == 0 else (josephus(n - 1, k) + k) % n

print(josephus(41, 3)) 

https://www.youtube.com/watch?v=-JGuXte8BOg
"""

"""
Approach

    The solution uses the Josephus problem algorithm to find the winner's position in a circular game. The Josephus problem determines the safe position in a group where every k-th person is eliminated in a circle until only one person remains.
    - The `josephus` method calculates the position of the winner for `n` people and step `k` using a recursive formula.
    - The `findTheWinner` method adjusts the result from the 0-indexed system (used in the Josephus problem) to a 1-indexed system (as required by the problem) by adding 1.

Complexity

    Time complexity: O(n), due to the recursion depth and calls made to the `josephus` method.
    
    Space complexity: O(n), due to the recursive call stack used in the `josephus` method.
"""