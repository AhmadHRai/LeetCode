class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda function to calculate the gain of adding one extra student
        auto calculateGain = [](double pass, double total) {
            return (pass + 1) / (total + 1) - pass / total;
        };

        // Max-heap to store the class data along with the calculated gain
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        double totalPassRatio = 0.0;

        // Initialize the heap with the initial pass ratios and calculate the sum
        for (const auto& classData : classes) {
            int passingStudents = classData[0];
            int totalStudents = classData[1];
            
            // Add the initial pass ratio to the sum
            totalPassRatio += static_cast<double>(passingStudents) / totalStudents;
            
            // Push the gain of adding an extra student to the heap
            maxHeap.push({calculateGain(passingStudents, totalStudents), {passingStudents, totalStudents}});
        }

        // Distribute the extra students to the classes with the highest gain
        for (int i = 0; i < extraStudents; ++i) {
            // Get the class with the highest gain from the heap
            auto [currentGain, classData] = maxHeap.top();
            maxHeap.pop();

            int passingStudents = classData.first;
            int totalStudents = classData.second;

            // Update the total pass ratio by removing the old pass ratio and adding the new one
            totalPassRatio -= static_cast<double>(passingStudents) / totalStudents;
            passingStudents += 1;
            totalStudents += 1;
            totalPassRatio += static_cast<double>(passingStudents) / totalStudents;

            // Recalculate the gain and push the updated class data back into the heap
            maxHeap.push({calculateGain(passingStudents, totalStudents), {passingStudents, totalStudents}});
        }

        // Return the average pass ratio across all classes
        return totalPassRatio / classes.size();
    }
};

/* 
Time Complexity:

    Time Complexity: O(m log m + k log m), where:
        m is the number of classes (classes.size()).
        k is the number of extra students (extraStudents).
        The initial heap construction takes O(m log m).
        For each of the k extra students, a heap pop and push operation takes O(log m), resulting in O(k log m) for all extra students.

    Therefore, the total time complexity is O(m log m + k log m).

    Space Complexity: O(m), as the solution stores class data in the max-heap.
 */