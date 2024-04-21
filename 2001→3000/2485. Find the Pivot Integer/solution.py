# Using quick maths:

class Solution:
    def pivotInteger(self, n: int) -> int:
        # Calculate the sum of numbers from 1 to n
        sum = n * (n + 1) // 2
        # Calculate the square root of the sum
        a = math.sqrt(sum)

        # Check if the square root is an integer
        if a - math.ceil(a) == 0:
            # If it is, return the integer part of the square root as the pivot integer
            return int(a)
        else:
            # If not, return -1 to indicate no pivot integer exists
            return -1

        
""" 
Approach:

    Calculate the sum of integers.
        1 to x = x(x+1)/2
        x to n = (1 to n) - (1 to (x-1))
        Equating both we get, x^2= n(n+1)/2

    Find the square root of the sum=n(n+1)/2:

    Take the square root of the sum calculated in step 1 and store it in variable a.
    Check if the square root is an integer:
        If the square root is an integer, it implies that the pivot point exists and that the sum of integers from 1 to that pivot point is equal to the sum of integers from the pivot point to n.
        We can check if the difference between the square root and its ceiling value (rounded up) is zero. If it is, it means the square root is an integer.
        If the difference is zero, return the square root as the pivot integer.
        If not, return -1, indicating that there's no valid pivot integer.

    Return the result:
        If the square root is an integer, return it as the pivot integer.
        If not, return -1.


Maths:
The logic behind the solution involves a mathematical approach to determine if there exists a pivot integer within a given range. The pivot integer is defined as a number x such that 
the sum of all numbers from 1 to x is equal to the sum of all numbers from x+1 to n.

Here's a step-by-step explanation of the logic:

    Calculate the Sum of Numbers: The sum of all numbers from 1 to n is calculated using the formula sum = n * (n + 1) // 2. This formula is derived from the sum of an arithmetic series, which is a common mathematical concept.

    Check for Perfect Square: The sum is then checked to see if it is a perfect square. This is done by taking the square root of the sum (a = math.sqrt(sum)) and checking if the square root is an integer (a - math.ceil(a) == 0). If the square root is an integer, it means the sum is a perfect square, and the pivot integer exists.

    Return the Pivot Integer or -1: If the sum is a perfect square, the square root is returned as the pivot integer. If not, -1 is returned to indicate that no pivot integer exists.

Complexity:
    The time complexity of this solution is O(1) because it performs a constant number of operations regardless of the size of n. 
    The space complexity is also O(1) because it uses a fixed amount of space to store variables and does not depend on the input size.
 """