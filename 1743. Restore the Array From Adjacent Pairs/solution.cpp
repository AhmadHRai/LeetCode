// This class defines a solution to the problem of restoring the array from adjacent pairs
// The problem statement is: There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums. You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums. It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order. Return the original array nums. If there are multiple solutions, return any of them.
class Solution {
public:
    // This function takes a vector of vectors of integers representing the adjacent pairs
    // It returns a vector of integers representing the original array
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // This unordered map stores the mapping from each element to its adjacent elements
        unordered_map<int, vector<int>> ps;
        // This loop iterates over the adjacent pairs vector and fills the map
        for (auto &p : adjacentPairs) {
            // This adds the second element of the pair to the first element's vector
            ps[p[0]].push_back(p[1]);
            // This adds the first element of the pair to the second element's vector
            ps[p[1]].push_back(p[0]);
        }
        // This vector stores the result array
        vector<int> res;
        // This loop iterates over the map
        for (auto &p : ps) {
            // This checks if the element has only one adjacent element
            if (p.second.size() == 1) {
                // If yes, then it must be the first or the last element of the array
                // This adds the element and its adjacent element to the result vector
                res.push_back(p.first);
                res.push_back(p.second[0]);
                // This breaks the loop as we have found the starting point
                break;
            }
        }
        // This loop continues until the result vector has the same size as the original array
        while (res.size() < adjacentPairs.size() + 1) {
            // This gets the last element and the second last element of the result vector
            auto tail = res.back(), prev = res[res.size() - 2];
            // This gets the vector of the adjacent elements of the last element from the map
            auto &next = ps[tail];
            // This checks if the first element of the vector is not the same as the second last element of the result vector
            if (next[0] != prev)
                // If yes, then it must be the next element of the array
                // This adds it to the result vector
                res.push_back(next[0]);
            else
                // If no, then the second element of the vector must be the next element of the array
                // This adds it to the result vector
                res.push_back(next[1]);
        }
        // This returns the result vector
        return res;
    }
};

/* 
The time complexity of this function is O(n), where n is the number of elements in the original array. This is because the function loops through the adjacent pairs vector once and 
performs constant time operations in each iteration, which is O(n-1). The function also loops through the map once and performs constant time operations in each iteration, which is 
O(n). The function also loops through the result vector once and performs constant time operations in each iteration, which is O(n). The total time complexity is O(n-1) + O(n) + O
(n) = O(n).

The space complexity of this function is O(n), where n is the number of elements in the original array. This is because the function uses an unordered map to store the adjacent 
elements, which takes O(n) space. The function also uses a vector to store the result array, which takes O(n) space. The total space complexity is O(n) + O(n) = O(n).
 */