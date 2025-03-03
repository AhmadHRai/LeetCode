class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        list<int> less;
        list<int> p;
        list<int> greater;

        // Separate elements into less, equal, and greater lists
        for (auto num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num > pivot) {
                greater.push_back(num);
            } else { // equals
                p.push_back(num);
            }
        }

        // Combine less, p, and greater lists into a vector
        vector<int> result;

        // Add less elements to result
        result.insert(result.end(), less.begin(), less.end());

        // Add p (pivot) elements to result
        result.insert(result.end(), p.begin(), p.end());

        // Add greater elements to result
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};