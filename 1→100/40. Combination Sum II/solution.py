class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(start: int, target: int, path: List[int]):
            # Base case: if target is 0, we've found a valid combination
            if target == 0:
                res.append(path[:])  # Add a copy of the current path to the results
                return
            
            # Iterate over the candidates starting from the 'start' index
            for i in range(start, len(candidates)):
                # Skip duplicates to avoid generating the same combination multiple times
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                
                # If the current candidate exceeds the target, no point in continuing further
                if candidates[i] > target:
                    break
                
                # Include the current candidate in the current path
                path.append(candidates[i])
                
                # Recursively call backtrack with the updated target and starting index
                backtrack(i + 1, target - candidates[i], path)
                
                # Backtrack: remove the last added candidate from the current path
                path.pop()

        # Sort candidates to handle duplicates and to enable early termination
        candidates.sort()
        
        # Initialize the result list to store all valid combinations
        res = []
        
        # Begin backtracking from index 0, with the full target and an empty path
        backtrack(0, target, [])
        
        # Return the list of all valid combinations
        return res

"""
Approach:
1. The problem is solved using a backtracking approach.
2. First, the candidates array is sorted to handle duplicates easily and enable early termination of branches that exceed the target.
3. The `backtrack` function is defined to explore all possible combinations starting from a given index:
   - The base case checks if the target is 0, meaning the current path is a valid combination, which is then added to the result list.
   - The loop iterates over the candidates starting from the given index.
   - Duplicates are skipped to avoid generating the same combination multiple times.
   - If a candidate exceeds the target, the loop is terminated early (since the candidates are sorted).
   - The candidate is added to the current path, and `backtrack` is called recursively with the reduced target and the next index.
   - After exploring with the current candidate, it is removed (backtracked) from the path to explore other possibilities.
4. The initial call to `backtrack` starts with index 0, the full target, and an empty path.
5. The result list `res` is returned, containing all unique combinations that sum to the target.

Complexity Analysis:
- Time Complexity: O(2^n), where `n` is the number of candidates. In the worst case, we might explore all subsets.
- Space Complexity: O(n), where `n` is the depth of the recursion tree (equal to the number of elements in the path at most).
"""
