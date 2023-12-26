class Solution:
    # This function returns the number of ways to roll n dice with k faces each to get a target sum
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:        
        # Each dice is unique, e.g. 6+1 and 1+6 are different ways

        # Brute-force approach: use top-down dynamic programming (DP):
        # Define ways(n,k) as the number of ways to roll n dice with k faces each
        # Then we have the recurrence relation:
        #      ways(n,k) =
        #        ways(n-1,k-1) # roll a one on the last dice, then continue with the rest
        #       +ways(n-2,k-1) # roll a two on the last dice, then continue with the rest
        #       +...
        #       +ways(n-k,k-1) # roll a k on the last dice, then continue with the rest

        # Since ways(n,k) only depends on k-1, we can use an in-place DP trick to reduce memory use
        # We only need to store the values of ways for the current and previous k

        # Another possible approach: for each 1..k, we can roll
        #    r_k rolls of k: then we have to get target-r_k*k with rolls of 1..k-1 in n-r_k
        #    We can use combinatorics to get the total ways for each r_k
        #    But this is essentially the same as the top-down DP approach

        # Base cases: if target is out of range, return 0
        # If target is equal to the minimum or maximum possible sum, return 1
        if target < n: return 0 # min roll is 1
        if target == n: return 1 # min roll every time
        if target == n*k: return 1 # max roll every time
        if target > n*k: return 0

        ### DP solution: will be faster for cumulative sum reasons, and less memory
        # Time complexity: O(target) work per iteration, O(n) iterations: O(n*target)
        # Space complexity: O(target) to store the ways array
        ways = [0]*(target+1) # initialize the ways array with zeros
        ways[0] = 1 # base case: one way to get zero sum with zero dice
        BIG = 10**9+7 # modulo to avoid overflow
        for _ in range(n): # loop for n times, each time representing one dice
            w = sum(ways[t] for t in range(max(target-k, 0),target)) % BIG # compute the sum of ways to roll prior k values
            ways[target] = w # update the ways for the target value
            for t in range(target-1, -1, -1): # loop backwards from target-1 to 0
                if t-k >= 0: w += ways[t-k] # if t-k is valid, add the ways for t-k to w
                w -= ways[t] # subtract the ways for t from w
                ways[t] = w # update the ways for t

        return ways[target] % BIG # return the final answer modulo BIG

"""
The approach is to use dynamic programming to store the number of ways to roll a certain sum with a certain number of dice. The idea is to update the ways array for each dice, using the previous values of the array. The final answer is the value of ways[target] after n iterations. The time complexity is O(n*target) and the space complexity is O(target).
"""