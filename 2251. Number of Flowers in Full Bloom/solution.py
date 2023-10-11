def fullBloomFlowers(self, A: List[List[int]], persons: List[int]) -> List[int]:
        start, end = sorted(a for a,b in A), sorted(b for a,b in A)
        return [bisect_right(start, t) - bisect_left(end, t) for t in persons]

"""
Approach:
    Collect start bloom time point array, then sort it.
    Collect end bloom time point array, then sort it.

    For each time point t in persons:

    Binary search the upper bound of t in start, then we find the started flowers.
    Binary search the lower bound of t in end, then we find the started flowers.
    Blooming flowers = started flowers - ended flowers 


Complexit
    Time O(nlogn + mlogn) where n is the number of flowers and m is the number of days, since it uses a sorting algorithm that takes O(nlogn) time and a binary search that takes 
    O(logn) time for each day. 
    Space O(n)
"""