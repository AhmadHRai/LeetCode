// Define a public class that contains a function to search the first and last position of a target element in a sorted array
public class Solution {
	// Define a public function that takes an array of integers and a target element as parameters
	public int[] searchRange(int[] A, int target) {
		// Call a private static function to find the first index that is greater than or equal to the target
		int start = Solution.firstGreaterEqual(A, target);
		// If the start index is out of bounds or the element at the start index is not equal to the target, return an array of -1 values
		if (start == A.length || A[start] != target) {
			return new int[]{-1, -1};
		}
		// Otherwise, return an array of the start index and the end index, which is the first index that is greater than or equal to the target plus one minus one
		return new int[]{start, Solution.firstGreaterEqual(A, target + 1) - 1};
	}

	// Define a private static function that takes an array of integers and a target element as parameters
	// This function finds the first number that is greater than or equal to the target
	// This function could return A.length if the target is greater than A[A.length-1]
	// This function is actually the same as lower_bound in C++ STL
	private static int firstGreaterEqual(int[] A, int target) {
		// Initialize two variables to store the low and high indices of the array
		int low = 0, high = A.length;
		// Use a while loop to perform binary search on the array
		while (low < high) {
			// Calculate the middle index by adding the low and high indices and shifting right by one bit
			int mid = low + ((high - low) >> 1);
			// low <= mid < high
			// If the element at the middle index is smaller than the target, move the low index to the right of the middle index
			if (A[mid] < target) {
				low = mid + 1;
			} else {
				// If the element at the middle index is greater than or equal to the target, move the high index to the middle index
				// This ensures that we do not miss the first occurrence of the target
				high = mid;
			}
		}
		// Return the low index, which is either the first index that is greater than or equal to the target, or A.length if no such index exists
		return low;
	}
}

/* 
The time complexity of this solution is O(log n), where n is the length of the array. This is because we use binary search twice on the array, which reduces the search space by 
half in each iteration.

The space complexity of this solution is O(1), because we only use constant extra space for the variables low, high, mid, and start.
*/