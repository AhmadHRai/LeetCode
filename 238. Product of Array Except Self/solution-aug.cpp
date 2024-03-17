class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        vector<int> ans(n); // Initialize the result vector with the same size as the input array
        vector<int> left_Product(n); // Initialize the left product vector
        vector<int> right_Product(n); // Initialize the right product vector
        left_Product[0] = 1; // The product of elements to the left of the first element is 1
        for(int i=1; i<n; i++){ // Iterate through the array starting from the second element
            left_Product[i] = left_Product[i-1] * nums[i-1]; // Calculate the product of elements to the left of the current element
        }
        right_Product[n-1] = 1; // The product of elements to the right of the last element is 1
        for(int i=n-2; i>=0; i--){ // Iterate through the array in reverse order starting from the second last element
            right_Product[i] = right_Product[i+1] * nums[i+1]; // Calculate the product of elements to the right of the current element
        }
        for(int i=0; i<n; i++){ // Iterate through the array to calculate the final product array
            ans[i] = left_Product[i] * right_Product[i]; // Multiply the left and right products for each element
        }
        return ans; // Return the final product array
    }
};

/* 
Approach Explanation

    Initialization: The solution starts by initializing three vectors: ans, left_Product, and right_Product. The ans vector will store the final product array, while left_Product and 
    right_Product will store the cumulative product of elements to the left and right of each element in the original array, respectively.
    
    Left Product Calculation: The left_Product vector is filled by iterating through the original array from left to right, multiplying the current element by the product of all 
    elements to its left.
    
    Right Product Calculation: Similarly, the right_Product vector is filled by iterating through the original array from right to left, multiplying the current element by the product 
    of all elements to its right.
    
    Final Product Calculation: Finally, the ans vector is filled by multiplying the corresponding elements in left_Product and right_Product for each element in the original array. 
    
    This gives the product of all elements except for the current element.


Complexity Analysis

    Time Complexity: The time complexity of this solution is O(n), where n is the size of the input array. This is because each element in the array is processed once to calculate the 
    left and right products, and then once more to calculate the final product array.
    
    Space Complexity: The space complexity is O(n), as the solution uses three additional vectors of the same size as the input array to store intermediate results.

 */