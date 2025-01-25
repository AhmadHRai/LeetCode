#include <ranges>

static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  // Returns the lexicographically smallest array by replacing each element with the smallest in its group
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    // Create a sorted copy of the input array
    auto sorted_nums = nums;
    sort(begin(sorted_nums), end(sorted_nums));

    // Use ranges to chunk the sorted array based on the difference limit
    auto chunks = sorted_nums
        | views::chunk_by([limit](auto a, auto b) { return b - a <= limit; });

    // Create a view of iterators to the beginning of each chunk
    auto chunk_its_view =  chunks |
        views::transform([](auto chunk) { return begin(chunk); });
    // Convert the view to a vector for easier manipulation
    auto chunk_its = vector(begin(chunk_its_view), end(chunk_its_view));

    // Create a view of the fronts of each chunk (smallest element in each group)
    auto chunk_fronts = chunks |
        views::transform([](auto chunk) { return chunk.front(); });
    // Convert the view to a vector for lookup
    auto chunk_lookup = vector(begin(chunk_fronts), end(chunk_fronts));

    // Replace each number in the original array with the smallest in its group
    for (auto& num : nums) {
      // Find the appropriate chunk for the current number using binary search
      auto lut_it = prev(ranges::upper_bound(chunk_lookup, num));
      // Get the iterator to the current chunk
      auto& chunk_it = chunk_its[distance(begin(chunk_lookup), lut_it)];
      // Replace the current number with the smallest in its chunk and increment the iterator
      num = *chunk_it++;
    }

    return nums;
  }
}
/*
Approach Summary:
This solution uses C++20 ranges to efficiently group numbers in the sorted array based on a difference limit. It then replaces each number in the original array with the smallest in its group, ensuring the resulting array is lexicographically smallest.

Complexity Analysis:
- Time Complexity: O(N log N), primarily due to sorting the array.
- Space Complexity: O(N), for storing the sorted array and chunk iterators.
*/
