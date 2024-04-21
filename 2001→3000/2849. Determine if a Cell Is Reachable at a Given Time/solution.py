# This function takes five parameters: sx, sy, fx, fy, and t
# sx and sy are the coordinates of the starting point
# fx and fy are the coordinates of the final point
# t is the time limit
# The function returns True if the final point is reachable from the starting point within the time limit, and False otherwise
class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        # Calculate the x and y distances between the starting and final points
        x_distance = abs(sx - fx)
        y_distance = abs(sy - fy)
        # Calculate the minimum distance required to reach the final point
        # This is the sum of the smaller distance and the difference between the larger and smaller distances
        # For example, if sx = 1, sy = 2, fx = 4, fy = 5, then x_distance = 3, y_distance = 3, and min_dist = 3 + 0 = 3
        # If sx = 1, sy = 2, fx = 4, fy = 6, then x_distance = 3, y_distance = 4, and min_dist = 3 + 1 = 4
        min_dist = min(x_distance, y_distance) + abs(y_distance - x_distance)
        # If the minimum distance is zero, then the starting and final points are the same
        if min_dist == 0:
            # If the time limit is one, then the final point is not reachable, because we need to move at least once
            if t == 1:
                return False
            # Otherwise, the final point is reachable, because we can stay at the same point
            else:
                return True
        # If the minimum distance is not zero, then the final point is reachable if and only if the time limit is greater than or equal to the minimum distance
        return t >= min_dist

# Time complexity analysis:
# The function performs constant operations on the input parameters, such as arithmetic operations and comparisons
# Therefore, the time complexity is O(1), meaning that the function takes constant time regardless of the input size

# Space complexity analysis:
# The function uses constant extra space to store the variables x_distance, y_distance, and min_dist
# Therefore, the space complexity is also O(1), meaning that the function takes constant space regardless of the input size
