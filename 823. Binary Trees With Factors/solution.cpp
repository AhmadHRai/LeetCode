class Solution {
public:
    // Define a constant mod to be used in the function
    int mod = pow(10,9) + 7;
    // Define a function to calculate the number of factored binary trees
    int numFactoredBinaryTrees(vector<int>& arr) {
        // Sort the input array in ascending order
        sort(arr.begin(), arr.end());
        // Create an unordered map to store the root element and its count
        unordered_map <int, long> rootWithCount;
        // Initialize the count of the first element as 1
        rootWithCount[arr[0]] = 1;
        // Loop through the remaining elements in the array
        for(int i = 1; i < arr.size(); i++){
            // Initialize the count of the current element as 1
            long count = 1;
            // Loop through all the root elements and their counts in the map
            for(auto j : rootWithCount){
                int rootEle = j.first;
                // Check if the current element is divisible by the root element and if its quotient is present in the map
                if(arr[i] % rootEle == 0 && rootWithCount.find(arr[i] / rootEle) != rootWithCount.end()){
                    // Update the count of the current element by multiplying the counts of its factors
                    count += rootWithCount[rootEle] * rootWithCount[arr[i] / rootEle];
                }
            }
            // Add the current element and its count to the map
            rootWithCount[arr[i]] = count;
        }
        // Initialize a variable to store the total number of trees
        int noOfTrees = 0;
        // Loop through all the elements and their counts in the map and add their counts to get the total number of trees
        for(auto i : rootWithCount){
            noOfTrees = (noOfTrees + i.second) % mod;
        }
        // Return the total number of trees modulo mod
        return noOfTrees;
    }
};


/* 
Explanation

    This C++ code defines a class Solution with a single public function numFactoredBinaryTrees that takes an input vector arr of integers. The function calculates and 
    returns the total number of unique binary trees that can be formed using elements from arr as their values.

    The function first sorts arr in ascending order using sort. It then initializes an unordered map rootWithCount to store each unique element in arr as a key and its count 
    as a value. The count of the first element in arr is initialized to 1.

    The function then loops through each remaining element in arr. For each element, it initializes a count variable to 1. It then loops through each key-value pair in 
    rootWithCount. For each pair, it checks if the current element is divisible by the key and if its quotient is present in rootWithCount. If both conditions are met, it 
    updates the count variable by multiplying together the counts associated with each factor. Finally, it adds an entry to rootWithCount for the current element with its 
    updated count.

    After all elements have been processed, the function initializes a variable noOfTrees to 0. It then loops through each key-value pair in rootWithCount, adding each value 
    to noOfTrees. The final value of noOfTrees is returned modulo mod.

Complexity Analysis

    The time complexity of this function is O(n^2), where n is the length of arr. This is because for each element in arr, we loop through all previous elements in arr, 
    resulting in O(n^2) iterations.

    The space complexity of the numFactoredBinaryTrees function is O(n), where n is the length of the input vector arr. This is because we store an unordered map with up to 
    n keys and values, which requires O(n) space.
 */