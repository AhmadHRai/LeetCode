class Solution {
    public int[] rearrangeArray(int[] nums) {
        // Create lists to hold positive and negative numbers
        List<Integer> pos = new ArrayList<>();
        List<Integer> neg = new ArrayList<>();

        // Iterate over the input array nums
        for (int num : nums) {
            // Separate positive and negative numbers into different lists
            if (num >=  0) {
                pos.add(num);
            } else {
                neg.add(num);
            }
        }

        // Index variable to track current position in the rearrangement process
        int i =  0;
        // While loop to alternate between positive and negative numbers
        while (2 * i < nums.length) {
            // Assign the next positive number to an even index in nums
            nums[2 * i] = pos.get(i);
            // Assign the next negative number to an odd index in nums
            nums[2 * i +  1] = neg.get(i);
            // Increment the index for the next iteration
            i++;
        }

        // Handle the case where the array length is odd
        // Copy the last remaining positive number to the end of the array
        if (nums.length %  2 !=  0 && !pos.isEmpty()) {
            nums[nums.length -  1] = pos.remove(pos.size() -  1);
        }

        // Return the rearranged array
        return nums;
    }
}

/* 
Complexity:
Time Complexity Analysis:

    The initial for-loop iterates over the entire input array once, so this operation takes O(n) time, where n is the length of the input array.
    The while loop runs until it reaches half the length of the input array, so this part also takes O(n) time.
    Since we perform list operations inside the loops, these contribute to O(1) time complexity per operation since we only ever access elements by index.
    Therefore, the overall time complexity is O(n), assuming that n is the length of the input array.

Space Complexity Analysis:

    We create two separate lists, pos and neg, to hold positive and negative numbers. In the worst case, these lists could contain all elements of the input array, leading to a space complexity of O(n).
    Additionally, the input array itself requires space proportional to its size, which is O(n).
    Thus, the total space complexity is O(n) due to the extra storage required for the two lists.

 */