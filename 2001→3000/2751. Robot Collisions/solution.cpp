class Solution {
public:

    // Define a structure to represent a robot with position, health, direction, and original index
    struct Robot {
        int position;
        int health;
        char direction;
        int index;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string& directions) {
        int n = positions.size();
        vector<Robot> vals;

        // Create a vector of Robot objects and initialize with given positions, healths, and directions
        for (int i = 0; i < n; i++) {
            vals.push_back({positions[i], healths[i], directions[i], i});
        }

        // Sort robots based on their positions
        sort(vals.begin(), vals.end(), [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });

        vector<Robot> stack;

        // Process each robot in the sorted order
        for (auto& robot : vals) {
            if (robot.direction == 'R') {
                // Push robots moving to the right onto the stack
                stack.push_back(robot);
                continue;
            }

            // Flag to check if the current robot has been eliminated
            bool gone = false;

            // Process the stack to check for robot elimination
            while (!stack.empty() && stack.back().health <= robot.health && stack.back().direction == 'R') {
                if (stack.back().health == robot.health) {
                    // If healths are equal, both robots are eliminated
                    stack.pop_back();
                    gone = true;
                    break;
                }
                // Decrease health of the incoming robot and remove the robot from the stack
                robot.health--;
                stack.pop_back();
            }

            // If robot is not eliminated and there are robots facing right with higher health
            if (!gone && !stack.empty() && stack.back().direction == 'R' && stack.back().health > robot.health) {
                // Decrease health of the right-facing robot
                stack.back().health--;
                gone = true;
            }

            // If the robot is not eliminated, push it onto the stack
            if (!gone) {
                stack.push_back(robot);
            }
        }

        // Sort the surviving robots by their original index to maintain the input order
        sort(stack.begin(), stack.end(), [](const Robot& a, const Robot& b) {
            return a.index < b.index;
        });

        // Extract the healths of the surviving robots for the result
        vector<int> result;
        for (const auto& robot : stack) {
            result.push_back(robot.health);
        }

        // Return the list of surviving robots' healths
        return result;
    }
};

/* 
Approach

    The solution simulates a scenario where robots move and potentially collide based on their directions and healths.
    - Initialize a vector of `Robot` objects with their positions, healths, directions, and original indices.
    - Sort the robots based on their positions to process them in the order they appear.
    - Use a stack to handle robots moving to the right and determine which robots survive after potential collisions with robots moving to the left.
    - After processing all robots, sort the surviving robots based on their original indices to maintain the input order.
    - Extract and return the healths of the surviving robots.

Complexity

    Time complexity: O(n log n), where n is the number of robots. This is due to the sorting operations (twice) and linear processing of the robots.
    
    Space complexity: O(n), due to the space required for the `stack` and `vals` vectors.
 */
