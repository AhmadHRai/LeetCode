class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output; // Initialize the output vector
        int n = nums.size(); // Get the size of the input array
        output.push_back(1); // The product of elements to the left of the first element is 1
        for(int i=1; i<=n; i++){ // Iterate through the array
            output.push_back(output[i-1] * nums[i-1]); // Calculate the product of elements to the left of the current element
        }
        int right = 1; // Initialize the right product
        for(int i=n-1; i>=0; i--){ // Iterate through the array in reverse
            output[i] *= right; // Multiply the left product by the right product
            right *= nums[i]; // Update the right product
        }
        output.pop_back(); // Remove the last element, which was added for convenience during calculation
        return output; // Return the final product array
    }
};

/* 
Approach

    Initialization: The solution starts by initializing an empty vector output and setting its first element to 1. This is because the product of all elements to the left of the first 
    element is 1.
    
    Left Product Calculation: The solution then iterates through the input array nums, multiplying each element by the product of all elements to its left (stored in output[i-1]). This 
    is done by pushing the product onto the output vector.
    
    Right Product Calculation: After calculating the left products, the solution iterates through the output vector in reverse, multiplying each element by the product of all elements 
    to its right. This is done by maintaining a right variable that accumulates the product of elements to the right.
    
    Final Product Calculation: The final step involves multiplying the left and right products for each element, which gives the product of all elements except for the current element.

Complexity Analysis

    Time Complexity: The time complexity of this solution is O(n), where n is the size of the input array. This is because each element in the array is processed once to calculate the 
        left and right products, and then once more to calculate the final product array.

    Space Complexity: The space complexity is O(n), as the solution uses an additional vector of the same size as the input array to store intermediate results.

this solution is better in terms of space complexity, as it uses less additional space than the first solution. However, both solutions are efficient in terms of time complexity
 */

