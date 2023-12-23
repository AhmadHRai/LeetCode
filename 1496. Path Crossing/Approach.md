# Intuition

The problem asks us to determine if a path crosses itself at any point. We need to keep track of the visited locations during the traversal of the path and check if we revisit any location.

# Approach

1.  Create a map `moves` to map the characters 'N', 'S', 'E', 'W' to their respective coordinate changes.
2.  Initialize a set `visited` to store the visited locations. Add the starting location (0, 0) to the set.
3.  Traverse the path character by character:
    - Update the current position based on the move.
    - Create a pair of the current position.
    - Check if the pair is already in the `visited` set. If yes, return `true` as the path crosses itself.
    - Otherwise, add the pair to the `visited` set.
4.  If the traversal completes without finding any crossing, return `false`.

# Complexity

- Time complexity: O(n) - We iterate through the path once.

- Space complexity: O(n) - We use a set to store visited locations. In the worst case, all locations are unique.
