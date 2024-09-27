#include <map>
using namespace std;

class MyCalendarTwo {
    map<int, int> mp; // Map to track the number of overlapping events at each time point

public:
    // Constructor
    MyCalendarTwo() {
        
    }
    
    // Method to book a new event
    bool book(int start, int end) {
        // Increment the count for the start time and decrement for the end time
        mp[start]++;
        mp[end]--;
        
        int booked = 0; // Counter for the number of overlapping events
        
        // Iterate through the map to check the number of overlaps
        for (auto it = mp.begin(); it != mp.end(); it++) {
            booked += it->second; // Update the booked count
            
            // If there are three overlapping events, revert the last booking
            if (booked == 3) {
                mp[start]--; // Decrease the count for the start time
                mp[end]++;   // Increase the count for the end time
                return false; // Booking is not possible
            }
        }
        return true; // Booking was successful
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start, end);
 */

/*
Approach:
1. Use a map to track the number of overlapping bookings at each time point.
2. For each new booking:
   - Increment the count at the start time and decrement at the end time.
   - Check the running total of overlaps while iterating through the map.
3. If the count reaches three (indicating a double booking), revert the changes and return false.

Time Complexity:
- O(N) in the worst case for the number of bookings due to the iteration through the map.

Space Complexity:
- O(N) in the worst case, where N is the number of unique time points stored in the map.
*/
