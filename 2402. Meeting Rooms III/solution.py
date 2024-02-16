""" 
Approach

    Initialization:
        We initialize two vectors: ans to keep track of the number of meetings each person attends, and times to keep track of the end time of each person's last meeting.
        Both vectors are initialized with zeros.

    Sorting Meetings:
        We sort the meetings based on their start times. This helps us process them in chronological order.

    Processing Meetings:
        For each meeting, we find the person who has the earliest available time slot to attend the meeting.
        If there's a person available (i.e., their last meeting ends before the current meeting starts), we assign them to attend the meeting and update their end time.
        If no person is available, we find the person who has the earliest end time among all persons and assign them to attend the meeting. We also update their end time accordingly.

    Finding Most Booked:
        After processing all meetings, we find the person who attended the maximum number of meetings.
        We iterate through the ans vector and find the person with the highest count of attended meetings.

    Return Result:
        We return the ID of the person who attended the most meetings.

 """

 class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        # Create a list of size n, initialized with 0, to store the number of bookings for each room
        ans = [0] * n
        # Create a list of size n, initialized with 0, to store the end time of the last meeting for each room
        times = [0] * n
        # Sort the meetings by their start time in ascending order
        meetings.sort()

        # Loop over the meetings
        for start, end in meetings:
            # Initialize a boolean variable to indicate if a room is available for the current meeting
            flag = False
            # Initialize an integer variable to store the index of the room with the minimum end time
            minind = -1
            # Initialize an integer variable to store the minimum end time
            val = float('inf')
            # Loop over the rooms
            for j in range(n):
                # If the end time of the current room is less than the minimum end time, update the minimum end time and the index
                if times[j] < val:
                    val = times[j]
                    minind = j
                # If the end time of the current room is less than or equal to the start time of the current meeting, it means the room is available
                if times[j] <= start:
                    # Set the flag to true, indicating that a room is found
                    flag = True
                    # Increment the number of bookings for the current room
                    ans[j] += 1
                    # Update the end time of the current room with the end time of the current meeting
                    times[j] = end
                    # Break the loop, as we do not need to check the other rooms
                    break
            # If no room is available for the current meeting, we need to assign the meeting to the room with the minimum end time
            if not flag:
                # Increment the number of bookings for the room with the minimum end time
                ans[minind] += 1
                # Add the duration of the current meeting to the end time of the room with the minimum end time
                times[minind] += (end - start)

        # Initialize an integer variable to store the maximum number of bookings
        maxi = -1
        # Initialize an integer variable to store the index of the most booked room
        id = -1
        # Loop over the rooms
        for i in range(n):
            # If the number of bookings for the current room is greater than the maximum number of bookings, update the maximum number of bookings and the index
            if ans[i] > maxi:
                maxi = ans[i]
                id = i
        # Return the index of the most booked room
        return id

""" 
Complexity
    Time complexity:
    O(n . log n)

    Space complexity:
    O(n)
 """