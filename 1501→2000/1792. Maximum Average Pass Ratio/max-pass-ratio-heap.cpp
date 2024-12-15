class Solution {
public:
    // Function to calculate the gain in pass ratio by adding one student
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        // Lambda function to calculate the gain by adding one extra student
        auto calculateGain = [](double passingStudents, double totalStudents) {
            return (passingStudents + 1) / (totalStudents + 1) - passingStudents / totalStudents;
        };

        // Max-heap (priority queue) to store the class data with gain as the priority
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        double totalPassRatio = 0.0;  // To store the cumulative pass ratio

        // Loop through each class and calculate the initial pass ratio
        for (const auto& classData : classes) {
            int passingStudents = classData[0];  // Number of passing students in the class
            int totalStudents = classData[1];   // Total number of students in the class
            
            // Add the initial pass ratio to the total
            totalPassRatio += static_cast<double>(passingStudents) / totalStudents;  
            
            // Calculate the gain if one extra student is added and push to the heap
            maxHeap.push({calculateGain(passingStudents, totalStudents), {passingStudents, totalStudents}});
        }

        // Distribute the extra students to maximize the overall pass ratio
        for (int i = 0; i < extraStudents; ++i) {
            // Get the class with the highest gain
            auto [currentGain, classData] = maxHeap.top();
            maxHeap.pop();  // Pop the class with the highest gain
            
            int passingStudents = classData.first;  // Number of passing students
            int totalStudents = classData.second;   // Total number of students

            // Update the total pass ratio by removing the old pass ratio and adding the new one
            totalPassRatio -= static_cast<double>(passingStudents) / totalStudents;
            passingStudents += 1;  // Add one student to the class
            totalStudents += 1;    // Increase the total number of students

            // Add the new pass ratio after adding one student
            totalPassRatio += static_cast<double>(passingStudents) / totalStudents;

            // Recalculate the gain with the updated number of students and push it back to the heap
            maxHeap.push({calculateGain(passingStudents, totalStudents), {passingStudents, totalStudents}});
        }

        // Return the average pass ratio after distributing the extra students
        return totalPassRatio / classes.size();
    }
};

/* 
Time Complexity:

    Heap construction: O(n log n) where n is the number of classes.
    Distributing extra students: For each of the k extra students, the heap pop and push operations take O(log n) time, so the complexity for this part is O(k log n).
    Final pass ratio computation: O(n), iterating over all classes once.

Thus, the total time complexity is O(n log n + k log n), where n is the number of classes and k is the number of extra students.

Space Complexity:

    The space complexity is O(n) because we store all class data in the max-heap.
*/