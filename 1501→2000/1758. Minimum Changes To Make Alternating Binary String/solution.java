/* 
Approach:
    Small observation that the sequence of index is [0,1,2,3..],
    if we get its module by 2, we get [0,1,0,1,0..],
    which is the alternating binary sequence we want.

    So we iterate the string,
    check if the characters[i] is same as the i % 2.
    Note that s[i] is a character,
    and s[i] - '0' making it to integer.

    We accumulate the number of difference,
    which is the number of operation to make it into 01 string.

    We can do the same to find out res,
    the number of operation for 10 string.
    But we don't have to,
    becaue this equals to s.length - res.
 */

class Solution {
    public int minOperations(String s) {
        int res = 0;
        int len = s.length();
        char[] chars = s.toCharArray(); // we can use char array to reduce runtime 

        for (int i = 0; i < len; ++i)
            if (chars[i] - '0' != i % 2)
                res++;

        return Math.min(res, len - res);
    }
}

/* 
Complexity
    Time O(n)
    Space O(1)
 */