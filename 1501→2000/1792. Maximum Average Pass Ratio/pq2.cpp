class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Priority queue to track the improvement potential of each class
        priority_queue<pair<double, int>> pq;

        double ans = 0;
        
        // Calculate the initial ratio for each class
        for (int i = 0; i < classes.size(); i++) {
            ans += 1.0 * classes[i][0] / classes[i][1];

            // If there's room for improvement, calculate the potential gain
            if (classes[i][0] != classes[i][1]) {
                double temp = 1.0 * (classes[i][1] - classes[i][0]) / classes[i][1] / (classes[i][1] + 1);
                pq.push({temp, classes[i][1]});
            }
        }

        // Allocate extra students to maximize the average ratio
        while (extraStudents > 0 && !pq.empty()) {
            pair<double, int> top = pq.top();
            pq.pop();

            // Add the improvement of the current class and re-calculate its potential
            ans += top.first;
            pq.push({ top.first * top.second / (top.second + 2), 1 + top.second });

            extraStudents--;
        }

        // Return the average ratio after all extra students are allocated
        return ans / classes.size();
    }
};
