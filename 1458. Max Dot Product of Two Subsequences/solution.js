/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDotProduct = function(nums1, nums2) {
    const m = nums1.length;
    const n = nums2.length;

    if (m < n) {
        return maxDotProduct(nums2, nums1);
    }

    const dp = new Array(n + 1).fill(Number.NEGATIVE_INFINITY);

    for (let i = 0; i < m; i++) {
        let prev = 0;
        for (let j = 0; j < n; j++) {
            const tmp = dp[j + 1];
            dp[j + 1] = Math.max(prev + nums1[i] * nums2[j], nums1[i] * nums2[j], dp[j], dp[j + 1]);
            prev = tmp;
        }
    }

    return dp[n];    
};

/* 
Approach

Algorithm Overviews:

    Input Processing and Setup:
        Obtain the lengths of the input arrays, m and n.
        Swap arrays if nums1 is shorter than nums2.
        Initialize a dynamic programming array dp of size n + 1 to store maximum dot products.

    Dynamic Programming for Maximum Dot Product:
        Iterate over elements in nums1.
            For each element in nums1, iterate over elements in nums2.
                Calculate the maximum dot product for the current elements from nums1 and nums2, considering various cases.

    Output:
        Return the maximum dot product calculated from the dynamic programming array.

Detailed Explanation:

    Input Processing and Setup:
        Obtain the lengths of the input arrays, m and n.
        Swap arrays if nums1 is shorter than nums2. This ensures nums1 is at least as long as nums2.
        Initialize a dynamic programming array dp of size n + 1 to store maximum dot products. Each element in dp corresponds to the maximum dot product for subsequences up to that point.

    Dynamic Programming for Maximum Dot Product:
        Iterate over elements in nums1.
        For each element in nums1, iterate over elements in nums2.
        Calculate the maximum dot product for the current elements from nums1 and nums2. The maximum dot product is calculated by considering four cases:
            Taking the dot product of the current elements from nums1 and nums2.
            Taking the maximum dot product from the previous element in nums1 and the current element in nums2.
            Taking the maximum dot product from the current element in nums1 and the previous element in nums2.
            Taking the maximum dot product from the previous elements in both nums1 and nums2.

    Output:
        Return the maximum dot product calculated from the dynamic programming array, which corresponds to the maximum dot product of non-empty subsequences of nums1 and nums2 with the same length.

Complexity

    Time complexity: O(mn)O(mn)O(mn)
    The time complexity of this algorithm is O(mn), where m and n are the lengths of the input arrays nums1 and nums2, respectively. This is because there is a nested loop that iterates through both arrays, resulting in O(mn) operations.

    Space complexity: O(n)O(n)O(n)
    The space complexity is O(n), where n is the length of the shorter input array (after swapping if necessary). This is due to the dynamic programming array dp, which is of size n+1, and a few additional variables used in the function. The space used is proportional to the length of the shorter array.

*/