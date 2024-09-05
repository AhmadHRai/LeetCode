class Solution {
public:
    // Function to find the missing rolls such that their mean is equal to `mean`
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int m = rolls.size(); // Number of known rolls
        const int sum_rolles = accumulate(rolls.begin(), rolls.end(), 0); // Sum of known rolls
        const int total = (n + m) * mean; // Total sum required to achieve the mean
        const int miss = total - sum_rolles; // Total sum needed from missing rolls

        // Check if it's possible to have `n` missing rolls with values between 1 and 6
        if (miss > 6 * n || miss < n) return {};

        // Calculate base value and remainder for the missing rolls
        auto [q, r] = div(miss, n);
        vector<int> ans(n, q); // Initialize missing rolls with base value `q`

        // Distribute the remainder among the first `r` rolls
        fill(ans.begin(), ans.begin() + r, q + 1);

        return ans; // Return the list of missing rolls
    }
};

/*
Approach Summary:
- Calculate the total sum required to achieve the given mean when including both known and missing rolls.
- Compute the sum that needs to be achieved by the missing rolls.
- Check if it's feasible to distribute this sum among the missing rolls given the constraints (each roll between 1 and 6).
- Distribute the sum such that the mean is achieved and return the list of missing rolls.

Time Complexity:
- O(n), where n is the number of missing rolls. The function performs operations that are linear with respect to the number of missing rolls.

Space Complexity:
- O(n), where n is the number of missing rolls. Space is used to store the resulting vector of missing rolls.
*/
