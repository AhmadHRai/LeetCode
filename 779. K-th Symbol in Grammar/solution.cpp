class Solution {
public:
    int kthGrammar(int N, int K) {
        // If we are at the first row, return 0
        if (N == 1) return 0;
        // If K is even, then the parent node is 0
        if (K % 2 == 0) return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0;
        // If K is odd, then the parent node is 1
        else return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1;
    }
};

/*
The given code implements a recursive function kthGrammar that takes two integer arguments N and K. The function returns an integer value that represents the value of the K-th symbol in the N-th row of a grammar.

The grammar is defined as follows:

The first row is 0.
For each subsequent row, each occurrence of 0 is replaced by 01, and each occurrence of 1 is replaced by 10.
The function works as follows:

If we are at the first row (N == 1), we return 0.
If the index K is even, then the parent node is 0. We recursively call the function with (N - 1, K / 2) as arguments. If the value returned by this call is 0, we return 1, otherwise we return 0.
If the index K is odd, then the parent node is 1. We recursively call the function with (N - 1, (K + 1) / 2) as arguments. If the value returned by this call is 0, we return 0, otherwise we return 1.
The time complexity of this function is O(N), since we make one recursive call for each row of the grammar. The space complexity of this function is also O(N), since we use a recursive approach and need to store intermediate results on the stack.
*/