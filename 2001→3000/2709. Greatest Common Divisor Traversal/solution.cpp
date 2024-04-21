class Solution {
    // Function to find the representative of a set in the union-find structure.
    int getf(vector<int> &f, int x) {
        return f[x] == x ? x : (f[x] = getf(f, f[x]));
    }
    
    // Function to merge two sets in the union-find structure.
    void merge(vector<int> &f, vector<int> &num, int x, int y) {
        x = getf(f, x);
        y = getf(f, y);
        if (x == y) {
            return;
        }
        if (num[x] < num[y]) {
            swap(x, y);
        }
        f[y] = x;
        num[x] += num[y];
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const int n = nums.size();
        if (n ==  1) {
            return true;
        }
        vector<int> f(n), num(n);
        for (int i =  0; i < n; ++i) {
            f[i] = i; // Initialize each element as its own parent.
            num[i] =  1; // Initialize the count of numbers in each set.
        }
        unordered_map<int, int> have; // Map to store the representative of each number's set.
        
        // Process each number.
        for (int i =  0; i < n; ++i) {
            int x = nums[i];
            if (x ==  1) {
                return false; // If a number is  1, it cannot be part of any pair with GCD >  1.
            }
            // Find the prime factors of the number.
            for (int d =  2; d * d <= x; ++d) {
                if (x % d ==  0) {
                    // If the factor is already encountered, merge the sets.
                    if (have.count(d)) {
                        merge(f, num, i, have[d]);
                    } else {
                        have[d] = i; // Otherwise, mark the current number as the representative.
                    }
                    // Divide the number by the factor to find the next prime factor.
                    while (x % d ==  0) {
                        x /= d;
                    }  
                }
            }
            // If there's a factor greater than  1 left, it must be a prime number.
            if (x >  1) {
                if (have.count(x)) {
                    merge(f, num, i, have[x]);
                } else {
                    have[x] = i; // Mark the current number as the representative.
                }
            }
        }
        // Check if all numbers are in the same set (i.e., the count of numbers is equal to the total number of numbers).
        return num[getf(f,  0)] == n;
    }
};

/* 
Approach

    Initialization: Initialize a union-find structure with n elements, where n is the size of the input array. Each element is its own parent, and the count of numbers in each set is initialized to 1.
    Process Numbers: For each number in the array, find its prime factors. If a factor is already encountered, merge the sets of the current number and the number with the same factor. Otherwise, mark the current number as the representative of its set.
    Merge Sets: When merging sets, ensure that the set with the larger count is merged into the set with the smaller count to maintain the count accurately.
    Final Check: After processing all numbers, check if all numbers are in the same set by comparing the count of numbers in the set with the total number of numbers.

Complexity Analysis

    Time Complexity: The time complexity is primarily influenced by the factorization of each number and the union-find operations. The factorization is done in O(sqrt(x)) for each number, and the union-find operations are O(1) on average. Therefore, the overall time complexity is O(n * sqrt(x_max)), where n is the number of elements in the array and x_max is the maximum number in the array.
    Space Complexity: The space complexity is O(n) due to the storage required for the union-find structure, the count array, and the map to store the representative of each number's set.
 */