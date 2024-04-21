class Solution {
    public int trap(int[] height) {
        if (height == null || height.length == 0) {
            return 0;
        }
        int left = 0; int right = height.length - 1; // Pointers to both ends of the array.
        int maxLeft = 0; int maxRight = 0;
        
        int totalWater = 0;
        while (left < right) {
            // Water could, potentially, fill everything from left to right, if there is nothing in between.
            if (height[left] < height[right]) {
                // If the current elevation is greater than the previous maximum, water cannot occupy that point at all.
                // However, we do know that everything from maxLeft to the current index, has been optimally filled, as we've
                // been adding water to the brim of the last maxLeft.
                if (height[left] >= maxLeft) { 
                    // So, we say we've found a new maximum, and look to see how much water we can fill from this point on.
                    maxLeft = height[left]; 
                // If we've yet to find a maximum, we know that we can fill the current point with water up to the previous
                // maximum, as any more will overflow it. We also subtract the current height, as that is the elevation the
                // ground will be at.
                } else { 
                    totalWater += maxLeft - height[left]; 
                }
                // Increment left, we'll now look at the next point.
                left++;
            // If the height at the left is NOT greater than height at the right, we cannot fill from left to right without over-
            // flowing; however, we do know that we could potentially fill from right to left, if there is nothing in between.
            } else {
                // Similarly to above, we see that we've found a height greater than the max, and cannot fill it whatsoever, but
                // everything before is optimally filled
                if (height[right] >= maxRight) { 
                    // We can say we've found a new maximum and move on.  
                    maxRight = height[right]; 
                // If we haven't found a greater elevation, we can fill the current elevation with maxRight - height[right]
                // water.
                } else {
                    totalWater += maxRight - height[right]; 
                }
                // Decrement left, we'll look at the next point.
                right--;
            }
        }
        // Return the sum we've been adding to.
        return totalWater;
    }
}

/* 
Approach

    The solution uses two pointers, `left` and `right`, to traverse the array from both ends towards the center. It maintains two variables, `maxLeft` and `maxRight`, to keep track 
    of the maximum height encountered so far from the left and right ends, respectively. The `totalWater` variable is used to accumulate the total amount of water that can be trapped.

    The algorithm iterates through the array, comparing the heights at the `left` and `right` pointers. If the height at `left` is less than the height at `right`, it means that the 
    water can be trapped between the current `left` height and the `maxRight` height. If the current `left` height is greater than or equal to `maxLeft`, it updates `maxLeft` to the 
    current `left` height. Otherwise, it calculates the amount of water that can be trapped at the current `left` position and adds it to `totalWater`. The `left` pointer is then 
    incremented.

    If the height at `left` is greater than or equal to the height at `right`, it means that the water can be trapped between the current `right` height and the `maxLeft` height. If 
    the current `right` height is greater than or equal to `maxRight`, it updates `maxRight` to the current `right` height. Otherwise, it calculates the amount of water that can be 
    trapped at the current `right` position and adds it to `totalWater`. The `right` pointer is then decremented.

    This process continues until the `left` and `right` pointers meet, at which point all possible trapped water has been calculated and added to `totalWater`.

Complexity

    Time complexity: O(n), where n is the length of the height array. This is because each element in the array is processed exactly once.
    
    Space complexity: O(1), as the solution uses a constant amount of space to store the pointers and variables and does not depend on the size of the input array.
*/
