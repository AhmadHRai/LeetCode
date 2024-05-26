# 40ms Beats 100.00% of users with Python3
# 16.68MB Beats 74.63% of users with Python3

MOD = 1000000007

def matMul(mat1, mat2):
    """
    Multiplies two matrices and returns the result.

    Args:
    mat1 (List[List[int]]): The first matrix.
    mat2 (List[List[int]]): The second matrix.

    Returns:
    List[List[int]]: The result of matrix multiplication.
    """
    r1 = len(mat1)
    r2, c2 = len(mat2), len(mat2[0])
    ret = [[0]*c2 for _ in range(r1)]
    for i in range(r1):
        for j in range(c2):
            for k in range(r2):
                ret[i][j] += mat1[i][k]*mat2[k][j]
            ret[i][j] %= MOD

    return ret

# Four states of attendance award: P, A, L, LL
matrix = [
    # P, L, LL, A, AP, AL, ALL
    [ 1, 1, 0,  1, 0, 0, 0 ], # P
    [ 1, 0, 1,  1, 0, 0, 0 ], # L
    [ 1, 0, 0,  1, 0, 0, 0 ], # LL
    [ 0, 0, 0,  0, 1, 1, 0 ], # A
    [ 0, 0, 0,  0, 1, 1, 0 ], # AP
    [ 0, 0, 0,  0, 1, 0, 1 ], # AL
    [ 0, 0, 0,  0, 1, 0, 0 ], # ALL
]

n = 100000
mats = [matrix]
while n:
    mats.append(matMul(mats[-1], mats[-1]))
    n >>= 1

class Solution:
    def checkRecord(self, n: int) -> int:
        """
        Counts the number of attendance records with 'n' days, considering constraints.

        Args:
        n (int): The number of days.

        Returns:
        int: The count of valid attendance records modulo 10^9 + 7.
        """
        # Initialize the result matrix
        rslts = [[1, 1, 0, 1, 0, 0, 0]]
        x = n-1
        matIdx = 0
        while x:
            if x&1:
                rslts = matMul(rslts, mats[matIdx])
            x >>= 1
            matIdx += 1

        # Sum up the counts for all possible attendance records
        count = sum(rslts[0]) % MOD
        return count

"""
Approach:
    The solution builds a matrix array of mat^0, mat^1, mat^2, mat^3, ..., where mat is a matrix 
    representing the suffix states of attendance awards. It then multiplies the matrix according 
    to the binary representation of n-1 to compute the final result. The solution uses modular 
    arithmetic to avoid integer overflow and returns the count of valid attendance records modulo 10^9 + 7.

Complexity Analysis:
- Time Complexity: O(log n). The solution performs matrix exponentiation using repeated squaring, 
  which requires logarithmic time complexity.
- Space Complexity: O(1). The solution uses constant space for storing matrices and variables, 
  regardless of the value of 'n'.
"""
