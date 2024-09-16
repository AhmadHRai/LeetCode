class Solution {
public:
    // Method to find the minimum time difference between time points
    int findMinDifference(vector<string>& timePoints) {
        // Vector to store the time points converted to total minutes
        vector<int> minutes;
        
        // Convert time points to total minutes from midnight
        for (const string &time : timePoints) {
            // Extract hours and minutes from the time string
            int hours = stoi(time.substr(0, 2)); // Get the hours part
            int mins = stoi(time.substr(3, 2)); // Get the minutes part
            // Calculate total minutes and store in the minutes vector
            minutes.push_back(hours * 60 + mins);
        }
        
        // Sort the minutes vector to facilitate finding the minimum difference
        sort(minutes.begin(), minutes.end());
        
        // Initialize the minimum difference to a large value
        int minDiff = INT_MAX;
        int n = minutes.size(); // Get the number of time points
        
        // Calculate differences between consecutive sorted time points
        for (int i = 1; i < n; ++i) {
            // Update minDiff with the minimum of the current difference
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Consider the circular difference between the last and the first time point
        minDiff = min(minDiff, (1440 - minutes.back() + minutes.front()));
        
        // Return the minimum time difference found
        return minDiff;
    }
};

/*
Approach:
1. Convert each time point from "HH:MM" format to the total number of minutes from midnight.
   This makes it easier to calculate the differences between time points.
2. Sort the list of minute values, which allows for easy calculation of the minimum difference 
   by checking only consecutive elements.
3. Iterate through the sorted list to find the minimum difference between consecutive time points.
4. Also, compute the wrap-around difference between the last and the first time point to account for 
   the circular nature of a day.
5. Return the smallest of the calculated differences.

Time Complexity:
- O(n log n) due to the sorting step, where `n` is the number of time points. The subsequent linear scan for differences takes O(n) time.

Space Complexity:
- O(n) for storing the converted minute values. However, this can be considered constant space if we only account for the input size and the result since the number of minutes is limited (1440).
*/


/*
To find the minimum time difference between any two time points in a list, you can use the following approach. This solution relies on converting the time points into minutes, sorting them, and then finding the minimum difference between consecutive times. Here’s a step-by-step explanation and implementation:

    Convert Time to Minutes: Convert each time point from "HH
    " format to the total number of minutes from midnight. This helps in simplifying the comparison of times.

    Sort the Minutes: Once all time points are converted to minutes, sort these minute values. This allows us to easily find the minimum difference by only checking consecutive elements in the sorted list.

    Calculate Differences: The minimum difference between times will be among the differences between consecutive times in the sorted list. Also, consider the wrap-around difference (from the last time point of the day to the first one of the day).

    Return Minimum Difference: Calculate and return the smallest of these differences.

Explanation:

    Conversion to Minutes:
        For each time point, hours * 60 + mins converts "HH
        " to total minutes from midnight.

    Sorting:
        Sorting the minute values helps to find differences easily.

    Finding Minimum Difference:
        After sorting, the smallest difference between consecutive minute values is calculated.
        The wrap-around case is handled by computing the difference between the last and first time points of the day.

    Time Complexity:
        Sorting takes O(nlog⁡n) time, and finding differences in a single pass takes O(n) time, where nn is the number of time points.

Understanding the Circular Difference

    Time Representation:
        Let's say the times are represented in minutes from midnight as 0 to 1439 (since there are 1440 minutes in a day).

    Sorting:
        After sorting the time points converted to minutes, the sorted list will have times in ascending order. For example, after sorting, you might have a list like [10, 100, 150, 1300, 1435].

    Finding the Minimum Difference:
        You compute the differences between consecutive sorted times, like 100 - 10, 150 - 100, and so on.

    Circular Wrap-Around:
        The circular difference comes into play between the last time point of the day and the first time point of the day. Essentially, you need to account for the difference that wraps around the end of the day back to the beginning.

Detailed Breakdown:

    Calculate the Wrap-Around Difference:
        Last Time Point: This is the last element in the sorted list. Let's denote this as minutes.back().
        First Time Point: This is the first element in the sorted list. Let's denote this as minutes.front().

    The circular difference is calculated as:
    wrap-around difference=(1440−minutes.back()+minutes.front())

    Here’s why:
        1440 is the total number of minutes in a day.
        Subtracting minutes.back() from 1440 gives the number of minutes remaining in the day after the last time point.
        Adding minutes.front() to this gives the total minutes from the end of the day to the start of the next day.

    For example:
        If minutes.back() = 1435 (which represents "23:55")
        If minutes.front() = 10 (which represents "00:10")
        Then the circular difference would be:
        wrap-around difference=(1440−1435+10)=15

    This represents the time span from "23:55" to "00:10".

    Compare and Choose the Minimum:
        Finally, you compare this circular difference with the minimum difference found among the consecutive times and return the smallest value.

Example with Full Steps:

Assume you have the times ["23:59", "00:00", "12:30"]:

    Convert to minutes:
        "23:59" → 1439 minutes
        "00:00" → 0 minutes
        "12:30" → 750 minutes

    Sorted minutes list:
        [0, 750, 1439]

    Compute consecutive differences:
        750 - 0 = 750 minutes
        1439 - 750 = 689 minutes

    Compute the circular difference:
        (1440 - 1439 + 0) = 1 minute

    Minimum difference:
        The minimum difference among the computed values is 1 minute.

So, the final result is 1, which is the smallest difference accounting for both linear and circular cases.
*/