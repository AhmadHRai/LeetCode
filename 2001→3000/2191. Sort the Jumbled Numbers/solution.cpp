class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Step 1: Create a vector to store original nums and their mapped values
        vector<tuple<int, int, int>> mappedList;
        for (int i = 0; i < nums.size(); i++) {
            // Convert the number to string to apply mapping
            string s = to_string(nums[i]);
            string n = "";
            for (char ch : s) {
                n += to_string(mapping[ch - '0']); // Map each digit to its new value
            }
            mappedList.push_back(make_tuple(nums[i], stoi(n), i)); // Store original number, mapped value, and original index
        }

        // Step 2: Sort the vector based on the mapped values and original indices for stability
        sort(mappedList.begin(), mappedList.end(), [](const auto& a, const auto& b) {
            if (get<1>(a) != get<1>(b)) {
                return get<1>(a) < get<1>(b); // Compare by mapped value
            } else {
                return get<2>(a) < get<2>(b); // Compare by original index if mapped values are the same
            }
        });

        // Step 3: Create a result vector and fill it with the sorted original nums
        vector<int> sortedNums(nums.size());
        for (int i = 0; i < mappedList.size(); i++) {
            sortedNums[i] = get<0>(mappedList[i]); // Extract original number in sorted order
        }

        return sortedNums;
    }
};

/*
Approach

    1. **Mapping and Storage**:
       - Convert each number in `nums` to its mapped value using the provided `mapping`.
       - Store each original number, its mapped value, and its original index in a tuple within `mappedList`.
    2. **Sorting**:
       - Sort `mappedList` based on the mapped value.
       - Use the original index for tie-breaking to maintain the order of numbers with identical mapped values.
    3. **Result Formation**:
       - Extract the original numbers from `mappedList` into the `sortedNums` vector, which will be returned.

Complexity

    Time complexity: O(n * log n), where n is the number of elements in `nums`. This is due to the sorting operation on `mappedList`.

    Space complexity: O(n), due to the additional storage used for `mappedList` and the result vector.

This approach efficiently maps and sorts the numbers based on their new values, preserving the order of numbers with identical mapped values.
*/
