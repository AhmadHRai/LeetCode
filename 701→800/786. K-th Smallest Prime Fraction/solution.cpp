class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1, mid;
        vector<int> res;

        while (left <= right) {
            mid = left + (right - left) / 2;
            int j = 1, total = 0, num = 0, den = 0;
            double maxFrac = 0;
            for (int i = 0; i < n; ++ i) {
                while (j < n && arr[i] >= arr[j] * mid) {
                    ++j;
                }
                
                total += n - j;

                if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i; den = j;
                }
            }

            if (total == k) {
                res = {arr[num], arr[den]};
                break;
            }

            if (total > k) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return res;
    }
};

/* 
Approach
    The solution employs a binary search strategy to find the k-th smallest fraction from an array of prime numbers. The key insight is to understand that for any given fraction value, we can count how many fractions in the array are less than or equal to this value. By adjusting the fraction value based on the count, we can efficiently narrow down the search space.

Initialization: 
    The search space is defined between 0 and 1, representing the possible range of fraction values.
    Binary Search: For each iteration, the midpoint of the current search space is calculated. This midpoint represents a potential fraction value.
    Counting Fractions: For each number in the array, we determine the smallest index j such that the fraction formed by dividing the current number by arr[j] is greater than the midpoint. This allows us to count all fractions that are less than or equal to the midpoint.
    Adjusting Search Space: If the count of fractions is equal to k, we have found the k-th smallest fraction. If the count is less than k, we need a larger fraction, so we adjust the lower bound of the search space. If the count is greater than k, we need a smaller fraction, so we adjust the upper bound of the search space.
    Tracking Maximum Fraction: To efficiently return the result, we keep track of the maximum fraction encountered that is less than or equal to the midpoint. This fraction is updated whenever a new maximum is found.

Dry Run
    Given arr = [1, 2, 3, 5] and k = 3, the process is as follows:

    Initialization: n = 4, left = 0, right = 1.
    First Iteration: mid = 0.5.
    For Loop: For i = 0, j is incremented until arr[i] >= arr[j] * mid is false, updating total and maxFrac.
    For i = 1: Similar process, updating total and maxFrac.
    For i = 2: Similar process, no update to maxFrac.
    Result: total == k, so res = {arr[1], arr[3]} = {2, 5}.

Complexity Analysis
    Time Complexity: O(n log n), due to the binary search and the loop through the array for each midpoint.
    Space Complexity: O(1), as the algorithm uses a constant amount of space to store the search bounds, count, and result.

 */