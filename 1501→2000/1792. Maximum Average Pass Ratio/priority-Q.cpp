class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda to calculate the gain of adding an extra student
        auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };

        // Max heap to store (-gain, passes, totalStudents)
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& singleClass : classes) {
            maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                          {singleClass[0], singleClass[1]}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};

/*
Complexity Analysis

Let n be the number of classes in the classes array and k be the number of extra students.

    Time complexity: O(k⋅n)

    The outer loop runs k times (once for each extra student).

    Inside the loop, we have two main operations:
    1. Calculating the updated pass ratios for all classes: This involves iterating over all n classes, resulting in O(n) time.
    2. Finding the class with the maximum gain: This involves another iteration over all n classes, resulting in O(n) time.

    Therefore, the total time complexity is O(k⋅n).

    Space complexity: O(n)

    We use a array passRatios of size n to store the pass ratios of all classes. Additionally, we use a temporary array updatedRatios of size n to store the updated pass ratios. The space complexity is dominated by these two arrays, resulting in O(n) space.

*/