class Solution {
public:
    vector<int> findArray(vector<int>& A) {
        for (int i = A.size() - 1; i > 0; --i)
            A[i] ^= A[i - 1];
        return A;
    }
};

/* 
Approach
    Since pref is the prefix array,
    it's calculated from arr one by one,
    we can doing this process reverssely to recover the original array.

    Since
    pref[i] = pref[i-1] ^ A[i]
    so we have
    pref[i] ^ pref[i-1] = A[i]

    So we simply change - to ^ in the intuition solution

    The reverse operation of + is -
    The reverse operation of ^ is still ^
    More general, we can apply this solution to prefix of any operation.

Complexity
    Time O(n)
    Space O(n)
 */