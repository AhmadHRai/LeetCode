class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a map to associate heights with names.
        unordered_map<int, string> map;
        for (int i = 0; i < names.size(); i++)
            map[heights[i]] = names[i];

        // Sort heights in descending order.
        sort(heights.begin(), heights.end(), greater<int>());

        // Create the result vector by mapping sorted heights to names.
        for (int i = 0; i < names.size(); i++)
            names[i] = map[heights[i]];

        return names;
    }
};

/*
Approach

    1. **Map Creation**: Create an unordered map where keys are heights and values are names. This allows for quick look-up of names based on heights.
    2. **Sorting**: Sort the `heights` vector in descending order. This determines the order in which names will be assigned in the final result.
    3. **Result Construction**: Iterate through the sorted heights and use the map to assign names to the result vector based on the sorted order of heights.

Complexity

    Time complexity: O(n log n), where n is the number of people. The most time-consuming operation is sorting the heights, which takes O(n log n) time.

    Space complexity: O(n), due to the storage required for the unordered map and the result vector.

The solution efficiently sorts people based on their heights using a combination of a hash map and sorting.
*/
