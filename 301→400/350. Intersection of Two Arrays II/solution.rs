impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        // Define a closure 'counter' to count occurrences of each number in a vector
        let counter = |nums| {
            let mut res = HashMap::new();  // Create a HashMap to store number counts
            for num in nums {
                *res.entry(num).or_insert(0) += 1;  // Increment count for each number in 'nums'
            }
            res  // Return the HashMap with number counts
        };

        // Count occurrences of numbers in both nums1 and nums2 using the 'counter' closure
        let nums1 = counter(nums1);
        let nums2 = counter(nums2);

        // Generate the intersection of nums1 and nums2 based on the counts of each number
        nums1.into_iter()  // Iterate through elements of nums1 HashMap
            .flat_map(|(num, count)| {  // For each key-value pair (num, count)
                // Create an iterator that repeats 'num' up to the minimum of its count in nums2 or nums1
                (0..nums2.get(&num).copied().unwrap_or(0).min(count)).map(move |_| num)
            })
            .collect()  // Collect the results into a vector
    }
}

use std::collections::HashMap;  // Import HashMap from the standard library

/*
Approach:
- Define a closure 'counter' to count occurrences of each number in a vector using HashMap.
- Count occurrences for both nums1 and nums2 using 'counter'.
- Generate the intersection of nums1 and nums2 based on the counts of each number.

Complexity Analysis:
- Time Complexity: O(m + n), where m and n are the lengths of nums1 and nums2, respectively.
  - Counting elements in both vectors using HashMaps takes O(m + n) time.
  - Generating the intersection takes linear time relative to the total number of elements in both vectors.
- Space Complexity: O(m + n), due to the space used by the HashMaps to store counts of elements in nums1 and nums2.
  - The space used by the result vector is also O(m + n), as it can potentially hold all elements of the intersection.
*/