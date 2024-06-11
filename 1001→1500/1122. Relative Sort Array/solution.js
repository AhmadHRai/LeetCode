/**
 * Sorts the array `arr1` relative to the order defined by `arr2`.
 *
 * @param {number[]} arr1 - The array to be sorted relative to `arr2`.
 * @param {number[]} arr2 - The array defining the relative order for sorting `arr1`.
 * @return {number[]} - The sorted array `arr1` relative to `arr2`.
 */
var relativeSortArray = function (arr1, arr2) {
  // Step 1: Count frequencies of each element in arr1
  const count = Array(1001).fill(0); // Since constraints specify arr1[i] <= 1000
  arr1.forEach((num) => {
    count[num]++;
  });

  // Step 2: Create sorted array relative to arr2
  const ans = [];
  arr2.forEach((num) => {
    while (count[num] > 0) {
      ans.push(num);
      count[num]--;
    }
  });

  // Step 3: Handle elements not present in arr2 (sorting remaining elements)
  for (let i = 0; i < count.length; i++) {
    while (count[i] > 0) {
      ans.push(i);
      count[i]--;
    }
  }

  return ans; // Return the sorted array relative to arr2
};

/*
Approach:
    1. Counting Frequencies:
        - Initialize an array `count` of size 1001 to count occurrences of each element in `arr1`.
        - Use `forEach` to iterate through `arr1` and increment the count for each element.
    2. Sorting Relative to arr2:
        - Initialize an empty array `ans` to store the sorted array.
        - Use `forEach` to iterate through each element in `arr2`. For each element, append it to `ans` as many times as it appears in `arr1` (using `count`).
    3. Sorting Remaining Elements:
        - Use a `for` loop to iterate through `count` to handle elements not present in `arr2`. Append each element to `ans` based on its count.
    4. Return Result:
        - Return the sorted array `ans`, which represents `arr1` sorted relative to the order defined by `arr2`.

Complexity Analysis:
    - Time Complexity: O(n + m)
      where n is the number of elements in `arr1` and m is the number of elements in `arr2`. Counting frequencies takes O(n), and sorting relative to `arr2` and sorting remaining elements each take O(1001), which is constant time.
    - Space Complexity: O(1)
      Additional space is used for the `count` array of fixed size 1001 and `ans` array, which is dependent on input size.

*/
