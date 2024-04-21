# Define a class named Solution with a method named isPathCrossing
class Solution(object):
    # The method takes a string of directions as input and returns a boolean as output
    def isPathCrossing(self, path):
        # Define a dictionary that maps each direction to a tuple of coordinate changes
        moves = {
            "N": (0, 1), # North means adding 1 to the y-coordinate
            "S": (0, -1), # South means subtracting 1 from the y-coordinate
            "W": (-1, 0), # West means subtracting 1 from the x-coordinate
            "E": (1, 0) # East means adding 1 to the x-coordinate
        }
        
        # Define a set to store the visited coordinates
        visited = {(0, 0)}
        # Initialize the current x-coordinate and y-coordinate to zero
        x = 0
        y = 0

        # Loop through each character in the path string
        for c in path:
            # Get the corresponding coordinate change for the current direction
            dx, dy = moves[c]
            # Update the current x-coordinate and y-coordinate by adding the changes
            x += dx
            y += dy
            
            # Check if the current coordinates have been visited before
            if (x, y) in visited:
                # If yes, return True to indicate that the path is crossing
                return True

            # Otherwise, add the current coordinates to the visited set
            visited.add((x, y))
        
        # If the loop ends without returning True, return False to indicate that the path is not crossing
        return False
