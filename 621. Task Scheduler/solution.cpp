class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Initialize a vector to keep count of each task
        vector<int> taskCount(26, 0);
        int maxCount = 0; // Variable to keep track of the maximum count of a single task

        // Count the tasks and find out the task with the maximum count
        for (char task : tasks) {
            task -= 'A'; // Convert char to an index between 0 and 25
            ++taskCount[task]; // Increment the count for this task
            maxCount = max(maxCount, taskCount[task]); // Update maxCount if current task's count is greater
        }

        // Count how many tasks have the same count as maxCount
        int tasksWithMaxCount = 0;
        for (int count : taskCount) {
            if (count == maxCount) {
                ++tasksWithMaxCount;
            }
        }

        // Calculate the least interval
        // First part: Calculate the minimum slots required based on the most frequent task (maxCount - 1) times (coolingPeriod + 1)
        // Second part: Add the number of tasks that have the highest frequency (taskWithMaxCount)
        int minSlotsRequired = (maxCount - 1) * (n + 1) + tasksWithMaxCount;

        // The result is the maximum between the actual size of tasks and the minimum slots required
        return max(static_cast<int>(tasks.size()), minSlotsRequired);
    }
};

/* 
Approach:

    First, we count the frequency of each task by converting each character to its corresponding index in the taskCount vector.
    We then find the task with the maximum frequency and count how many tasks have the same frequency as the maximum.
    To calculate the minimum number of intervals required, we consider the most frequent task and its cooling period. The minimum slots 
        required is calculated by multiplying the maximum frequency minus one by the cooling period plus one, and then adding the number of 
        tasks with the maximum frequency.
    Finally, we return the maximum of the actual number of tasks and the minimum slots required, as the CPU must complete all tasks while 
        adhering to the cooling time constraint.

Complexity Analysis:

    Time Complexity: O(T), where T is the total number of tasks, as we iterate over each task once to count their frequencies.
    Space Complexity: O(U), where U is the number of unique tasks, as we use a vector to store the frequency of each task.

 */