#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Create a copy of the original array to work with
        vector<int> A(arr);
        
        // Sort the copy of the array to determine ranks
        sort(A.begin(), A.end());
        
        // Map to store the rank of each unique element
        unordered_map<int, int> rank;
        
        // Assign ranks to the unique elements
        for (int& a : A) {
            // Only assign rank if it hasn't been assigned already
            if (rank.find(a) == rank.end()) {
                rank.emplace(a, rank.size() + 1); // Rank starts from 1
            }
        }
        
        // Transform the original array based on the assigned ranks
        for (int i = 0; i < A.size(); ++i) {
            A[i] = rank[arr[i]]; // Replace with the corresponding rank
        }
        
        return A; // Return the transformed array
    }
};

/*
  Approach:
  The objective is to replace each element in the array with its rank.
  The rank is defined as the 1-based index of the element in the sorted 
  array of unique elements.
  
  Steps:
  1. Create a copy of the original array to sort and determine unique elements.
  2. Sort the copied array. This allows us to easily identify unique elements and their ranks.
  3. Use an unordered map to store the rank of each unique element. 
     As we iterate through the sorted array, we assign a rank (1-based index) 
     only when we encounter a unique element.
  4. Replace each element in the original array with its corresponding rank 
     using the map.
  5. Return the modified array containing ranks.
  
  Complexity Analysis:
  - Time Complexity: O(N log N), where N is the number of elements in the array.
    This is due to the sorting step. The subsequent operations to assign ranks and 
    transform the array take linear time, O(N).
  - Space Complexity: O(N), for the storage of the map containing unique elements and ranks.
 */
