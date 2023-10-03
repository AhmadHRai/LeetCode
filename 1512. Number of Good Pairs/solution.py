class Solution:

    # search for duplicate numbers
    def numIdenticalPairs(self, nums: List[int]) -> int:

        # number of good pairs
        repeat = {}
        num = 0

        # for every element in nums
        for v in nums:

            # number of repeated digits
            if v in repeat:

                # count number of pairs based on duplicate values
                num += repeat[v]

                # increment the number of counts
                repeat[v] += 1
            # number has not been seen before
            else:
                repeat[v] = 1
        # return
        return num


""" 
Solution Idea
The idea is storing the number of repeated elements in a dictionary/hash table and using mathmatics to calculate the number of combinations.

Fundamental Math Concept (Combinations)
The "# of pairs" can be calculated by summing each value from range 0 to n-1, where n is the "# of times repeated". So the "# of pairs" for the 5 repeated values, would be 0+1+2+3+4 = 10.

Another way to think about it is:

Notice in the table below how the number of pairs increments by adding the previous "# of times repeated" to the previous "# of pairs."

For example: to get the "# of pairs" for 3 repeated values, you would add the previous "# of times repeated" (which is 2) with the previous "# of pairs" (which is 1). Therefore, the "# of pairs for 3 repeated values is 2+1=3. In this method, you don't peform the same computations multiple times.

Example Table of # of repeated items with their corresponding # of pairs
# of times repeated	    # of pairs
        2                   1
        3	                3
        4	                6
        5	                10
        6	                15


The time complexity of this code is O(n), where n is the length of nums, because it iterates through the list once and performs constant time operations for each element.
The space complexity is O(m), where m is the number of distinct elements in nums, because it uses a dictionary to store the counts of each element.

 """
