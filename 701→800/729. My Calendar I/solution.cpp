#include <map>
using namespace std;

class MyCalendar {
public:
    map<int, int> books; // Map to store the start time and end time of booked events

    // Constructor
    MyCalendar() {
        
    }
    
    // Method to book a new event
    bool book(int s, int e) {
        // Find the first event that starts at or after the new event's start time
        auto next = books.lower_bound(s);
        
        // Check if the next event starts before the new event ends
        if (next != books.end() && next->first < e) return false; // Overlaps with an existing booking
        
        // Check the previous event (if it exists) to see if the new event starts before it ends
        if (next != books.begin() && s < (--next)->second) return false; // Overlaps with an existing booking

        // Book the new event by adding it to the map
        books[s] = e;
        return true; // Booking was successful
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start, end);
 */

/*
Approach:
1. Use a map to store the start and end times of booked events.
2. For each new booking request:
   - Use `lower_bound` to find the next event that starts at or after the new event's start time.
   - Check for overlaps with the next and previous events.
3. If there is no overlap, add the new event to the map.

Time Complexity:
- O(log N) for each booking due to the use of a map, where N is the number of bookings. Each booking involves finding potential overlaps and inserting into the map.

Space Complexity:
- O(N) in the worst case, where N is the number of booked events, as each booking is stored in the map.
*/
