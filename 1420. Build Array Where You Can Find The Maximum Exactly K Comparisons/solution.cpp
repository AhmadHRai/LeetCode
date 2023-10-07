class Solution {
public:
    /* let ways[i][j][k] = # ways to construct an array of length i with max element equal to j and a search cost of k. */
    long long ways[51][101][51];
    const int MOD = 1e9 + 7;
    
    int numOfArrays(int n, int m, int k) {
		/* There are our base cases. For each index 1 <= j <= m, we require ways[1][j][1] = 1 because the array consisting of only the element j
			has length 1, maximum element j, and it has a search cost of 1. */
        for (int j = 1; j <= m; j++) {
                ways[1][j][1] = 1;
        }
        
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= m; b++) {
                for (int c = 1; c <= k; c++) {
                    long long s = 0;

		            /* In this first case, we can append any element from [1, b] to the end of the array. */
                    s = (s + b * ways[a - 1][b][c]) % MOD;
                    
		           /* In this second case, we can append the element "b" to the end of the array. */
                    for (int x = 1; x < b; x++) {
						s = (s + ways[a - 1][x][c - 1]) % MOD;
                    }
					
                    ways[a][b][c] = (ways[a][b][c] + s) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int j = 1; j <= m; j++) {
            ans = (ans + ways[n][j][k]) % MOD;
        }
        
        return int(ans);
    }
};

/*
Let ways[i][j][k] be the number of ways to construct an array of length i with maximum element equal to j at a search cost of k.

There are two subproblems that contribute to ways[i][j][k]:

    Clearly, we require ways[i][j][k] += j * ways[i - 1][j][k]. Why? Because if we have an array of length i - 1 with maximum element equal to j at a search cost of k, then we can just append any element from [1, 2, ... j] to this array, and we end up with an array of length i with maximum element equal to j at a search cost of k. Note that neither the search cost nor the maximum element change since we're only appending elements from [1,2, ..., j]. Only the length changes by one.

    We also require ways[i][j][k] += SUM from x=1 to j-1 of ways[i - 1][x][k - 1] (the sum is inclusive on both ends). This is true because if we have an array of length i - 1 with maximum element (strictly) less than j at a search cost of k - 1, then we can simply append the element j to the end of this array (which adds a comparison cost of one), and we obtain a valid solution.

Now the answer is just the sum over all ways[i][x][k] from x = 1 to k because there is no constraint on what the maximum element should be.

The runtime of this solution is O(NKM^2), but you can achieve O(NKM * log(M)) with a Fenwick tree, or O(NKM) by using prefix sums and eliminating the innermost for-loop.
*/