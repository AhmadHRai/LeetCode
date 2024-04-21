# From leetcode the hard way
""" Their comments
If you have solved enough DP problems, you should see the similar pattern.

    Handle the case when k is all used
    Handle the case when i reaches the end
    Result of choosing the current element
    Result of not choosing the current element
    Return the min result

 """
class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @cache
        def dp(i, prev, prev_cnt, k):
            # set it to inf as we will take the min later
            if k < 0: return inf
            # we delete all characters, return 0
            if i == len(s): return 0
            # here we can have two choices, we either
            # 1. delete the current char
            # 2. keep the current char
            # we calculate both result and take the min one
            delete = dp(i + 1, prev, prev_cnt, k - 1)
            if s[i] == prev:
                # e.g. a2 -> a3
                keep = dp(i + 1, prev, prev_cnt + 1, k)
                # add an extra 1 for the following cases
                # since the length of RLE will be changed
                # e.g. prev_cnt = 1: a -> a2
                # e.g. prev_cnt = 9: a9 -> a10
                # e.g. prev_cnt = 99: a99 -> a100 
                # otherwise the length of RLE will not be changed
                # e.g. prev_cnt = 3: a3 -> a4
                # e.g. prev_cnt = 8: a8 -> a9
                # alternative you can calculate `RLE(prev_cnt + 1) - RLE(cnt)`
                if prev_cnt in [1, 9, 99]:
                    keep += 1
            else:
                # e.g. a
                keep = dp(i + 1, s[i], 1, k) + 1
            return min(delete, keep)
        
        # dp(i, prev, prev_cnt, k) returns the length of RLE with k characters to be deleted
        # starting from index i 
        # with previous character `prev`
        # with `prev_cnt` times repeated so far
        return dp(0, "", 0, k)

""" 
Complexity:
    Time: The time complexity of this code is O(n^2 * k), where n is the length of the input string s, and k is the number of characters to be deleted. This is because the code loops 
    through each character in the string s once, and for each character, it considers two choices: delete it or keep it. Deleting a character reduces the value of k by one, while 
    keeping a character updates the previous character and its count. The code also checks if the current character is the same as the previous character, and if so, it adds one to the 
    length of the RLE string if the count is in [1, 9, 99]. The code uses a cache to store the results of the subproblems, which avoids repeated computations. The cache has a size of O
    (n * k), since there are n possible values for the index i, k possible values for the number of deletions k, and a constant number of possible values for the previous character prev 
    and its count prev_cnt.

    Space: The space complexity of this code is O(n * k), where n and k are the same as above. This is because the code uses a cache to store the results of the subproblems, which has a 
    size of O(n * k). The code also uses a constant amount of extra space for the variables delete, keep, width, and hash. Therefore, the total space complexity is O(n * k).
 """