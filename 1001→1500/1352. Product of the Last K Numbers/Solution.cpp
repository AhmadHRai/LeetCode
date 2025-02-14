class ProductOfNumbers {
    private:
        // Stores cumulative product of the stream
        vector<int> prefixProduct;
        int size = 0; // Size of the valid product list
    
    public:
        // Initializes the product list with 1 to handle multiplication logic
        ProductOfNumbers() {
            prefixProduct.push_back(1);
            size = 0;
        }
    
        // Adds a number to the stream
        void add(int num) {
            if (num == 0) {
                // If num is 0, reset the cumulative products since multiplication with 0 invalidates previous products
                prefixProduct = {1};
                size = 0;
            } else {
                // Append the cumulative product of the current number with the last product
                prefixProduct.push_back(prefixProduct[size] * num);
                size++;
            }
        }
    
        // Returns the product of the last k elements
        int getProduct(int k) {
            // Check if the requested product length exceeds the size of the valid product list
            if (k > size) return 0;
    
            // Compute the product of the last k elements using division
            return prefixProduct[size] / prefixProduct[size - k];
        }
    }

    /*
    Approach Summary:
        This solution uses a prefix product array to efficiently store and compute the product of elements in a stream. It handles multiplication by zero by resetting the 
        prefix product list and updates the product list by appending new cumulative products.
    
    Complexity Analysis:
        Time Complexity:
            `add`: O(1), because each operation involves a constant number of steps.
            `getProduct`: O(1), because it involves a constant number of operations.
        Space Complexity: O(N), where N is the number of elements added to the stream, for storing the prefix product list.
    */
    