/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();

        // Find the index of the peak element in the mountain array.
        int peakIndex = findPeakIndex(1, length - 2, mountainArr);

        // Binary search for the target in the increasing part of the mountain array.
        int increasingIndex = binarySearch(0, peakIndex, target, mountainArr, false);
        if (mountainArr.get(increasingIndex) == target) 
            return increasingIndex; // Target found in the increasing part.

        // Binary search for the target in the decreasing part of the mountain array.
        int decreasingIndex = binarySearch(peakIndex + 1, length - 1, target, mountainArr, true);
        if (mountainArr.get(decreasingIndex) == target) 
            return decreasingIndex; // Target found in the decreasing part.

        return -1;  // Target not found in the mountain array.
    }

    int findPeakIndex(int low, int high, MountainArray &mountainArr) {
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1; // Move to the right side (increasing slope).
            } else {
                high = mid; // Move to the left side (decreasing slope).
            }
        }
        return low; // Return the index of the peak element.
    }

    int binarySearch(int low, int high, int target, MountainArray &mountainArr, bool reversed) {
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (reversed) {
                if (mountainArr.get(mid) > target)
                    low = mid + 1; // Move to the right side for a decreasing slope.
                else
                    high = mid; // Move to the left side for an increasing slope.
            } else {
                if (mountainArr.get(mid) < target)
                    low = mid + 1; // Move to the right side for an increasing slope.
                else
                    high = mid; // Move to the left side for a decreasing slope.
            }
        }
        return low; // Return the index where the target should be or would be inserted.
    }
};

/*
Approach

    Using a binary search findPeakIndex to locate the peak index of the mountain array.
    Perform a binary search for the target in the increasing part of the mountain array from index 0 to the peak index.
        Use the binarySearch method with the reversed parameter set to false.
        If the target is found in the increasing part, return the index.
    If the target is not found in the increasing part, perform a binary search for the target in the decreasing part of the mountain array from the peak index to the end.
        Use the binarySearch method with the reversed parameter set to true.
        If the target is found in the decreasing part, return the index.
    If the target is not found in either part of the array, return -1 to indicate the absence of the target.

Complexity

    Time complexity: O(log(N))O(log(N))O(log(N))
    Since we are performing binary search three times: one time to find the peak, another time to find the target in increasing part and last time to find it in decreasing part.
    This cost us (3 * log(N)) which is O(log(N)).
    where N is the size of Mountain Array.
    Space complexity: O(1)O(1)O(1)
    Since we are using only constant variables and not using anyother data structures.

*/