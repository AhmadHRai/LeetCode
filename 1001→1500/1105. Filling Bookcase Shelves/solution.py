from typing import List

class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)  # Get the number of books
        # dp[i] will store the minimum height of the bookshelf needed for the first i books
        dp = [float('inf')] * (n + 1)  # Initialize dp array with infinity
        dp[0] = 0  # Base case: no books require zero height
        
        # Iterate through each book position
        for i in range(1, n + 1):
            width_sum = 0  # Initialize the width sum of the current shelf
            max_height = 0  # Initialize the maximum height of books on the current shelf
            
            # Try to fit books from position j to i on the current shelf
            for j in range(i, 0, -1):
                width_sum += books[j - 1][0]  # Add the width of the current book
                if width_sum > shelfWidth:  # If the width exceeds the shelf width, stop
                    break
                
                max_height = max(max_height, books[j - 1][1])  # Update the maximum height of the current shelf
                # Calculate the minimum height needed for the first i books
                dp[i] = min(dp[i], dp[j - 1] + max_height)
        
        return dp[n]  # Return the minimum height needed for all books

"""
Approach:
- Use dynamic programming to find the minimum height of the bookshelf required to place all books.
- Maintain a dp array where `dp[i]` represents the minimum height needed to fit the first `i` books.
- For each book position `i`, determine the height required if books from position `j` to `i` are placed on the current shelf.
  - Calculate the total width of these books and check if it fits on the shelf.
  - Track the maximum height of the books on this shelf.
  - Update `dp[i]` with the minimum height required, considering the previous shelves (`dp[j - 1]`) and the height of the current shelf.
  
Complexity Analysis:
- Time Complexity: O(n^2), where n is the number of books. For each book `i`, we may consider up to `i` previous books.
- Space Complexity: O(n), due to the dp array used to store the minimum height for each number of books.
"""